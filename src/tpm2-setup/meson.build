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
                'name' : 'systemd-tpm2-setup',
                'sources' : files('tpm2-setup.c'),
                'conditions' : [
                        'ENABLE_BOOTLOADER',
                        'HAVE_OPENSSL',
                        'HAVE_TPM2',
                ],
                'dependencies' : [
                        libopenssl,
                ],
        },
        libexec_template + {
                'name' : 'systemd-tpm2-clear',
                'sources' : files('tpm2-clear.c'),
                'conditions' : [
                        'ENABLE_BOOTLOADER',
                        'HAVE_OPENSSL',
                        'HAVE_TPM2',
                ],
        },
        libexec_template + {
                'name' : 'systemd-tpm2-swtpm',
                'sources' : files('tpm2-swtpm.c'),
                'conditions' : [
                        'ENABLE_BOOTLOADER',
                        'HAVE_OPENSSL',
                        'HAVE_TPM2',
                ],
        },
        generator_template + {
                'name' : 'systemd-tpm2-generator',
                'sources' : files('tpm2-generator.c'),
                'conditions' : [
                        'ENABLE_BOOTLOADER',
                        'HAVE_OPENSSL',
                        'HAVE_TPM2',
                ],
        },
]

if conf.get('ENABLE_BOOTLOADER') == 1 and conf.get('HAVE_OPENSSL') == 1 and conf.get('HAVE_TPM2') == 1
        nvpcrs = [ 'cryptsetup',
                   'hardware',
                   'verity']
        foreach n : nvpcrs
                custom_target(
                        input : 'nvpcr/' + n + '.nvpcr.in',
                        output : n + '.nvpcr',
                        command : [jinja2_cmdline, '@INPUT@', '@OUTPUT@'],
                        install : true,
                        install_dir : prefixdir / 'lib/nvpcr')
        endforeach
endif
