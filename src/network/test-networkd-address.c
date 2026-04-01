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

#include "networkd-address.h"
#include "tests.h"
#include "time-util.h"

static void test_FORMAT_LIFETIME_one(usec_t lifetime, const char *expected) {
        const char *t = FORMAT_LIFETIME(lifetime);

        log_debug(USEC_FMT " → \"%s\" (expected \"%s\")", lifetime, t, strna(expected));
        if (expected)
                ASSERT_STREQ(t, expected);
}

TEST(FORMAT_LIFETIME) {
        usec_t now_usec;

        now_usec = now(CLOCK_BOOTTIME);

        test_FORMAT_LIFETIME_one(now_usec, "for 0");
        test_FORMAT_LIFETIME_one(USEC_INFINITY, "forever");

        /* These two are necessarily racy, especially for slow test environment. */
        test_FORMAT_LIFETIME_one(usec_add(now_usec, 2 * USEC_PER_SEC - 1), NULL);
        test_FORMAT_LIFETIME_one(usec_add(now_usec, 3 * USEC_PER_WEEK + USEC_PER_SEC - 1), NULL);
}

DEFINE_TEST_MAIN(LOG_DEBUG);
