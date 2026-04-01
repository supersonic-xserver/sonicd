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

#define DECLARE_STRING_TABLE_LOOKUP_TO_STRING(name, type) \
        const char* name##_to_string(type i) _const_

#define DECLARE_STRING_TABLE_LOOKUP_FROM_STRING(name, type) \
        type name##_from_string(const char *s) _pure_

#define DECLARE_STRING_TABLE_LOOKUP(name, type) \
        DECLARE_STRING_TABLE_LOOKUP_TO_STRING(name, type); \
        DECLARE_STRING_TABLE_LOOKUP_FROM_STRING(name, type)

#define DECLARE_STRING_TABLE_LOOKUP_TO_STRING_FALLBACK(name, type) \
        int name##_to_string_alloc(type i, char **ret)

#define DECLARE_STRING_TABLE_LOOKUP_WITH_FALLBACK(name, type) \
        DECLARE_STRING_TABLE_LOOKUP_TO_STRING_FALLBACK(name, type); \
        DECLARE_STRING_TABLE_LOOKUP_FROM_STRING(name, type)
