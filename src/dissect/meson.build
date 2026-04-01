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

if conf.get('HAVE_BLKID') != 1
        subdir_done()
endif

executables += [
        executable_template + {
                'name' : 'systemd-dissect',
                'public' : true,
                'sources' : files('dissect.c'),
        },
]

install_symlink('mount.ddi',
                pointing_to : sbin_to_bin + 'systemd-dissect',
                install_dir : sbindir)
