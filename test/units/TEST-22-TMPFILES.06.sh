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
# Inspired by https://github.com/systemd/systemd/issues/9508
set -eux
set -o pipefail

test_snippet() {
    # First call with --dry-run to test the code paths
    systemd-tmpfiles --dry-run "$@" - <<EOF
d /var/tmp/foobar-test-06
d /var/tmp/foobar-test-06/important
R /var/tmp/foobar-test-06
EOF

    systemd-tmpfiles "$@" - <<EOF
d /var/tmp/foobar-test-06
d /var/tmp/foobar-test-06/important
R /var/tmp/foobar-test-06
EOF
}

test_snippet --create --remove
test -d /var/tmp/foobar-test-06
test -d /var/tmp/foobar-test-06/important

test_snippet --remove
test ! -f /var/tmp/foobar-test-06
test ! -f /var/tmp/foobar-test-06/important

test_snippet --create
test -d /var/tmp/foobar-test-06
test -d /var/tmp/foobar-test-06/important

touch /var/tmp/foobar-test-06/something-else

test_snippet --create
test -d /var/tmp/foobar-test-06
test -d /var/tmp/foobar-test-06/important
test -f /var/tmp/foobar-test-06/something-else

test_snippet --create --remove
test -d /var/tmp/foobar-test-06
test -d /var/tmp/foobar-test-06/important
test ! -f /var/tmp/foobar-test-06/something-else
