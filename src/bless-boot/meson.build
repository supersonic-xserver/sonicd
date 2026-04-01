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

if get_option('link-boot-shared')
        boot_link_with = [libshared]
else
        boot_link_with = [
                libshared_static,
                libsystemd_static,
        ]
endif

executables += [
        libexec_template + {
                'name' : 'systemd-bless-boot',
                'public' : true,
                'conditions' : [
                        'HAVE_BLKID',
                        'ENABLE_BOOTLOADER',
                ],
                'sources' : files('bless-boot.c'),
                'link_with' : boot_link_with,
        },
        generator_template + {
                'name' : 'systemd-bless-boot-generator',
                'conditions' : [
                        'HAVE_BLKID',
                        'ENABLE_BOOTLOADER',
                ],
                'sources' : files('bless-boot-generator.c'),
                'link_with' : boot_link_with,
        },
        libexec_template + {
                'name' : 'systemd-boot-check-no-failures',
                'sources' : files('boot-check-no-failures.c'),
        },
]
