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

factory_etc_dir = factorydir / 'etc'

custom_target(
        input : 'locale.conf.in',
        output : 'locale.conf',
        command : [jinja2_cmdline, '@INPUT@', '@OUTPUT@'],
        install : true,
        install_dir : factory_etc_dir)

custom_target(
        input : 'vconsole.conf.in',
        output : 'vconsole.conf',
        command : [jinja2_cmdline, '@INPUT@', '@OUTPUT@'],
        install : true,
        install_dir : factory_etc_dir)

if conf.get('ENABLE_NSS') == 1
        install_data(
                'nsswitch.conf',
                install_dir : factory_etc_dir)
endif
