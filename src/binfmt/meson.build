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

if conf.get('ENABLE_BINFMT') != 1
        subdir_done()
endif

executables += [
        libexec_template + {
                'name' : 'systemd-binfmt',
                'public' : true,
                'sources' : files('binfmt.c'),
        },
]

install_emptydir(binfmtdir)
if install_sysconfdir
        install_emptydir(sysconfdir / 'binfmt.d')
endif
