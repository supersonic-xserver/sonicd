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
#!/usr/bin/env bash
# SPDX-License-Identifier: LGPL-2.1-or-later
# Test specifiers
set -eux

rm -rf /tmp/specifiers

root='/tmp/specifiers/root'
mkdir -p $root/etc
cat >$root/etc/os-release <<EOF
ID=the-id
BUILD_ID=build-id
VARIANT_ID=variant-id
VERSION_ID=version-id
IMAGE_ID=image-id
IMAGE_VERSION=22
EOF

systemd-tmpfiles --create - --root=$root <<EOF
f  /os-release2 - - - - ID=%o\n
w+ /os-release2 - - - - BUILD_ID=%B\n
w+ /os-release2 - - - - VARIANT_ID=%W\n
w+ /os-release2 - - - - VERSION_ID=%w\n
w+ /os-release2 - - - - IMAGE_ID=%M\n
w+ /os-release2 - - - - IMAGE_VERSION=%A\n
EOF

diff $root/etc/os-release $root/os-release2
