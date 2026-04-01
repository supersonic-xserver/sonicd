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
# -*- mode: shell-script; indent-tabs-mode: nil; sh-basic-offset: 4; -*-
# ex: ts=8 sw=4 sts=4 et filetype=sh
set -eux
set -o pipefail

at_exit() {
    set +e

    rm -fr /run/hoge /tmp/aaa
}

trap at_exit EXIT

# RuntimeDirectory= should be preserved for oneshot units if RemainAfterExit=yes

systemd-run --service-type=oneshot --remain-after-exit \
            -u TEST-23-remain-after-exit.service \
            -p RuntimeDirectory=TEST-23-remain-after-exit \
            true

[[ -d /run/TEST-23-remain-after-exit ]]

systemctl stop TEST-23-remain-after-exit.service

[[ ! -e /run/TEST-23-remain-after-exit ]]

# Test RuntimeDirectoryPreserve=yes

systemd-mount -p RuntimeDirectory=hoge -p RuntimeDirectoryPreserve=yes -t tmpfs tmpfs /tmp/aaa

touch /run/hoge/foo
touch /tmp/aaa/bbb

systemctl restart tmp-aaa.mount

test -e /run/hoge/foo
test ! -e /tmp/aaa/bbb
