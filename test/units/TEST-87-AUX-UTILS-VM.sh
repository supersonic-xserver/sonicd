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

# For issue #38765
journalctl --sync
if journalctl -q -o short-monotonic --grep "Looking at job .*/.* conflicted_by=(yes|no)" >/failed; then
    echo "Found unexpected unmergeable jobs"
    cat /failed
    exit 1
fi

# shellcheck source=test/units/test-control.sh
. "$(dirname "$0")"/test-control.sh

run_subtests

touch /testok
