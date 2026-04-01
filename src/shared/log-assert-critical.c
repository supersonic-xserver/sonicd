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

#include "env-util.h"
#include "log.h"
#include "log-assert-critical.h"

static bool assert_return_is_critical = BUILD_MODE_DEVELOPER;

void log_set_assert_return_is_critical(bool b) {
        assert_return_is_critical = b;
}

void log_set_assert_return_is_critical_from_env(void) {
        static int cached = INT_MIN;
        int r;

        if (cached == INT_MIN) {
                r = secure_getenv_bool("SYSTEMD_ASSERT_RETURN_IS_CRITICAL");
                if (r < 0 && r != -ENXIO)
                        log_debug_errno(r, "Failed to parse $SYSTEMD_ASSERT_RETURN_IS_CRITICAL, ignoring: %m");

                cached = r;
        }

        if (cached >= 0)
                log_set_assert_return_is_critical(cached);
}

bool log_get_assert_return_is_critical(void) {
        return assert_return_is_critical;
}
