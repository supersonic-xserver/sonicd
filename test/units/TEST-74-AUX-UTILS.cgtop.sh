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

# Without tty attached cgtop should default to --iterations=1
systemd-cgtop
systemd-cgtop --iterations=1
# Same as --iterations=1
systemd-cgtop -1
systemd-cgtop --delay=1ms
systemd-cgtop --raw
systemd-cgtop --batch
systemd-cgtop --cpu=percentage
systemd-cgtop --cpu=time
systemd-cgtop -P
systemd-cgtop -k
systemd-cgtop --recursive=no -P
systemd-cgtop --recursive=no -k
systemd-cgtop --depth=0
systemd-cgtop --depth=100

for order in path tasks cpu memory io; do
    systemd-cgtop --order="$order"
done
systemd-cgtop -p -t -c -m -i

(! systemd-cgtop --cpu=foo)
(! systemd-cgtop --order=foo)
(! systemd-cgtop --depth=-1)
(! systemd-cgtop --recursive=foo)
(! systemd-cgtop --delay=1foo)
