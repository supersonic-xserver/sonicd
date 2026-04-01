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

if conf.get('ENABLE_XDG_AUTOSTART') != 1
        subdir_done()
endif

executables += [
        executable_template + {
                'name' : 'systemd-xdg-autostart-generator',
                'sources' : files('xdg-autostart-generator.c'),
                'extract' : files('xdg-autostart-service.c'),
                'install_dir' : usergeneratordir,
        },
        libexec_template + {
                'name' : 'systemd-xdg-autostart-condition',
                'sources' : files('xdg-autostart-condition.c'),
        },
        test_template + {
                'sources' : files('test-xdg-autostart.c'),
                'objects' : ['systemd-xdg-autostart-generator'],
        },
        fuzz_template + {
                'sources' : files('fuzz-xdg-desktop.c'),
                'objects' : ['systemd-xdg-autostart-generator'],
        },
]
