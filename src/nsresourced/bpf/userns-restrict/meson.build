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

if conf.get('HAVE_VMLINUX_H') != 1
        subdir_done()
endif

userns_restrict_bpf_o_unstripped = custom_target(
        input : 'userns-restrict.bpf.c',
        output : 'userns-restrict.bpf.unstripped.o',
        command : bpf_o_unstripped_cmd,
        depends : vmlinux_h_dependency)

userns_restrict_bpf_o = custom_target(
        input : userns_restrict_bpf_o_unstripped,
        output : 'userns-restrict.bpf.o',
        command : bpf_o_cmd)

userns_restrict_skel_h = custom_target(
        input : userns_restrict_bpf_o,
        output : 'userns-restrict.skel.h',
        command : skel_h_cmd,
        capture : true)

generated_sources += userns_restrict_skel_h
