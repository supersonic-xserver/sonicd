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

# shellcheck source=test/units/util.sh
. "$(dirname "$0")"/util.sh

at_exit() {
    set +e
    systemctl stop waldo-ask-pw-agent.service
}

trap at_exit EXIT

systemd-ask-password --help
systemd-tty-ask-password-agent --list

varlinkctl introspect /run/systemd/io.systemd.AskPassword

# Spawn an agent that always replies all ask password requests with "waldo"
systemd-run -u waldo-ask-pw-agent.service -p Environment=SYSTEMD_ASK_PASSWORD_AGENT_PASSWORD=waldo -p Type=notify systemd-tty-ask-password-agent --watch --console=/dev/console
assert_eq "$(systemd-ask-password --no-tty)" "waldo"
assert_eq "$(varlinkctl call /usr/bin/systemd-ask-password io.systemd.AskPassword.Ask '{"message":"foobar"}' | jq '.passwords[0]')" "\"waldo\""
