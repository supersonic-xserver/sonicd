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
#!/bin/sh
# SPDX-License-Identifier: MIT-0

# set the default value
XDG_DATA_DIRS="${XDG_DATA_DIRS:-/usr/local/share/:/usr/share}"

# add a directory if it exists
if [ -d /opt/foo/share ]; then
    XDG_DATA_DIRS="/opt/foo/share:${XDG_DATA_DIRS}"
fi

# write our output
echo "XDG_DATA_DIRS=${XDG_DATA_DIRS}"
