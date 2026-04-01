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

#include <stdio.h>      /* IWYU pragma: keep */

#include "sd-forward.h"

#include "alloc-util.h" /* IWYU pragma: keep */

DECLARE_STRING_TABLE_LOOKUP(audit_type, int);

/* This is inspired by DNS TYPEnnn formatting */
#define audit_type_name_alloca(type)                                    \
        ({                                                              \
                const char *_s_;                                        \
                _s_ = audit_type_to_string(type);                       \
                if (!_s_) {                                             \
                        _s_ = newa(char, STRLEN("AUDIT") + DECIMAL_STR_MAX(int)); \
                        sprintf((char*) _s_, "AUDIT%04i", type);        \
                }                                                       \
                _s_;                                                    \
        })
