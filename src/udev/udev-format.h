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
/* SPDX-License-Identifier: GPL-2.0-or-later */
#pragma once

#include "udev-forward.h"

#define UDEV_ALLOWED_CHARS_INPUT        "/ $%?,"

size_t udev_event_apply_format(
                UdevEvent *event,
                const char *src,
                char *dest,
                size_t size,
                bool replace_whitespace,
                bool *ret_truncated);
int udev_check_format(const char *value, size_t *offset, const char **hint);

int udev_resolve_subsys_kernel(const char *string, char *result, size_t maxsize, bool read_value);
