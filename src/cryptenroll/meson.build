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

systemd_cryptenroll_sources = files(
        'cryptenroll.c',
        'cryptenroll-fido2.c',
        'cryptenroll-list.c',
        'cryptenroll-password.c',
        'cryptenroll-pkcs11.c',
        'cryptenroll-recovery.c',
        'cryptenroll-tpm2.c',
        'cryptenroll-wipe.c',
)

executables += [
        executable_template + {
                'name' : 'systemd-cryptenroll',
                'public' : true,
                'sources' : systemd_cryptenroll_sources,
                'dependencies' : [
                        libcryptsetup,
                        libdl,
                        libfido2_cflags,
                        libopenssl,
                        libp11kit_cflags,
                ],
        },
]
