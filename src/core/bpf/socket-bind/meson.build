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

socket_bind_bpf_o_unstripped = custom_target(
        input : 'socket-bind.bpf.c',
        output : 'socket-bind.bpf.unstripped.o',
        command : bpf_o_unstripped_cmd)

socket_bind_bpf_o = custom_target(
        input : socket_bind_bpf_o_unstripped,
        output : 'socket-bind.bpf.o',
        command : bpf_o_cmd)

socket_bind_skel_h = custom_target(
        input : socket_bind_bpf_o,
        output : 'socket-bind.skel.h',
        command : skel_h_cmd,
        capture : true)

generated_sources += socket_bind_skel_h
