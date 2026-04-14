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

# shellcheck disable=SC1004
awk '
    BEGIN {
        print "%{\n\
_Pragma(\"GCC diagnostic ignored \\\"-Wimplicit-fallthrough\\\"\")\n\
#if __GNUC__ >= 15\n\
_Pragma(\"GCC diagnostic ignored \\\"-Wzero-as-null-pointer-constant\\\"\")\n\
#endif\n\
#include <linux/input.h>\n\
%}"
        print "struct key_name { const char* name; unsigned short id; };"
        print "%null-strings"
        print "%%"
    }

    /^KEY_/ { print tolower(substr($1 ,5)) ", " $1 }
    { print tolower($1) ", " $1 }
' <"${1:?}"
