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
set -eu
set -o pipefail

CC=${1:?}
shift

$CC -E -dM -include linux/stat.h "$@" - </dev/null | \
       grep -Ev '^#define[[:space:]]+(STATX_BASIC_STATS|STATX_ALL|STATX_ATTR_)' | \
       awk '/^#define[ \t]+STATX_[A-Z][A-Z_]*[ \t]+/ { print $2; }'
