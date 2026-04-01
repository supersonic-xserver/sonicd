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

#include "shared-forward.h"
#include "static-destruct.h"    /* IWYU pragma: keep */

void main_prepare(int argc, char *argv[]);

void main_finalize(int r, int exit_status);

#define _DEFINE_MAIN_FUNCTION(intro, impl, result_to_exit_status)       \
        int main(int argc, char *argv[]) {                              \
                int r, s;                                               \
                main_prepare(argc, argv);                               \
                intro;                                                  \
                r = impl;                                               \
                s = result_to_exit_status(r);                           \
                main_finalize(r, s);                                    \
                static_destruct();                                      \
                return s;                                               \
        }

int exit_failure_if_negative(int result) _const_;

/* Negative return values from impl are mapped to EXIT_FAILURE, and
 * everything else means success! */
#define DEFINE_MAIN_FUNCTION(impl)                                      \
        _DEFINE_MAIN_FUNCTION(, impl(argc, argv), exit_failure_if_negative)

int exit_failure_if_nonzero(int result) _const_;

/* Zero is mapped to EXIT_SUCCESS, negative values are mapped to EXIT_FAILURE,
 * and positive values are propagated.
 * Note: "true" means failure! */
#define DEFINE_MAIN_FUNCTION_WITH_POSITIVE_FAILURE(impl)                \
        _DEFINE_MAIN_FUNCTION(, impl(argc, argv), exit_failure_if_nonzero)
