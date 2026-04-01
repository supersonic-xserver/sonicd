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

#include "af-list.h"
#include "tests.h"

_unused_
static const struct af_name* lookup_af(register const char *str, register GPERF_LEN_TYPE len);

#include "af-from-name.inc"
#include "af-to-name.inc"

TEST(af_list) {
        for (unsigned i = 0; i < ELEMENTSOF(af_names); i++) {
                if (af_names[i]) {
                        ASSERT_STREQ(af_to_name(i), af_names[i]);
                        assert_se(af_from_name(af_names[i]) == (int) i);
                }
        }

        ASSERT_NULL(af_to_name(af_max()));
        ASSERT_NULL(af_to_name(0));
        ASSERT_NULL(af_to_name(-1));
        assert_se(af_from_name("huddlduddl") == -EINVAL);
        assert_se(af_from_name("") == -EINVAL);
}

DEFINE_TEST_MAIN(LOG_INFO);
