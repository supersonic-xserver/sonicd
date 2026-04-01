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

# Assert when calling AttachProcesses on a unit without ref_uid set

at_exit() {
    set +e

    systemctl stop attach_and_barf.service
    rm -f /run/systemd/system/attach_and_barf.service
    systemctl daemon-reload
}

trap at_exit EXIT

mkdir -p /run/systemd/system

cat >/run/systemd/system/attach_and_barf.service <<EOF
[Service]
Type=simple
Delegate=yes
ExecStart=sleep infinity
EOF

systemctl daemon-reload
systemctl start attach_and_barf.service
run0 -u testuser \
    busctl --system call \
        org.freedesktop.systemd1 \
        /org/freedesktop/systemd1 \
        org.freedesktop.systemd1.Manager \
        AttachProcessesToUnit \
        "ssau" "attach_and_barf.service" "" 1 0 |& grep -F "Access denied" &>/dev/null
