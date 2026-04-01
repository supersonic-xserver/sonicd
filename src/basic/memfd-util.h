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

#include <sys/mman.h>           /* IWYU pragma: export */

#include "basic-forward.h"

int memfd_create_wrapper(const char *name, unsigned mode);

int memfd_new_full(const char *name, unsigned extra_flags);
static inline int memfd_new(const char *name) {
        return memfd_new_full(name, 0);
}

int memfd_new_and_seal(const char *name, const void *data, size_t sz) _nonnull_if_nonzero_(2, 3);
static inline int memfd_new_and_seal_string(const char *name, const char *s) {
        return memfd_new_and_seal(name, s, SIZE_MAX);
}

int memfd_set_sealed(int fd);
int memfd_get_sealed(int fd);

int memfd_get_size(int fd, uint64_t *ret);
int memfd_set_size(int fd, uint64_t sz);
