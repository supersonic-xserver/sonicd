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
#include "shift-uid.h"
#include "tests.h"
#include "user-util.h"

int main(int argc, char *argv[]) {
        uid_t shift, range;
        int r;

        test_setup_logging(LOG_DEBUG);

        if (argc != 4) {
                log_error("Expected PATH SHIFT RANGE parameters.");
                return EXIT_FAILURE;
        }

        r = parse_uid(argv[2], &shift);
        if (r < 0) {
                log_error_errno(r, "Failed to parse UID shift %s.", argv[2]);
                return EXIT_FAILURE;
        }

        r = parse_gid(argv[3], &range);
        if (r < 0) {
                log_error_errno(r, "Failed to parse UID range %s.", argv[3]);
                return EXIT_FAILURE;
        }

        r = path_patch_uid(argv[1], shift, range);
        if (r < 0) {
                log_error_errno(r, "Failed to patch directory tree: %m");
                return EXIT_FAILURE;
        }

        log_info("Changed: %s", yes_no(r));

        return EXIT_SUCCESS;
}
