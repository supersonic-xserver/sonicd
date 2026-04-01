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

libc_wrapper_sources = files(
        'bpf.c',
        'ioprio.c',
        'kcmp.c',
        'keyctl.c',
        'mempolicy.c',
        'mount.c',
        'pidfd.c',
        'quota.c',
        'sched.c',
        'signal.c',
        'stat.c',
        'unistd.c',
        'xattr.c',
)

subdir('musl')

sources += libc_wrapper_sources

libc_wrapper_static = static_library(
        'c-wrapper',
        libc_wrapper_sources,
        include_directories : system_includes,
        implicit_include_directories : false,
        dependencies : [userspace],
        c_args : ['-fvisibility=default'],
        build_by_default : false)
