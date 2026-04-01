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
#include "mempool.h"
#include "process-util.h"

bool mempool_enabled(void) {
        static int cache = -1;

        if (!is_main_thread())
                return false;

        if (cache < 0)
                cache = getenv_bool("SYSTEMD_MEMPOOL") != 0;

        return cache;
}
