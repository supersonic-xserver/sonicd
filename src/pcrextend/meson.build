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

executables += [
        libexec_template + {
                'name' : 'systemd-pcrextend',
                'conditions' : [
                        'HAVE_BLKID',
                        'ENABLE_BOOTLOADER',
                        'HAVE_OPENSSL',
                        'HAVE_TPM2',
                ],
                'sources' : files('pcrextend.c'),
                'dependencies' : [
                        libopenssl,
                        tpm2,
                ],
        },
]
