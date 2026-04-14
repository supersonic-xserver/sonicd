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

# Check that timestamps of a Type=notify service are consistent

systemd-run --service-type notify --property NotifyAccess=all --unit notify.service --wait bash -c 'systemd-notify --ready; exit 1' || :

start=$(systemctl show --property=ExecMainStartTimestampMonotonic --value notify.service)
handoff=$(systemctl show --property=ExecMainHandoffTimestampMonotonic --value notify.service)
active=$(systemctl show --property=ActiveEnterTimestampMonotonic --value notify.service)
exit=$(systemctl show --property=ExecMainExitTimestampMonotonic --value notify.service)

[[ $start -le $handoff ]]
[[ $handoff -le $active ]]
[[ $active -le $exit ]]
