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

#if ENABLE_UTMP
#include <utmpx.h>

int utmp_put_shutdown(void);
int utmp_put_reboot(usec_t timestamp);

int utmp_put_dead_process(const char *id, pid_t pid, int code, int status);
int utmp_put_init_process(const char *id, pid_t pid, pid_t sid, const char *line, int ut_type, const char *user);

static inline bool utxent_start(void) {
        setutxent();
        return true;
}
static inline void utxent_cleanup(bool *initialized) {
        assert(initialized);
        if (*initialized)
                endutxent();
}

#else /* ENABLE_UTMP */

static inline int utmp_put_shutdown(void) {
        return 0;
}
static inline int utmp_put_reboot(usec_t timestamp) {
        return 0;
}
static inline int utmp_put_dead_process(const char *id, pid_t pid, int code, int status) {
        return 0;
}
static inline int utmp_put_init_process(const char *id, pid_t pid, pid_t sid, const char *line, int ut_type, const char *user) {
        return 0;
}

#endif /* ENABLE_UTMP */
