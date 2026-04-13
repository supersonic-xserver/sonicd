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

P=/run/systemd/system.conf.d
mkdir $P

cat >$P/rlimits.conf <<EOF
[Manager]
DefaultLimitNOFILE=10000:16384
EOF

systemctl daemon-reload

[[ "$(systemctl show -P DefaultLimitNOFILESoft)" = "10000" ]]
[[ "$(systemctl show -P DefaultLimitNOFILE)" = "16384" ]]

[[ "$(systemctl show -P LimitNOFILESoft TEST-05-RLIMITS.service)" = "10000" ]]
[[ "$(systemctl show -P LimitNOFILE TEST-05-RLIMITS.service)" = "16384" ]]

# shellcheck disable=SC2016
systemd-run --wait -t bash -c '[[ "$(ulimit -n -S)" = "10000" ]]'
# shellcheck disable=SC2016
systemd-run --wait -t bash -c '[[ "$(ulimit -n -H)" = "16384" ]]'
