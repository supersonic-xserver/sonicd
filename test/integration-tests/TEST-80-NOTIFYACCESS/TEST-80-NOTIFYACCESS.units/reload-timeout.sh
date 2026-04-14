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

COUNTER=0

sync_in() {
    read -r x < /tmp/syncfifo2
    test "$x" = "$1"
}

wait_for_signal() {
    local notify="${1:?}"
    local p
    local c

    sleep infinity &
    p=$!
    c="${COUNTER:-0}"

    # Notify readiness after 'sleep' is running to avoid race
    # condition where the SIGHUP is sent before 'sleep' is ready to
    # receive it and we get stuck
    if [ "$notify" -eq 1 ]; then
        systemd-notify --ready
    fi

    # ...but even that is not sufficient sometimes, so check if the
    # callback has already ran by checking the counter
    if [ "$c" -ne "$COUNTER" ]; then
        kill -TERM "$p" || :
    else
        wait "$p" || :
    fi
}

sighup_handler() {
    echo "hup$(( ++COUNTER ))" >/tmp/syncfifo1
}

trap sighup_handler SIGHUP

export SYSTEMD_LOG_LEVEL=debug

wait_for_signal 1
systemd-notify --reloading

wait_for_signal 0
systemd-notify --reloading
sync_in ready

wait_for_signal 1
systemd-notify --reloading --ready

exec sleep infinity
