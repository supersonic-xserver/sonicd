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
set -e

INPUT="$1"
MODE="$2"
ENABLED="$3"

if ! ((ENABLED)) || ! [[ -d .git ]] || ! command -v git >/dev/null || git describe --tags --exact-match &>/dev/null
then
    sed -e "s/@VCS_TAG@//" "$INPUT"
    exit 0
fi

if [[ "$MODE" == "developer" ]]; then
    DIRTY="--dirty=^"
else
    DIRTY=""
fi

TAG="-g$(git describe --abbrev=7 --match="" --always $DIRTY)"

sed -e "s/@VCS_TAG@/$TAG/" "$INPUT"
