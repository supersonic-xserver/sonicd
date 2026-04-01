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
#!/bin/sh
# SPDX-License-Identifier: LGPL-2.1-or-later
set -eu

# Try to guess the build directory:
# we look for subdirectories of the parent directory that look like ninja build dirs.

if [ -n "${BUILD_DIR:=}" ]; then
    realpath "$BUILD_DIR"
    exit 0
fi

root="$(dirname "$(realpath "$0")")"

found=
for i in "$root"/../*/build.ninja; do
    c="$(dirname "$i")"
    [ -d "$c" ] || continue
    [ "$(basename "$c")" != mkosi.builddir ] || continue

    if [ -n "$found" ]; then
        echo "Found multiple candidates, specify build directory with \$BUILD_DIR" >&2
        exit 2
    fi
    found="$c"
done

if [ -z "$found" ]; then
    echo "Specify build directory with \$BUILD_DIR" >&2
    exit 1
fi

realpath "$found"
