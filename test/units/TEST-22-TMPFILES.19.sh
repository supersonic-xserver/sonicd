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
#
# Tests for character and block device creation
#
set -eux
set -o pipefail

rm -rf /tmp/dev
mkdir /tmp/dev

# We are running tests in /tmp, which would normally be mounted nodev,
# so we only try with --dry-run.

systemd-tmpfiles --dry-run --create - <<EOF
c /tmp/dev/char  - - - - 11:12
b /tmp/dev/block - - - - 11:14
EOF

test ! -e /tmp/dev/char
test ! -e /tmp/dev/block

systemd-tmpfiles --dry-run --create - <<EOF
c+ /tmp/dev/char  - - - - 11:12
b+ /tmp/dev/block - - - - 11:14
EOF

test ! -e /tmp/dev/char
test ! -e /tmp/dev/block
