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

#include "basic-forward.h"

int procfs_get_pid_max(uint64_t *ret);
int procfs_get_threads_max(uint64_t *ret);

int procfs_tasks_set_limit(uint64_t limit);
int procfs_tasks_get_current(uint64_t *ret);

int procfs_cpu_get_usage(nsec_t *ret);

int procfs_memory_get(uint64_t *ret_total, uint64_t *ret_used);
static inline int procfs_memory_get_used(uint64_t *ret) {
        return procfs_memory_get(NULL, ret);
}

int convert_meminfo_value_to_uint64_bytes(const char *s, uint64_t *ret);
