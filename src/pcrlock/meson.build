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

if conf.get('HAVE_OPENSSL') != 1 or conf.get('HAVE_TPM2') != 1
        subdir_done()
endif

executables += [
        libexec_template + {
                'name' : 'systemd-pcrlock',
                'sources' : files(
                        'pcrlock.c',
                        'pcrlock-firmware.c',
                ),
                'dependencies' : [
                        libm,
                        libopenssl,
                        tpm2,
                ],
        },
]

install_data('pcrlock.d/350-action-efi-application.pcrlock', install_dir : pcrlockdir)
install_data('pcrlock.d/400-secureboot-separator.pcrlock.d/300-0x00000000.pcrlock', install_dir : pcrlockdir / '400-secureboot-separator.pcrlock.d')
install_data('pcrlock.d/400-secureboot-separator.pcrlock.d/600-0xffffffff.pcrlock', install_dir : pcrlockdir / '400-secureboot-separator.pcrlock.d')
install_data('pcrlock.d/500-separator.pcrlock.d/300-0x00000000.pcrlock', install_dir : pcrlockdir / '500-separator.pcrlock.d')
install_data('pcrlock.d/500-separator.pcrlock.d/600-0xffffffff.pcrlock', install_dir : pcrlockdir / '500-separator.pcrlock.d')
install_data('pcrlock.d/700-action-efi-exit-boot-services.pcrlock.d/300-present.pcrlock', install_dir : pcrlockdir / '700-action-efi-exit-boot-services.pcrlock.d')
install_data('pcrlock.d/700-action-efi-exit-boot-services.pcrlock.d/600-absent.pcrlock', install_dir : pcrlockdir / '700-action-efi-exit-boot-services.pcrlock.d')
install_data('pcrlock.d/750-enter-initrd.pcrlock', install_dir : pcrlockdir)
install_data('pcrlock.d/750-os-separator.pcrlock', install_dir : pcrlockdir)
install_data('pcrlock.d/770-nvpcr-separator.pcrlock', install_dir : pcrlockdir)
install_data('pcrlock.d/800-leave-initrd.pcrlock', install_dir : pcrlockdir)
install_data('pcrlock.d/850-sysinit.pcrlock', install_dir : pcrlockdir)
install_data('pcrlock.d/900-ready.pcrlock', install_dir : pcrlockdir)
install_data('pcrlock.d/950-shutdown.pcrlock', install_dir : pcrlockdir)
install_data('pcrlock.d/990-final.pcrlock', install_dir : pcrlockdir)
