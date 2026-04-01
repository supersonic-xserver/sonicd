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

if conf.get('BPF_FRAMEWORK') != 1
        subdir_done()
endif

restrict_ifaces_bpf_o_unstripped = custom_target(
        input : 'restrict-ifaces.bpf.c',
        output : 'restrict-ifaces.bpf.unstripped.o',
        command : bpf_o_unstripped_cmd)

restrict_ifaces_bpf_o = custom_target(
        input : restrict_ifaces_bpf_o_unstripped,
        output : 'restrict-ifaces.bpf.o',
        command : bpf_o_cmd)

restrict_ifaces_skel_h = custom_target(
        input : restrict_ifaces_bpf_o,
        output : 'restrict-ifaces.skel.h',
        command : skel_h_cmd,
        capture : true)

generated_sources += restrict_ifaces_skel_h
