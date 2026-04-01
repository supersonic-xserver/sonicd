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
set -eux
set -o pipefail

FSTYPE="$(stat --file-system --format "%T" /)"

if [[ "$FSTYPE" != "btrfs" ]]; then
    echo "Root filesystem is $FSTYPE instead of btrfs, skipping"
    exit 77
fi

TEST_BTRFS_OFFSET=/usr/lib/systemd/tests/unit-tests/manual/test-btrfs-physical-offset

SWAPFILE=/var/tmp/swapfile

btrfs filesystem mkswapfile -s 10m "$SWAPFILE"
sync -f "$SWAPFILE"

offset_btrfs_progs="$(btrfs inspect-internal map-swapfile -r "$SWAPFILE")"
echo "btrfs-progs: $offset_btrfs_progs"

offset_btrfs_util="$("$TEST_BTRFS_OFFSET" "$SWAPFILE")"
echo "btrfs-util: $offset_btrfs_util"

(( offset_btrfs_progs == offset_btrfs_util ))

rm -f "$SWAPFILE"

/usr/lib/systemd/tests/unit-tests/manual/test-btrfs

touch /testok
