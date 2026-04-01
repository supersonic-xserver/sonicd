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

#if HAVE_P11KIT
#include "homework-forward.h"
#include "pkcs11-util.h"

struct pkcs11_callback_data {
        UserRecord *user_record;
        UserRecord *secret;
        Pkcs11EncryptedKey *encrypted_key;
        char *decrypted_password;
};

void pkcs11_callback_data_release(struct pkcs11_callback_data *data);

int pkcs11_callback(CK_FUNCTION_LIST *m, CK_SESSION_HANDLE session, CK_SLOT_ID slot_id, const CK_SLOT_INFO *slot_info, const CK_TOKEN_INFO *token_info, P11KitUri *uri, void *userdata);
#endif
