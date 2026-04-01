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

#include "audit-fd.h"
#include "capability-util.h"
#include "libaudit-util.h"

static bool initialized = false;
static int audit_fd = -EBADF;

int get_core_audit_fd(void) {
        if (!initialized) {
                if (have_effective_cap(CAP_AUDIT_WRITE) <= 0)
                        audit_fd = -EPERM;
                else
                        audit_fd = open_audit_fd_or_warn();

                initialized = true;
        }

        return audit_fd;
}

void close_core_audit_fd(void) {
        close_audit_fd(audit_fd);
        initialized = true;
        audit_fd = -ECONNRESET;
}
