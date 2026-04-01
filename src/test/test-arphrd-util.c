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

#include <linux/if_arp.h>

#include "arphrd-util.h"
#include "tests.h"

TEST(arphrd) {
        for (int i = 0; i <= ARPHRD_VOID + 1; i++) {
                const char *name;

                name = arphrd_to_name(i);
                if (name) {
                        log_info("%i: %s", i, name);

                        ASSERT_EQ(arphrd_from_name(name), i);
                }
        }

        ASSERT_NULL(arphrd_to_name(ARPHRD_VOID + 1));
        assert_se(arphrd_from_name("huddlduddl") == -EINVAL);
        assert_se(arphrd_from_name("") == -EINVAL);
}

DEFINE_TEST_MAIN(LOG_INFO);
