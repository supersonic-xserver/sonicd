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

FSTYPE="$(stat --file-system --format "%T" /)"

if [[ "$FSTYPE" == "fuseblk" ]]; then
    echo "Root filesystem is virtiofs, skipping"
    exit 77
fi

if ! command -v systemd-nspawn >/dev/null; then
    echo "no systemd-nspawn" >/skipped
    exit 77
fi

# shellcheck source=test/units/test-control.sh
. "$(dirname "$0")"/test-control.sh

run_subtests

touch /testok
