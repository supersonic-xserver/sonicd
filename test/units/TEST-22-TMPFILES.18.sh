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
# Tests for the --purge switch
#
set -eux
set -o pipefail

export SYSTEMD_LOG_LEVEL=debug

c='
d$ /tmp/somedir
f$ /tmp/somedir/somefile - - - - baz
f /tmp/someotherfile - - - - qux
'

systemd-tmpfiles --create - <<<"$c"
test -f /tmp/somedir/somefile
grep -q baz /tmp/somedir/somefile
grep -q qux /tmp/someotherfile

systemd-tmpfiles --purge --dry-run - <<<"$c"
test -f /tmp/somedir/somefile
grep -q baz /tmp/somedir/somefile
grep -q qux /tmp/someotherfile

systemd-tmpfiles --purge - <<<"$c"
test ! -f /tmp/somedir/somefile
test ! -d /tmp/somedir/
grep -q qux /tmp/someotherfile

systemd-tmpfiles --create --purge --dry-run - <<<"$c"
test ! -f /tmp/somedir/somefile
test ! -d /tmp/somedir/
grep -q qux /tmp/someotherfile

systemd-tmpfiles --create --purge - <<<"$c"
test -f /tmp/somedir/somefile
grep -q baz /tmp/somedir/somefile
grep -q qux /tmp/someotherfile

systemd-tmpfiles --purge - <<<"$c"
test ! -f /tmp/somedir/somefile
test ! -d /tmp/somedir/
grep -q qux /tmp/someotherfile

rm /tmp/someotherfile
