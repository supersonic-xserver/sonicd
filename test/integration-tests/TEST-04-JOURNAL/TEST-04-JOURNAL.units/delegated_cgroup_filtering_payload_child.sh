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
#!/bin/bash
# SPDX-License-Identifier: LGPL-2.1-or-later

echo $$ >/sys/fs/cgroup/system.slice/delegated-cgroup-filtering.service/the_child/cgroup.procs

echo "child_process: hello, world!"
echo "child_process: hello, people!"

# If the service finishes extremely fast, journald cannot find the source of the
# stream. Hence, we need to call 'journalctl --sync' before service finishes.
journalctl --sync
