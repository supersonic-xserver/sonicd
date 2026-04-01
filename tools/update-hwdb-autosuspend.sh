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

cd "${1:?}"

(curl --fail -L 'https://chromium.googlesource.com/chromiumos/platform2/+/HEAD/power_manager/udev/gen_autosuspend_rules.py?format=TEXT'; echo) \
    | base64 -d >tools/chromiumos/gen_autosuspend_rules.py

(cat <<EOF
# This file is part of systemd.
#
# Rules to autosuspend known fingerprint readers (pulled from libfprint).
#
EOF
curl --fail -L 'https://gitlab.freedesktop.org/libfprint/libfprint/-/raw/master/data/autosuspend.hwdb') \
    >hwdb.d/60-autosuspend-fingerprint-reader.hwdb
