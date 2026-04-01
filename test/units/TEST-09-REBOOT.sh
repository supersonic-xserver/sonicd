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

export NUM_REBOOT=4

# shellcheck source=test/units/test-control.sh
. "$(dirname "$0")"/test-control.sh

# shellcheck source=test/units/util.sh
. "$(dirname "$0")"/util.sh

systemd-cat echo "Reboot count: $REBOOT_COUNT"
systemd-cat journalctl --list-boots

run_subtests

if [[ "$REBOOT_COUNT" -lt "$NUM_REBOOT" ]]; then
    SYSTEMCTL_SKIP_AUTO_SOFT_REBOOT=1
    export SYSTEMCTL_SKIP_AUTO_SOFT_REBOOT
    systemctl_final reboot
    # Now block until the reboot killing spree kills us.
    exec sleep infinity
elif [[ "$REBOOT_COUNT" -gt "$NUM_REBOOT" ]]; then
    assert_not_reached
fi

touch /testok
