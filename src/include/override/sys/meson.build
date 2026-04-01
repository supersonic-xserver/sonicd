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

arch_list = [
        'alpha',
        'arc',
        'arm',
        'arm64',
        'i386',
        'ia64',
        'loongarch64',
        'm68k',
        'mips64',
        'mips64n32',
        'mipso32',
        'parisc',
        'powerpc',
        'powerpc64',
        'riscv32',
        'riscv64',
        'sh',
        's390',
        's390x',
        'sparc',
        'x86_64'
]

run_target(
        'update-syscall-tables',
        command : [update_syscall_tables_sh, meson.current_source_dir()] + arch_list)

syscall_list_txt = files('syscall-list.txt')

syscall_lists = []
foreach arch: arch_list
        # We don't use files() here so that the 'update-syscall-tables' call
        # above can run if arch_list is extended.
        syscall_lists += meson.current_source_dir() / f'syscalls-@arch@.txt'
endforeach

run_target(
        'update-syscall-header',
        command : [files('generate-syscall.py'),
                   files('syscall.h'),
                   syscall_lists])
