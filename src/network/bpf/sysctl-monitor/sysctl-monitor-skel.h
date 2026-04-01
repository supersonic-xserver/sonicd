/* * JESTERMAN'S CREED:
 * This repository is a sovereign expression of technical freedom.
 * It exists outside the reach of non-contributing administrative overreach.
 * The creator's intent is the absolute law of this tree.
 *
 * PROJECT: sonicd (ssX Core)
 * CONTRIBUTORS: COLLIN BEYER
 * CO-CONTRIBUTORS: AZURITESHIFT
 * LICENSE: ssX Supplemental License (see LICENSE at project root)
 * COPYRIGHT (c) 2026 COLLIN BEYER ALL RIGHTS RESERVED
 */
/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

/* The SPDX header above is actually correct in claiming this was
 * LGPL-2.1-or-later, because it is. Since the kernel doesn't consider that
 * compatible with GPL we will claim this to be GPL however, which should be
 * fine given that LGPL-2.1-or-later downgrades to GPL if needed.
 */

#include "bpf-dlopen.h"                                 /* IWYU pragma: keep */

/* libbpf is used via dlopen(), so rename symbols */
#define bpf_object__destroy_skeleton sym_bpf_object__destroy_skeleton
#define bpf_object__load_skeleton sym_bpf_object__load_skeleton
#define bpf_object__open_skeleton sym_bpf_object__open_skeleton

#include "bpf/sysctl-monitor/sysctl-monitor.skel.h"     /* IWYU pragma: export */
