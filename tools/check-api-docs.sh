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

sd_good=0
sd_total=0
udev_good=0
udev_total=0

deprecated=(
    -e sd_bus_try_close
    -e sd_bus_process_priority
    -e sd_bus_message_get_priority
    -e sd_bus_message_set_priority
    -e sd_seat_can_multi_session
    -e sd_journal_open_container
)

for symbol in $(nm -g --defined-only "$@" | grep " T " | cut -d" " -f3 | grep -wv "${deprecated[@]}" | sort -u); do
    if test -f "${MESON_BUILD_ROOT:?}/man/$symbol.3"; then
        echo "✓ Symbol $symbol() is documented."
        good=1
    else
        echo -e "  \x1b[1;31mSymbol $symbol() lacks documentation.\x1b[0m"
        good=0
    fi

    case "$symbol" in
        sd_*)
            ((sd_good+=good))
            ((sd_total+=1))
            ;;
        udev_*)
            ((udev_good+=good))
            ((udev_total+=1))
            ;;
        *)
            echo 'unknown symbol prefix'
            exit 1
    esac
done

echo "libsystemd: $sd_good/$sd_total libudev: $udev_good/$udev_total"
