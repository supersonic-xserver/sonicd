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

int bpf_firewall_compile(Unit *u);
int bpf_firewall_install(Unit *u);
int bpf_firewall_load_custom(Unit *u);

int bpf_firewall_read_accounting(int map_fd, uint64_t *ret_bytes, uint64_t *ret_packets);
int bpf_firewall_reset_accounting(int map_fd);

void emit_bpf_firewall_warning(Unit *u);

void bpf_firewall_close(CGroupRuntime *crt);
