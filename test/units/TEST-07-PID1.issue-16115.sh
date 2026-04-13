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

# Test ExecCondition= does not restart on abnormal or failure
# Issue: https://github.com/systemd/systemd/issues/16115

systemctl start issue16115-repro-1
systemctl start issue16115-repro-2
systemctl start issue16115-repro-3
sleep 5 # wait a bit in case there are restarts so we can count them below

[[ "$(systemctl show issue16115-repro-1 -P NRestarts)" == "0" ]]
[[ "$(systemctl show issue16115-repro-2 -P NRestarts)" == "0" ]]
[[ "$(systemctl show issue16115-repro-3 -P NRestarts)" == "0" ]]
