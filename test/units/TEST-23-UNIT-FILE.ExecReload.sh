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

# Test ExecReload= (PR #13098)

export SYSTEMD_PAGER=
SERVICE_PATH="$(mktemp /etc/systemd/system/execreloadXXX.service)"
SERVICE_NAME="${SERVICE_PATH##*/}"

echo "[#1] Failing ExecReload= should not kill the service"
cat >"$SERVICE_PATH" <<EOF
[Service]
ExecStart=sleep infinity
ExecReload=false
EOF

systemctl daemon-reload
systemctl start "$SERVICE_NAME"
systemctl status "$SERVICE_NAME"
# The reload SHOULD fail but SHOULD NOT affect the service state
(! systemctl reload "$SERVICE_NAME")
systemctl status "$SERVICE_NAME"
systemctl stop "$SERVICE_NAME"


echo "[#2] Failing ExecReload= should not kill the service (multiple ExecReload=)"
cat >"$SERVICE_PATH" <<EOF
[Service]
ExecStart=sleep infinity
ExecReload=true
ExecReload=false
ExecReload=true
EOF

systemctl daemon-reload
systemctl start "$SERVICE_NAME"
systemctl status "$SERVICE_NAME"
# The reload SHOULD fail but SHOULD NOT affect the service state
(! systemctl reload "$SERVICE_NAME")
systemctl status "$SERVICE_NAME"
systemctl stop "$SERVICE_NAME"

echo "[#3] Failing ExecReload=- should not affect reload's exit code"
cat >"$SERVICE_PATH" <<EOF
[Service]
ExecStart=sleep infinity
ExecReload=-false
EOF

systemctl daemon-reload
systemctl start "$SERVICE_NAME"
systemctl status "$SERVICE_NAME"
systemctl reload "$SERVICE_NAME"
systemctl status "$SERVICE_NAME"
systemctl stop "$SERVICE_NAME"
