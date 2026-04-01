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

#include <openssl/evp.h>

#include "shared-forward.h"

int user_record_sign(UserRecord *ur, EVP_PKEY *private_key, UserRecord **ret);

enum {
        USER_RECORD_UNSIGNED,           /* user record has no signature */
        USER_RECORD_SIGNED_EXCLUSIVE,   /* user record has only a signature by our own key */
        USER_RECORD_SIGNED,             /* user record is signed by us, but by others too */
        USER_RECORD_FOREIGN,            /* user record is not signed by us, but by others */
};

int user_record_verify(UserRecord *ur, EVP_PKEY *public_key);

int user_record_has_signature(UserRecord *ur);
