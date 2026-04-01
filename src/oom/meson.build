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

if conf.get('ENABLE_OOMD') != 1
        subdir_done()
endif

systemd_oomd_sources = files(
        'oomd.c',
        'oomd-conf.c',
        'oomd-manager.c',
        'oomd-manager-bus.c',
)
systemd_oomd_extract_sources = files(
        'oomd-util.c',
)

executables += [
        libexec_template + {
                'name' : 'systemd-oomd',
                'dbus' : true,
                'sources' : systemd_oomd_sources,
                'extract' : systemd_oomd_extract_sources,
                'dependencies' : libatomic,
        },
        executable_template + {
                'name' : 'oomctl',
                'public' : true,
                'sources' : files('oomctl.c'),
        },
        test_template + {
                'sources' : files('test-oomd-util.c'),
                'objects' : ['systemd-oomd'],
                'dependencies' : libatomic,
        },
]

install_data('org.freedesktop.oom1.conf',
                install_dir : dbuspolicydir)

install_data('org.freedesktop.oom1.service',
                install_dir : dbussystemservicedir)

if install_sysconfdir_samples
        install_data('oomd.conf',
                        install_dir : pkgconfigfiledir)
endif
