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

$CC -dM -include linux/input.h "$@" - </dev/null | awk '
    /\<(KEY_(MAX|MIN_INTERESTING))|(BTN_(MISC|MOUSE|JOYSTICK|GAMEPAD|DIGI|WHEEL|TRIGGER_HAPPY))\>/  { next }
    /^#define[ \t]+(KEY|BTN)_[^ ]+[ \t]+[0-9BK]/                                                    { print $2 }
'
