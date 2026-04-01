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
# Test for C-style escapes in file names and contents
set -eux
set -o pipefail

data="\x20foo\nbar"
dst="/tmp/x/\x20a\nb"

systemd-tmpfiles --create - <<EOF
f     "$dst" 0644 0 0 - $data
EOF

diff "$(printf "/tmp/x/\x20a\nb")" <(printf "\x20foo\nbar")
