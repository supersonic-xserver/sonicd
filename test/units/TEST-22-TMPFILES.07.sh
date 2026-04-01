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
# Verifies the issues described by https://github.com/systemd/systemd/issues/10191
set -eux
set -o pipefail

rm -rf /tmp/test-prefix

mkdir /tmp/test-prefix
touch /tmp/test-prefix/file

systemd-tmpfiles --remove - <<EOF
r /tmp/test-prefix
r /tmp/test-prefix/file
EOF

test ! -f /tmp/test-prefix/file
test ! -f /tmp/test-prefix

mkdir /tmp/test-prefix
touch /tmp/test-prefix/file

systemd-tmpfiles --remove - <<EOF
r /tmp/test-prefix/file
r /tmp/test-prefix
EOF

test ! -f /tmp/test-prefix/file
test ! -f /tmp/test-prefix
