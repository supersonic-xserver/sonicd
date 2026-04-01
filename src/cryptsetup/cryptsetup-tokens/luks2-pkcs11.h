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

int acquire_luks2_key(
                struct crypt_device *cd,
                const char *json,
                void *userdata,
                const void *pin,
                size_t pin_size,
                char **password,
                size_t *password_size);

int parse_luks2_pkcs11_data(
                struct crypt_device *cd,
                const char *json,
                char **ret_uri,
                void **ret_encrypted_key,
                size_t *ret_encrypted_key_size);
