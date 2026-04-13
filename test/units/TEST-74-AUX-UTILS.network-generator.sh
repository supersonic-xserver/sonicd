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
# shellcheck disable=SC2016
set -eux
set -o pipefail

at_exit() {
    rm -f /run/credstore/network.conf.50-testme
    rm -f /run/credstore/network.network.50-testme
    rm -f /run/systemd/networkd.conf.d/50-testme.conf
    rm -f /run/systemd/network/50-testme.network
    rm -f /run/systemd/system/systemd-network-generator.service.d/50-testme.conf
}

trap at_exit EXIT

mkdir -p /run/credstore
cat >/run/credstore/network.conf.50-testme <<EOF
[Network]
SpeedMeter=yes
EOF

cat >/run/credstore/network.network.50-testme <<EOF
[Match]
Property=IDONTEXIST
EOF

systemctl edit systemd-network-generator.service --stdin --drop-in=50-testme.conf <<EOF
[Service]
LoadCredential=network.conf.50-testme
LoadCredential=network.network.50-testme
EOF

systemctl restart systemd-network-generator

diff /run/credstore/network.conf.50-testme /run/systemd/networkd.conf.d/50-testme.conf
diff /run/credstore/network.network.50-testme /run/systemd/network/50-testme.network
