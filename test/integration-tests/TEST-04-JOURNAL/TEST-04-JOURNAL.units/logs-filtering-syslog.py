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
#!/usr/bin/python3
# SPDX-License-Identifier: LGPL-2.1-or-later

import subprocess
import syslog

if __name__ == '__main__':
    syslog.openlog(ident="logs-filtering", logoption=syslog.LOG_PID)
    syslog.syslog(syslog.LOG_NOTICE, "Logging from the service, and ~more~ foo bar")

    subprocess.check_output(
        ['journalctl', '--sync'],
        stdin=subprocess.DEVNULL,
        text=True)
