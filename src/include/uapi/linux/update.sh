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
set -eu
set -o pipefail

# The directory must be userspace kernel header directory:
# git clone git@github.com:torvalds/linux.git
# make -C linux headers
# ./update.sh linux
SRCDIR=${1?}

for i in *.h */*.h; do
    if [[ "$i" == bpf_insn.h ]]; then
        cp "$SRCDIR/samples/bpf/$i" "$i"
    else
        cp "$SRCDIR/usr/include/linux/$i" "$i"
    fi

    case "$i" in
        auto_dev-ioctl.h)
            # set AUTOFS_DEV_IOCTL_VERSION_MINOR to 0
            sed -r -i '/^#define[[:space:]]+AUTOFS_DEV_IOCTL_VERSION_MINOR/ s/[0-9]+/0/' "$i"
            ;;
        dm-ioctl.h)
            # set DM_VERSION_MINOR to 27
            sed -r -i '/^#define[[:space:]]+DM_VERSION_MINOR/ s/[0-9]+/27/' "$i"
            ;;
        ethtool.h)
            # add casts in ethtool_cmd_speed()
            sed -r -i '/return (ep->speed_hi << 16) | ep->speed;/ s/return .*;/return ((__u32) ep->speed_hi << 16) | (__u32) ep->speed;/' "$i"
            ;;
    esac
done
