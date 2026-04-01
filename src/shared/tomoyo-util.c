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

#include <unistd.h>

#include "tomoyo-util.h"

bool mac_tomoyo_use(void) {
        static int cached_use = -1;

        if (cached_use < 0)
                cached_use = (access("/sys/kernel/security/tomoyo/version",
                                     F_OK) == 0);

        return cached_use;
}
