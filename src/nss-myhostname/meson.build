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

modules += [
        nss_template + {
                'name' : 'nss_myhostname',
                'conditions' : ['ENABLE_NSS_MYHOSTNAME'],
                'sources' : files('nss-myhostname.c'),
                'version-script' : meson.current_source_dir() / 'nss-myhostname.sym',
        },
]
