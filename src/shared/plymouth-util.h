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

#include "errno-util.h"
#include "shared-forward.h"

int plymouth_connect(int flags);
int plymouth_send_raw(const void *raw, size_t size, int flags);
int plymouth_send_msg(const char *text, bool pause_spinner);
int plymouth_hide_splash(void);

static inline bool ERRNO_IS_NO_PLYMOUTH(int r) {
        return IN_SET(ABS(r), EAGAIN, ENOENT) || ERRNO_IS_DISCONNECT(r);
}
