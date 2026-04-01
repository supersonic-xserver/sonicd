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

#include "log.h"
#include "main-func.h"
#include "time-util.h"

static int run(int argc, char *argv[]) {
        usec_t usec = USEC_INFINITY;
        int r;

        if (argc > 1) {
                r = parse_sec(argv[1], &usec);
                if (r < 0)
                        return log_error_errno(r, "Failed to parse timespan '%s': %m", argv[1]);
        }

        r = usleep_safe(usec);
        if (r < 0)
                return log_error_errno(r, "Failed to sleep: %m");

        return 0;
}

DEFINE_MAIN_FUNCTION(run);
