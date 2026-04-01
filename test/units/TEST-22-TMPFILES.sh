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

# shellcheck source=test/units/test-control.sh
. "$(dirname "$0")"/test-control.sh

if systemd-detect-virt --quiet --container; then
    # This comes from the selinux package and tries to write
    # some files under sysfs, which will be read-only in a container,
    # so mask it. It's not our tmpfiles.d file anyway.
    mkdir -p /run/tmpfiles.d/
    ln -s /dev/null /run/tmpfiles.d/selinux-policy.conf
fi

run_subtests

touch /testok
