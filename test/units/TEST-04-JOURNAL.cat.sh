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
set -eux
set -o pipefail

systemctl enable --now systemd-journald@cat-test.socket

systemd-cat --namespace cat-test env CAT_TEST_RESULT=1

timeout 30 bash -c "until systemctl -q is-active systemd-journald@cat-test.service; do sleep .5; done"

journalctl --namespace cat-test --grep "JOURNAL_STREAM="
journalctl --namespace cat-test --grep "CAT_TEST_RESULT=1"

systemctl disable --now systemd-journald@cat-test.socket
