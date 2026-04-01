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

if conf.get('ENABLE_HOSTNAMED') != 1
        subdir_done()
endif

executables += [
        libexec_template + {
                'name' : 'systemd-hostnamed',
                'dbus' : true,
                'sources' : files('hostnamed.c'),
        },
        executable_template + {
                'name' : 'hostnamectl',
                'public' : true,
                'sources' : files('hostnamectl.c'),
        },
]

install_data('org.freedesktop.hostname1.conf',
             install_dir : dbuspolicydir)
install_data('org.freedesktop.hostname1.service',
             install_dir : dbussystemservicedir)
install_data('org.freedesktop.hostname1.policy',
             install_dir : polkitpolicydir)
