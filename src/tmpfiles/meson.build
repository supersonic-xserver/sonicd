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

if conf.get('ENABLE_TMPFILES') != 1
        subdir_done()
endif

offline_passwd_c = files('offline-passwd.c')

executables += [
        executable_template + {
                'name' : 'systemd-tmpfiles',
                'public' : true,
                'extract' : files('tmpfiles.c') +
                            offline_passwd_c,
                'dependencies' : libacl_cflags,
        },
        executable_template + {
                'name' : 'systemd-tmpfiles.standalone',
                'public' : true,
                'objects' : ['systemd-tmpfiles'],
                'link_with' : [
                        libc_wrapper_static,
                        libbasic_static,
                        libshared_static,
                        libsystemd_static,
                ],
                'dependencies' : libacl_cflags,
        },
        test_template + {
                'sources' : files('test-offline-passwd.c') +
                            offline_passwd_c,
        },
]
