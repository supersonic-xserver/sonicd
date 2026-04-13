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
#!/usr/bin/env python3
# SPDX-License-Identifier: LGPL-2.1-or-later

"""Generate sample input for fuzz-bootspec"""

import json
import os
import sys

config = open(sys.argv[1]).read()
loader = [entry for entry in open(sys.argv[2], encoding='utf-16-le').read().split('\0')
          if len(entry) > 2]   # filter out fluff from bad decoding
entries = [(os.path.basename(name), open(name).read())
           for name in sys.argv[3:]]

data = {
    'config': config,
    'entries': entries,
    'loader': loader,
}

print(json.dumps(data, indent=4))
