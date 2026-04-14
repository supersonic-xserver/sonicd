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

IFNAME=test-udev-aaa
ip link add "$IFNAME" type dummy
IFINDEX=$(ip -json link show "$IFNAME" | jq '.[].ifindex')
udevadm wait --timeout=10 "/sys/class/net/$IFNAME"
# Check if the database file is created.
[[ -e "/run/udev/data/n$IFINDEX" ]]

ip link del "$IFNAME"
udevadm wait --timeout=10 --removed --settle "/sys/class/net/$IFNAME"
# CHeck if the database file is removed.
[[ ! -e "/run/udev/data/n$IFINDEX" ]]

exit 0
