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

#include <linux/securebits.h>

#include "shared-forward.h"

int secure_bits_to_strv(int i, char ***ret);
DECLARE_STRING_TABLE_LOOKUP_WITH_FALLBACK(secure_bits, int);

static inline bool secure_bits_is_valid(int i) {
        return ((SECURE_ALL_BITS | SECURE_ALL_LOCKS) & i) == i;
}

static inline int secure_bits_to_string_alloc_with_check(int n, char **s) {
        if (!secure_bits_is_valid(n))
                return -EINVAL;

        return secure_bits_to_string_alloc(n, s);
}
