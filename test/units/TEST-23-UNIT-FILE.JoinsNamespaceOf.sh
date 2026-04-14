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

# Test JoinsNamespaceOf= with PrivateTmp=yes

# simple case
systemctl start TEST-23-UNIT-FILE-joins-namespace-of-1.service
systemctl start TEST-23-UNIT-FILE-joins-namespace-of-2.service
systemctl start TEST-23-UNIT-FILE-joins-namespace-of-3.service
systemctl stop TEST-23-UNIT-FILE-joins-namespace-of-1.service

# inverse dependency
systemctl start TEST-23-UNIT-FILE-joins-namespace-of-4.service
systemctl start TEST-23-UNIT-FILE-joins-namespace-of-5.service
systemctl stop TEST-23-UNIT-FILE-joins-namespace-of-4.service

# transitive dependency
systemctl start TEST-23-UNIT-FILE-joins-namespace-of-6.service
systemctl start TEST-23-UNIT-FILE-joins-namespace-of-7.service
systemctl start TEST-23-UNIT-FILE-joins-namespace-of-8.service
systemctl start TEST-23-UNIT-FILE-joins-namespace-of-9.service
systemctl stop TEST-23-UNIT-FILE-joins-namespace-of-6.service
systemctl stop TEST-23-UNIT-FILE-joins-namespace-of-8.service
