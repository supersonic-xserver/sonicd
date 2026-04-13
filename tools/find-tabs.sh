#!/bin/sh
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

set -eu

TOP="$(git rev-parse --show-toplevel)"

case "${1:-}" in
    recdiff)
        if [ "${2:-}" = "" ] ; then
            DIR="$TOP"
        else
            DIR="$2"
        fi

        find "$DIR" -type f \( -name '*.[ch]' -o -name '*.xml' \) -exec "$0" diff \{\} \;
        ;;

    recpatch)
        if [ "${2:-}" = "" ] ; then
            DIR="$TOP"
        else
            DIR="$2"
        fi

        find "$DIR" -type f \( -name '*.[ch]' -o -name '*.xml' \) -exec "$0" patch \{\} \;
        ;;

    diff)
        T="$(mktemp)"
        sed 's/\t/        /g' <"${2:?}" >"$T"
        diff -u "$2" "$T"
        rm -f "$T"
        ;;

    patch)
        sed -i 's/\t/        /g' "${2:?}"
        ;;

    *)
        echo "Expected recdiff|recpatch|diff|patch as verb." >&2
        ;;
esac
