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

if conf.get('HAVE_LIBMOUNT') != 1
        subdir_done()
endif

shutdown_detach_sources = files(
        'detach-swap.c',
        'umount.c',
)

executables += [
        libexec_template + {
                'name' : 'systemd-shutdown',
                'extract' : files(
                        'detach-dm.c',
                        'detach-loopback.c',
                        'detach-md.c',
                        'shutdown.c',
                ) + shutdown_detach_sources,
                'dependencies' : libmount_cflags,
        },
        libexec_template + {
                'name' : 'systemd-shutdown.standalone',
                'objects' : ['systemd-shutdown'],
                'link_with' : [
                        libc_wrapper_static,
                        libbasic_static,
                        libshared_static,
                        libsystemd_static,
                ],
                'dependencies' : libmount_cflags,
        },
        test_template + {
                'sources' : files('test-umount.c') +
                            shutdown_detach_sources,
                'dependencies' : libmount_cflags,
        },
]
