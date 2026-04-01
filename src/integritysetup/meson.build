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

if conf.get('HAVE_LIBCRYPTSETUP') != 1
        subdir_done()
endif

executables += [
        libexec_template + {
                'name' : 'systemd-integritysetup',
                'sources' : files('integritysetup.c'),
                'extract' : files('integrity-util.c'),
                'dependencies' : libcryptsetup,
        },
        generator_template + {
                'name' : 'systemd-integritysetup-generator',
                'sources' : files('integritysetup-generator.c'),
                'objects' : ['systemd-integritysetup'],
        },
]
