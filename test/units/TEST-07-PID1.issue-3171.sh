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

# SocketGroup lost on daemon-reload with unit moving away temporarily
# Issue: https://github.com/systemd/systemd/issues/3171

echo "g adm - - -" | systemd-sysusers -

U=/run/systemd/system/issue-3171.socket
cat >$U <<EOF
[Unit]
Description=Test 12 socket
[Socket]
Accept=yes
ListenStream=/run/issue-3171.socket
SocketGroup=adm
SocketMode=0660
EOF

cat >/run/systemd/system/issue-3171@.service <<EOF
[Unit]
Description=Test service
[Service]
StandardInput=socket
ExecStart=bash -x -c cat
EOF

systemctl start issue-3171.socket
systemctl is-active issue-3171.socket
[[ "$(stat --format='%G' /run/issue-3171.socket)" == adm ]]
echo A | ncat -w1 -U /run/issue-3171.socket

mv $U ${U}.disabled
systemctl daemon-reload
systemctl is-active issue-3171.socket
[[ "$(stat --format='%G' /run/issue-3171.socket)" == adm ]]
echo B | ncat -w1 -U /run/issue-3171.socket && exit 1

mv ${U}.disabled $U
systemctl daemon-reload
systemctl is-active issue-3171.socket
echo C | ncat -w1 -U /run/issue-3171.socket && exit 1
[[ "$(stat --format='%G' /run/issue-3171.socket)" == adm ]]

systemctl restart issue-3171.socket
systemctl is-active issue-3171.socket
echo D | ncat -w1 -U /run/issue-3171.socket
[[ "$(stat --format='%G' /run/issue-3171.socket)" == adm ]]
