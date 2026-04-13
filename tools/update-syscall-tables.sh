#!/bin/sh
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
set -eu

cd "${1:?}" && shift

curl --fail -L -o syscall-list.txt 'https://raw.githubusercontent.com/hrw/syscalls-table/master/data/syscall-names.text'

for arch in "$@"; do
    curl --fail -L -o "syscalls-$arch.txt" "https://raw.githubusercontent.com/hrw/syscalls-table/master/data/tables/syscalls-$arch"
done
