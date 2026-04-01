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

#include "macro-fundamental.h"
#include "string-util-fundamental.h"

#define _STRV_FOREACH(s, l, i)                                          \
        for (typeof(*(l)) *s, *i = (l); (s = i) && *i; i++)

#define STRV_FOREACH(s, l)                      \
        _STRV_FOREACH(s, l, UNIQ_T(i, UNIQ))

static inline bool strv_isempty(sd_char * const *l) {
        return !l || !*l;
}
