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

if conf.get('ENABLE_SYSUSERS') != 1
        subdir_done()
endif

executables += [
        executable_template + {
                'name' : 'systemd-sysusers',
                'public' : true,
                'extract' : files('sysusers.c'),
                'dependencies' : libaudit_cflags,
        },
        executable_template + {
                'name' : 'systemd-sysusers.standalone',
                'public' : true,
                'objects' : ['systemd-sysusers'],
                'link_with' : [
                        libc_wrapper_static,
                        libbasic_static,
                        libshared_static,
                        libsystemd_static,
                ],
                'dependencies' : libaudit_cflags,
        },
]
