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

# Test StandardOutput=file:

systemd-run --wait --unit=TEST-23-UNIT-FILE-standard-output-one \
            -p StandardOutput=file:/tmp/stdout \
            -p StandardError=file:/tmp/stderr \
            -p Type=exec \
            bash -c 'echo x ; echo y >&2'
cmp /tmp/stdout <<EOF
x
EOF
cmp /tmp/stderr <<EOF
y
EOF

systemd-run --wait --unit=TEST-23-UNIT-FILE-standard-output-two \
            -p StandardOutput=file:/tmp/stdout \
            -p StandardError=file:/tmp/stderr \
            -p Type=exec \
            bash -c 'echo z ; echo a >&2'
cmp /tmp/stdout <<EOF
z
EOF
cmp /tmp/stderr <<EOF
a
EOF

systemd-run --wait --unit=TEST-23-UNIT-FILE-standard-output-three \
            -p StandardOutput=append:/tmp/stdout \
            -p StandardError=append:/tmp/stderr \
            -p Type=exec \
            bash -c 'echo b ; echo c >&2'
cmp /tmp/stdout <<EOF
z
b
EOF
cmp /tmp/stderr <<EOF
a
c
EOF

systemd-run --wait --unit=TEST-23-UNIT-FILE-standard-output-four \
            -p StandardOutput=truncate:/tmp/stdout \
            -p StandardError=truncate:/tmp/stderr \
            -p Type=exec \
            bash -c 'echo a ; echo b >&2'
cmp /tmp/stdout <<EOF
a
EOF
cmp /tmp/stderr <<EOF
b
EOF
