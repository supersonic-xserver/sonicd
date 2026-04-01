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

#include "shared-forward.h"

int dlopen_libaudit(void);

#if HAVE_AUDIT
#  include <libaudit.h>         /* IWYU pragma: export */

#  include "dlfcn-util.h"

extern DLSYM_PROTOTYPE(audit_log_acct_message);
extern DLSYM_PROTOTYPE(audit_log_user_avc_message);
extern DLSYM_PROTOTYPE(audit_log_user_comm_message);
#endif

bool use_audit(void);

int close_audit_fd(int fd);
int open_audit_fd_or_warn(void);
