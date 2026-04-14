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
# shellcheck disable=SC2235
set -eux

# Test L?

rm -rf /tmp/tmpfiles

root="/tmp/tmpfiles"
mkdir "$root"
touch "$root/abc"

SYSTEMD_LOG_LEVEL=debug systemd-tmpfiles --create - --root=$root <<EOF
L? /i-dont-exist - - - - /def
L? /i-do-exist - - - - /abc
EOF

(! test -L "$root/i-dont-exist")
test -L "$root/i-do-exist"
