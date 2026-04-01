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
#!/usr/bin/python
# SPDX-License-Identifier: MIT-0

import platform
os_release = platform.freedesktop_os_release()

pretty_name = os_release.get('PRETTY_NAME', 'Linux')
print(f'Running on {pretty_name!r}')

if 'fedora' in [os_release.get('ID', 'linux'),
                *os_release.get('ID_LIKE', '').split()]:
    print('Looks like Fedora!')
