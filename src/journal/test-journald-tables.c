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

#include "journald-config.h"
#include "test-tables.h"
#include "tests.h"

int main(int argc, char **argv) {
        test_setup_logging(LOG_DEBUG);

        test_table(SplitMode, split_mode, SPLIT);
        test_table(Storage, storage, STORAGE);

        return EXIT_SUCCESS;
}
