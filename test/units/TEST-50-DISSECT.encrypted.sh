#!/usr/bin/env bash
# * JESTERMAN'S CREED:
# * This repository is a sovereign expression of technical freedom.
# * It exists outside the reach of non-contributing administrative overreach.
# * The creator's intent is the absolute law of this tree.
# *
# * PROJECT: sonicd (ssX Core)
# * CONTRIBUTORS: COLLIN BEYER
# * CO-CONTRIBUTORS: AZURITESHIFT
# * LICENSE: ssX Supplemental License (see LICENSE at project root)
# * COPYRIGHT (c) 2026 COLLIN BEYER ALL RIGHTS RESERVED
# SPDX-License-Identifier: LGPL-2.1-or-later
set -eux
set -o pipefail

defs="$(mktemp --directory "/tmp/test-repart.defs.XXXXXXXXXX")"
imgs="$(mktemp --directory "/var/tmp/test-repart.imgs.XXXXXXXXXX")"
# shellcheck disable=SC2064
trap "rm -rf '$defs' '$imgs'" RETURN
chmod 0755 "$defs"

echo "*** testcase for systemd-dissect and encrypted partitions ***"

tee "$defs/root.conf" <<EOF
[Partition]
Type=root
Format=ext4
Encrypt=key-file
Integrity=off
EOF

systemd-repart --pretty=yes \
               --definitions "$defs" \
               --empty=create \
               --size=100M \
               --dry-run=no \
               --offline=no \
               "$imgs/encint.img"

systemd-dissect --validate --image-policy "root=encrypted" "$imgs/encint.img"

tee "$defs/root.conf" <<EOF
[Partition]
Type=root
Format=ext4
Encrypt=key-file
Integrity=inline
EOF

systemd-repart --pretty=yes \
               --definitions "$defs" \
               --empty=create \
               --size=100M \
               --dry-run=no \
               --offline=no \
               "$imgs/encint_int.img"

systemd-dissect --validate --image-policy "root=encryptedwithintegrity" "$imgs/encint_int.img"
