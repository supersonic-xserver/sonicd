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

#if HAVE_LIBCRYPT
int dlopen_libcrypt(void);
int make_salt(char **ret);
int hash_password(const char *password, char **ret);
int test_password_one(const char *hashed_password, const char *password);
int test_password_many(char **hashed_password, const char *password);

#else

static inline int dlopen_libcrypt(void) {
        return -EOPNOTSUPP;
}
static inline int hash_password(const char *password, char **ret) {
        return -EOPNOTSUPP;
}
#endif

bool looks_like_hashed_password(const char *s);
