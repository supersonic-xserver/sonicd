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

if conf.get('ENABLE_MOUNTFSD') != 1
        subdir_done()
endif

systemd_mountwork_sources = files(
        'mountwork.c',
)

systemd_mountfsd_sources = files(
        'mountfsd.c',
        'mountfsd-manager.c',
)

executables += [
        libexec_template + {
                'name' : 'systemd-mountfsd',
                'sources' : systemd_mountfsd_sources,
        },
        libexec_template + {
                'name' : 'systemd-mountwork',
                'sources' : systemd_mountwork_sources,
        },
]

install_data('io.systemd.mount-file-system.policy',
             install_dir : polkitpolicydir)
