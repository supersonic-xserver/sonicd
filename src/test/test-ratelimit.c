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

#include "ratelimit.h"
#include "tests.h"
#include "time-util.h"

TEST(ratelimit_below) {
        int i;
        RateLimit ratelimit = { 1 * USEC_PER_SEC, 10 };

        for (i = 0; i < 10; i++)
                assert_se(ratelimit_below(&ratelimit));
        assert_se(!ratelimit_below(&ratelimit));
        sleep(1);
        for (i = 0; i < 10; i++)
                assert_se(ratelimit_below(&ratelimit));

        ratelimit = (const RateLimit) { 0, 10 };
        for (i = 0; i < 10000; i++)
                assert_se(ratelimit_below(&ratelimit));
}

TEST(ratelimit_num_dropped) {
        int i;
        RateLimit ratelimit = { 1 * USEC_PER_SEC, 10 };

        for (i = 0; i < 10; i++) {
                assert_se(ratelimit_below(&ratelimit));
                assert_se(ratelimit_num_dropped(&ratelimit) == 0);
        }
        assert_se(!ratelimit_below(&ratelimit));
        assert_se(ratelimit_num_dropped(&ratelimit) == 1);
        assert_se(!ratelimit_below(&ratelimit));
        assert_se(ratelimit_num_dropped(&ratelimit) == 2);
        sleep(1);
        assert_se(ratelimit_below(&ratelimit));
        assert_se(ratelimit_num_dropped(&ratelimit) == 0);
}

DEFINE_TEST_MAIN(LOG_INFO);
