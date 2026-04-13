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
set -ex
set -o pipefail

if ! env --block-signal=SIGUSR1 true 2> /dev/null ; then
    echo "env tool too old, can't block signals, skipping test." >&2
    echo OK >/testok
    exit 0
fi

UNIT="test-sigqueue-$RANDOM.service"

systemd-run -u "$UNIT" -p Type=notify -p DynamicUser=1 -- env --block-signal=SIGRTMIN+7 systemd-notify --exec --ready \; sleep infinity

systemctl kill --kill-whom=main --kill-value=4 --signal=SIGRTMIN+7 "$UNIT"
systemctl kill --kill-whom=main --kill-value=4 --signal=SIGRTMIN+7 "$UNIT"
systemctl kill --kill-whom=main --kill-value=7 --signal=SIGRTMIN+7 "$UNIT"
systemctl kill --kill-whom=main --kill-value=16 --signal=SIGRTMIN+7 "$UNIT"
systemctl kill --kill-whom=main --kill-value=32 --signal=SIGRTMIN+7 "$UNIT"
systemctl kill --kill-whom=main --kill-value=16 --signal=SIGRTMIN+7 "$UNIT"

# We simply check that six signals are queued now. There's no easy way to check
# from shell which ones those are, hence we don't check that.
P=$(systemctl show -P MainPID "$UNIT")

test "$(grep SigQ: /proc/"$P"/status | cut -d: -f2 | cut -d/ -f1)" -eq 6

systemctl stop $UNIT

touch /testok
