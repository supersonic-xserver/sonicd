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

bootctl_sources = files(
        'bootctl.c',
        'bootctl-install.c',
        'bootctl-random-seed.c',
        'bootctl-reboot-to-firmware.c',
        'bootctl-set-efivar.c',
        'bootctl-status.c',
        'bootctl-uki.c',
        'bootctl-unlink.c',
        'bootctl-cleanup.c',
        'bootctl-util.c',
        'bootspec-util.c',
)

executables += [
        executable_template + {
                'name' : 'bootctl',
                'public' : true,
                'conditions' : [
                          'HAVE_BLKID',
                ],
                'sources' : bootctl_sources,
                'link_with' : boot_link_with,
                'dependencies' : [libopenssl],
        },
]
