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

#define AUDIT_SESSION_INVALID UINT32_MAX

int audit_session_from_pid(const PidRef *pid, uint32_t *ret_id);
int audit_loginuid_from_pid(const PidRef *pid, uid_t *ret_uid);

static inline bool audit_session_is_valid(uint32_t id) {
        return id > 0 && id != AUDIT_SESSION_INVALID;
}
