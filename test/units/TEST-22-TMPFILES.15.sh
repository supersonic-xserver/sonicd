#!/usr/bin/env bash
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
# SPDX-License-Identifier: LGPL-2.1-or-later
#
# Check specifier expansion in L lines.
#
set -eux

rm -fr /tmp/L
mkdir  /tmp/L

# Check that %h expands to $home.
home='/somewhere'
dst='/tmp/L/1'
src="$home"
HOME="$home" \
systemd-tmpfiles --dry-run --create - <<EOF
L     $dst    - - - - %h
EOF
test ! -h "$dst"

HOME="$home" \
systemd-tmpfiles --create - <<EOF
L     $dst    - - - - %h
EOF
test "$(readlink "$dst")" = "$src"

# Check that %h in the path is expanded, but
# the result of this expansion is not expanded once again.
root='/tmp/L/2'
home='/%U'
src="/usr/share/factory$home"
mkdir -p "$root$src"
dst="$root$home"
HOME="$home" \
systemd-tmpfiles --create --dry-run --root="$root" - <<EOF
L     %h    - - - -
EOF
test ! -h "$dst"

HOME="$home" \
systemd-tmpfiles --create --root="$root" - <<EOF
L     %h    - - - -
EOF
test "$(readlink "$dst")" = "$src"
