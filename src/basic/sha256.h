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

#include "basic-forward.h"
#include "sha256-fundamental.h" /* IWYU pragma: export */

int sha256_fd(int fd, uint64_t max_size, uint8_t ret[static SHA256_DIGEST_SIZE]);

int parse_sha256(const char *s, uint8_t ret[static SHA256_DIGEST_SIZE]);

bool sha256_is_valid(const char *s) _pure_;
