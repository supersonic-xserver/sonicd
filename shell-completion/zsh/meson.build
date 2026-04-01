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

zshcompletiondir = get_option('zshcompletiondir')
if zshcompletiondir == 'no'
        subdir_done()
elif zshcompletiondir == ''
        zshcompletiondir = datadir / 'zsh/site-functions'
endif

custom_target(
        input : '_systemctl.in',
        output : '_systemctl',
        command : [jinja2_cmdline, '@INPUT@', '@OUTPUT@'],
        install : true,
        install_dir : zshcompletiondir)

foreach item : [
        ['_bootctl',                  ''],
        ['_busctl',                   ''],
        ['_coredumpctl',              'ENABLE_COREDUMP'],
        ['_hostnamectl',              'ENABLE_HOSTNAMED'],
        ['_journalctl',               ''],
        ['_kernel-install',           'ENABLE_KERNEL_INSTALL'],
        ['_localectl',                'ENABLE_LOCALED'],
        ['_loginctl',                 'ENABLE_LOGIND'],
        ['_machinectl',               'ENABLE_MACHINED'],
        ['_networkctl',               'ENABLE_NETWORKD'],
        ['_oomctl',                   'ENABLE_OOMD'],
        ['_resolvectl',               'ENABLE_RESOLVE'],
        ['_run0',                     ''],
        ['_sd_bus_address',           ''],
        ['_sd_hosts_or_user_at_host', ''],
        ['_sd_machines',              'ENABLE_MACHINED'],
        ['_sd_outputmodes',           ''],
        ['_sd_unit_files',            ''],
        ['_systemd',                  ''],
        ['_systemd-analyze',          ''],
        ['_systemd-delta',            ''],
        ['_systemd-hwdb',             'ENABLE_HWDB'],
        ['_systemd-id128',            ''],
        ['_systemd-inhibit',          'ENABLE_LOGIND'],
        ['_systemd-nspawn',           ''],
        ['_systemd-path',             ''],
        ['_systemd-run',              ''],
        ['_systemd-tmpfiles',         'ENABLE_TMPFILES'],
        ['_timedatectl',              'ENABLE_TIMEDATED'],
        ['_udevadm',                  ''],
        ['_userdbctl',                ''],
        ['_varlinkctl',               ''],
]

        if item[1] == '' or conf.get(item[1]) == 1
                install_data(item[0],
                             install_dir : zshcompletiondir)
        endif
endforeach
