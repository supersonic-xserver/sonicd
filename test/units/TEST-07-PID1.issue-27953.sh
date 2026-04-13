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
#!/usr/bin/env bash
# SPDX-License-Identifier: LGPL-2.1-or-later
set -eux
set -o pipefail

# Check if the unit doesn't remain in active state after the main PID exits
# Issue: https://github.com/systemd/systemd/issues/27953

systemctl start issue27953.service
timeout 10 bash -c 'while systemctl is-active issue27953.service; do sleep .5; done'
[[ "$(systemctl show -P ExitType issue27953.service)" == main ]]
