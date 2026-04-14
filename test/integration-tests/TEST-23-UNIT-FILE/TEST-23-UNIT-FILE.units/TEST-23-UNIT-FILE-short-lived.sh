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

if [ -f /tmp/TEST-23-UNIT-FILE.counter ] ; then
    read -r counter < /tmp/TEST-23-UNIT-FILE.counter
    counter=$((counter + 1))
else
    counter=0
fi

echo "$counter" >/tmp/TEST-23-UNIT-FILE.counter

if [ "$counter" -eq 5 ] ; then
    systemctl kill --kill-whom=main -sUSR1 TEST-23-UNIT-FILE.service
fi

exec sleep 1.5
