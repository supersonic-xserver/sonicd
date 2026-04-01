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
# Tests for the ":" uid/gid/mode modifier
#
set -eux

rm -rf /tmp/someinode

systemd-tmpfiles --create - <<EOF
d /tmp/someinode :0123 :1 :1
EOF
test "$(stat -c %F:%u:%g:%a /tmp/someinode)" = "directory:1:1:123"

systemd-tmpfiles --create - <<EOF
d /tmp/someinode :0321 :2 :2
EOF
test "$(stat -c %F:%u:%g:%a /tmp/someinode)" = "directory:1:1:123"

systemd-tmpfiles --create - <<EOF
d /tmp/someinode 0321 2 2
EOF
test "$(stat -c %F:%u:%g:%a /tmp/someinode)" = "directory:2:2:321"

systemd-tmpfiles --create - <<EOF
d /tmp/someinode :0123 :1 :1
EOF
test "$(stat -c %F:%u:%g:%a /tmp/someinode)" = "directory:2:2:321"

rm -rf /tmp/someinode

systemd-tmpfiles --create - <<EOF
d /tmp/someinode :0123 :1 :1
EOF
test "$(stat -c %F:%u:%g:%a /tmp/someinode)" = "directory:1:1:123"

rm -rf /tmp/someinode
