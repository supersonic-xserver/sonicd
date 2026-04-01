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
        executable_template + {
                'name' : 'systemd-run',
                'public' : true,
                'sources' : files('run.c'),
        },
]

install_symlink('run0',
                pointing_to : 'systemd-run',
                install_dir : bindir)

custom_target(
        input : 'systemd-run0.in',
        output : 'systemd-run0',
        command : [jinja2_cmdline, '@INPUT@', '@OUTPUT@'],
        install : pamconfdir != 'no',
        install_dir : pamconfdir)

if install_polkit
        install_data('empower.rules',
                     install_dir : polkitrulesdir)
endif
