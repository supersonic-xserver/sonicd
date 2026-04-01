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

in_files = [
        'systemd.be.catalog',
        'systemd.be@latin.catalog',
        'systemd.bg.catalog',
        'systemd.catalog',
        'systemd.da.catalog',
        'systemd.de.catalog',
        'systemd.fr.catalog',
        'systemd.hr.catalog',
        'systemd.hu.catalog',
        'systemd.it.catalog',
        'systemd.ko.catalog',
        'systemd.pl.catalog',
        'systemd.pt_BR.catalog',
        'systemd.ru.catalog',
        'systemd.sr.catalog',
        'systemd.zh_CN.catalog',
        'systemd.zh_TW.catalog',
]

support_url = get_option('support-url')
support_sed = f's~%SUPPORT_URL%~@support_url@~'

foreach file : in_files
        catalogs += custom_target(
                input : file + '.in',
                output: file,
                command : [sed, support_sed, '@INPUT@'],
                capture : true,
                install : true,
                install_dir : catalogdir)
endforeach

meson.add_install_script(sh, '-c',
                         f'test -n "$DESTDIR" || @bindir@/journalctl --update-catalog')
