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

#include <sys/uio.h>

int pcrextend_file_system_word(const char *path, char **ret, char **ret_normalized_path);
int pcrextend_machine_id_word(char **ret);
int pcrextend_product_id_word(char **ret);
int pcrextend_verity_word(const char *name, const struct iovec *root_hash, const struct iovec *root_hash_sig, char **ret);
int pcrextend_imds_userdata_word(const struct iovec *data, char **ret);

int pcrextend_verity_now(const char *name, const struct iovec *root_hash, const struct iovec *root_hash_sig);
int pcrextend_imds_userdata_now(const struct iovec *data);
