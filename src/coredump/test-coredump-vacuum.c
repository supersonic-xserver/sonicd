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

#include "coredump-vacuum.h"
#include "tests.h"

int main(int argc, char *argv[]) {
        test_setup_logging(LOG_DEBUG);

        if (coredump_vacuum(-1, UINT64_MAX, 70 * 1024) < 0)
                return EXIT_FAILURE;

        return EXIT_SUCCESS;
}
