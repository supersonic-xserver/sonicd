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

#include <sys/mempolicy.h>

#include "cpu-set-util.h"
#include "shared-forward.h"

static inline bool mpol_is_valid(int t) {
        return t >= MPOL_DEFAULT && t <= MPOL_LOCAL;
}

typedef struct NUMAPolicy {
        /* Always use numa_policy_get_type() to read the value */
        int type;
        CPUSet nodes;
} NUMAPolicy;

bool numa_policy_is_valid(const NUMAPolicy *p);

static inline int numa_policy_get_type(const NUMAPolicy *p) {
        return p->type < 0 ? (p->nodes.set ? MPOL_PREFERRED : -1) : p->type;
}

static inline void numa_policy_reset(NUMAPolicy *p) {
        assert(p);
        cpu_set_done(&p->nodes);
        p->type = -1;
}

int apply_numa_policy(const NUMAPolicy *policy);
int numa_to_cpu_set(const NUMAPolicy *policy, CPUSet *ret);

int numa_mask_add_all(CPUSet *mask);

DECLARE_STRING_TABLE_LOOKUP(mpol, int);
