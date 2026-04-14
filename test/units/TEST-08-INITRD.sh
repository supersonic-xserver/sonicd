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

if systemd-detect-virt -qc; then
    echo >&2 "This test can't run in a container"
    exit 1
fi

# This test requires systemd to run in the initrd as well, which is not the case
# for mkinitrd-based initrd (Ubuntu/Debian)
if [[ "$(systemctl show -P InitRDTimestampMonotonic)" -eq 0 ]]; then
    echo "systemd didn't run in the initrd, skipping the test"
    touch /skipped
    exit 77
fi

# We should've created a mount under /run in initrd (see the other half of the test)
# that should've survived the transition from initrd to the real system
test -d /run/initrd-mount-target
mountpoint /run/initrd-mount-target
[[ -e /run/initrd-mount-target/hello-world ]]

# Copy the prepared exitrd to its intended location.
mkdir -p /run/initramfs
unzstd --stdout /exitrd | cpio --extract --make-directories --directory /run/initramfs/

touch /testok
