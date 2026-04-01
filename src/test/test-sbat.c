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

/* We include efi-config.h after undefining PROJECT_VERSION which is also defined in config.h. */
#undef PROJECT_VERSION
#include "efi-config.h"
#include "sbat.h"
#include "tests.h"

TEST(BOOT_SBAT) {
        log_info("---SBAT-----------&<-----------------------------------------\n"
                 "%s"
                 "------------------>&-----------------------------------------",
#ifdef SBAT_DISTRO
                 SBAT_BOOT_SECTION_TEXT
#else
                 "(not defined)"
#endif
        );
}

TEST(STUB_SBAT) {
        log_info("---SBAT-----------&<-----------------------------------------\n"
                 "%s"
                 "------------------>&-----------------------------------------",
#ifdef SBAT_DISTRO
                 SBAT_STUB_SECTION_TEXT
#else
                 "(not defined)"
#endif
        );
}

DEFINE_TEST_MAIN(LOG_INFO);
