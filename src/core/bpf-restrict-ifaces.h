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

#include "core-forward.h"

int bpf_restrict_ifaces_supported(void);
int bpf_restrict_ifaces_install(Unit *u);

int bpf_restrict_ifaces_serialize(Unit *u, FILE *f, FDSet *fds);

/* Add BPF link fd created before daemon-reload or daemon-reexec.
 * FDs will be closed at the end of restrict_network_interfaces_install. */
int bpf_restrict_ifaces_add_initial_link_fd(Unit *u, int fd);
