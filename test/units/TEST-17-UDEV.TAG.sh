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

test ! -f /run/udev/tags/added/c1:3
test ! -f /run/udev/tags/changed/c1:3
udevadm info /dev/null | grep -E 'E: (TAGS|CURRENT_TAGS)=.*:(added|changed):' && exit 1

cat >/run/udev/rules.d/50-testsuite.rules <<EOF
SUBSYSTEM=="mem", KERNEL=="null", OPTIONS="log_level=debug"
ACTION=="add", SUBSYSTEM=="mem", KERNEL=="null", TAG+="added"
ACTION=="change", SUBSYSTEM=="mem", KERNEL=="null", TAG+="changed"
EOF

udevadm control --reload
SYSTEMD_LOG_LEVEL=debug udevadm trigger --verbose --settle --action add /dev/null

test -f /run/udev/tags/added/c1:3
test ! -f /run/udev/tags/changed/c1:3
udevadm info /dev/null | grep 'E: TAGS=.*:added:.*' >/dev/null
udevadm info /dev/null | grep 'E: CURRENT_TAGS=.*:added:.*' >/dev/null
udevadm info /dev/null | grep 'E: TAGS=.*:changed:.*' >/dev/null && { echo 'unexpected TAGS='; exit 1; }
udevadm info /dev/null | grep 'E: CURRENT_TAGS=.*:changed:.*' >/dev/null && { echo 'unexpected CURRENT_TAGS='; exit 1; }

SYSTEMD_LOG_LEVEL=debug udevadm trigger --verbose --settle --action change /dev/null

test -f /run/udev/tags/added/c1:3
test -f /run/udev/tags/changed/c1:3
udevadm info /dev/null | grep 'E: TAGS=.*:added:.*' >/dev/null
udevadm info /dev/null | grep 'E: CURRENT_TAGS=.*:added:.*' >/dev/null && { echo 'unexpected CURRENT_TAGS='; exit 1; }
udevadm info /dev/null | grep 'E: TAGS=.*:changed:.*' >/dev/null
udevadm info /dev/null | grep 'E: CURRENT_TAGS=.*:changed:.*' >/dev/null

SYSTEMD_LOG_LEVEL=debug udevadm trigger --verbose --settle --action add /dev/null

test -f /run/udev/tags/added/c1:3
test -f /run/udev/tags/changed/c1:3
udevadm info /dev/null | grep 'E: TAGS=.*:added:.*' >/dev/null
udevadm info /dev/null | grep 'E: CURRENT_TAGS=.*:added:.*' >/dev/null
udevadm info /dev/null | grep 'E: TAGS=.*:changed:.*' >/dev/null
udevadm info /dev/null | grep 'E: CURRENT_TAGS=.*:changed:.*' >/dev/null && { echo 'unexpected CURRENT_TAGS='; exit 1; }

rm /run/udev/rules.d/50-testsuite.rules
udevadm control --reload

exit 0
