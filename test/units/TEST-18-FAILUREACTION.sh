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
set -eux
set -o pipefail

systemd-run --wait -p FailureAction=poweroff true
(! systemd-run --wait -p SuccessAction=poweroff false)

if ! test -f /firstphase ; then
    echo OK >/firstphase
    systemd-run --wait -p SuccessAction=reboot true
else
    echo OK >/testok
    systemd-run --wait -p FailureAction=exit -p FailureActionExitStatus=123 false
fi

sleep infinity
