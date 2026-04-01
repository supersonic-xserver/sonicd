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

#include "homework-forward.h"

int home_setup_fscrypt(UserRecord *h, HomeSetup *setup, const PasswordCache *cache);

int home_create_fscrypt(UserRecord *h, HomeSetup *setup, char **effective_passwords, UserRecord **ret_home);

int home_passwd_fscrypt(UserRecord *h, HomeSetup *setup, const PasswordCache *cache, char **effective_passwords);

int home_flush_keyring_fscrypt(UserRecord *h);
