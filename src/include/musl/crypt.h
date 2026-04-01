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

#include_next <crypt.h>

const char* missing_crypt_preferred_method(void);
#define crypt_preferred_method missing_crypt_preferred_method

char* missing_crypt_gensalt_ra(const char *prefix, unsigned long count, const char *rbytes, int nrbytes);
#define crypt_gensalt_ra missing_crypt_gensalt_ra

char* missing_crypt_ra(const char *phrase, const char *setting, void **data, int *size);
#define crypt_ra missing_crypt_ra
