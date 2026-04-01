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

install_data('90-systemd.preset',
             install_dir : systempresetdir)

install_data('90-systemd-user.preset',
             install_dir : userpresetdir,
             rename : '90-systemd.preset')

install_data('90-systemd-initrd.preset',
             install_dir : initrdpresetdir,
             rename : '90-systemd.preset')

install_data('99-default-initrd.preset',
             install_dir : initrdpresetdir,
             rename : '99-default.preset')
