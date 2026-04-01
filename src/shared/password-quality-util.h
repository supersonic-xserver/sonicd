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

#define N_SUGGESTIONS 6

#if HAVE_PASSWDQC

#include "password-quality-util-passwdqc.h" /* IWYU pragma: export */

#elif HAVE_PWQUALITY

#include "password-quality-util-pwquality.h" /* IWYU pragma: export */

#else

static inline int suggest_passwords(void) {
        return 0;
}

static inline int check_password_quality(
                const char *password,
                const char *old,
                const char *username,
                char **ret_error) {
        if (ret_error)
                *ret_error = NULL;
        return 1; /* all good */
}

#endif
