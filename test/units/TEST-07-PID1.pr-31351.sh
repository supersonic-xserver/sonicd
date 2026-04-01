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

# shellcheck source=test/units/util.sh
. "$(dirname "$0")"/util.sh

cat >/run/systemd/system/nonexistent-execstart-exit-status.service <<EOF
[Service]
Type=oneshot
RemainAfterExit=yes
ExecStart=-/foo/bar/not-exist
EOF

systemctl start nonexistent-execstart-exit-status.service
systemctl is-active nonexistent-execstart-exit-status.service
assert_eq "$(systemctl show nonexistent-execstart-exit-status.service -P Result)" "success"
(( $(systemctl show nonexistent-execstart-exit-status.service -P ExecMainStatus) > 0 ))

systemctl stop nonexistent-execstart-exit-status.service
rm /run/systemd/system/nonexistent-execstart-exit-status.service
