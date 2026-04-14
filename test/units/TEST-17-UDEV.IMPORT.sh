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
set -ex
set -o pipefail

mkdir -p /run/udev/rules.d/

cat >/run/udev/rules.d/50-testsuite.rules <<EOF
SUBSYSTEM=="mem", KERNEL=="null", OPTIONS="log_level=debug"
ACTION=="add", SUBSYSTEM=="mem", KERNEL=="null", IMPORT{program}="/usr/bin/echo -e HOGE=aa\\\\x20\\\\x20\\\\x20bb\nFOO=\\\\x20aaa\\\\x20\n\n\n"
EOF

udevadm control --reload
SYSTEMD_LOG_LEVEL=debug udevadm trigger --verbose --settle --action add /dev/null

test -f /run/udev/data/c1:3
udevadm info /dev/null | grep 'E: HOGE=aa\\x20\\x20\\x20bb' >/dev/null
udevadm info /dev/null | grep 'E: FOO=\\x20aaa\\x20' >/dev/null

rm /run/udev/rules.d/50-testsuite.rules
udevadm control --reload

exit 0
