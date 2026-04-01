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
                'name' : 'nss_systemd',
                'conditions' : ['ENABLE_NSS_SYSTEMD'],
                'sources' : files(
                        'nss-systemd.c',
                        'userdb-glue.c',
                ),
                'version-script' : meson.current_source_dir() / 'nss-systemd.sym',
        },
]
