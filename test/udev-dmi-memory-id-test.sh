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

set -e

dmi_memory_id="$1"
input="$2"
expected="$3"

output=$(mktemp --tmpdir "test-udev-dmi-memory-id.XXXXXXXXXX")
# shellcheck disable=SC2064
trap "rm '$output'" EXIT INT QUIT PIPE

(
    set -x
    "$dmi_memory_id" -F "$input" >"$output"
    diff -u "$output" "$expected"
)
