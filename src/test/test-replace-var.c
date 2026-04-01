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

#include <stdio.h>

#include "replace-var.h"
#include "string-util.h"
#include "tests.h"

static char *lookup(const char *variable, void *userdata) {
        return strjoin("<<<", variable, ">>>");
}

TEST(replace_var) {
        char *r;

        assert_se(r = replace_var("@@@foobar@xyz@HALLO@foobar@test@@testtest@TEST@...@@@", lookup, NULL));
        puts(r);
        ASSERT_STREQ(r, "@@@foobar@xyz<<<HALLO>>>foobar@test@@testtest<<<TEST>>>...@@@");
        free(r);
}

TEST(strreplace) {
        char *r;

        assert_se(r = strreplace("XYZFFFFXYZFFFFXYZ", "XYZ", "ABC"));
        puts(r);
        ASSERT_STREQ(r, "ABCFFFFABCFFFFABC");
        free(r);
}

DEFINE_TEST_MAIN(LOG_INFO);
