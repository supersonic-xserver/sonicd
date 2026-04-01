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

RESULTS_FILE=/tmp/TEST-66-DEVICE-ISOLATION.serviceresults

systemctl start TEST-66-DEVICE-ISOLATION-device-isolation.service

sleep 5
grep -q "Operation not permitted" "$RESULTS_FILE"

systemctl daemon-reload
systemctl daemon-reexec

systemctl stop TEST-66-DEVICE-ISOLATION-device-isolation.service

grep -q "thisshouldnotbehere" "$RESULTS_FILE" && exit 42

touch /testok
