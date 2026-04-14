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
# shellcheck disable=SC2016
set -eux
set -o pipefail

OUTPUT_FILE="$1"

dump_creds_tree() {
    grep . "$CREDENTIALS_DIRECTORY"/* >"$OUTPUT_FILE"
}

on_sighup() {
    systemd-notify --reloading
    dump_creds_tree
    systemd-notify --ready
}

trap on_sighup SIGHUP

export SYSTEMD_LOG_LEVEL=debug

dump_creds_tree
systemd-notify --ready

sleep infinity &
while :; do
    wait || :
done
