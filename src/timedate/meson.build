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

executables += [
        libexec_template + {
                'name' : 'systemd-timedated',
                'dbus' : true,
                'conditions' : ['ENABLE_TIMEDATED'],
                'sources' : files(
                        'timedated.c',
                        'hwclock-util.c',
                ),

        },
        executable_template + {
                'name' : 'timedatectl',
                'public' : true,
                'conditions' : ['ENABLE_TIMEDATECTL'],
                'sources' : files('timedatectl.c'),
                'dependencies' : libm,
        },
]

if conf.get('ENABLE_TIMEDATED') == 1
        install_data('org.freedesktop.timedate1.conf',
                     install_dir : dbuspolicydir)
        install_data('org.freedesktop.timedate1.service',
                     install_dir : dbussystemservicedir)
        install_data('org.freedesktop.timedate1.policy',
                     install_dir : polkitpolicydir)
endif
