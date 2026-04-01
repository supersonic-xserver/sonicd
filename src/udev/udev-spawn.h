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

#define READ_END  0
#define WRITE_END 1

int udev_event_spawn(
                UdevEvent *event,
                bool accept_failure,
                const char *cmd,
                char *result,
                size_t result_size,
                bool *ret_truncated);
void udev_event_execute_run(UdevEvent *event);

static inline usec_t udev_warn_timeout(usec_t timeout_usec) {
        if (timeout_usec == USEC_INFINITY)
                return USEC_INFINITY;

        return DIV_ROUND_UP(timeout_usec, 3);
}
