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

#include "tests.h"
#include "oci-util.h"

static void test_urlescape_one(const char *s, const char *expected) {
        _cleanup_free_ char *t = ASSERT_PTR(urlescape(s));

        ASSERT_STREQ(t, expected);
}

TEST(urlescape) {
        test_urlescape_one(NULL, "");
        test_urlescape_one("", "");
        test_urlescape_one("a", "a");
        test_urlescape_one(" ", "%20");
        test_urlescape_one("     ", "%20%20%20%20%20");
        test_urlescape_one("foo\tfoo\aqux", "foo%09foo%07qux");
        test_urlescape_one("müffel", "m%c3%bcffel");
}

DEFINE_TEST_MAIN(LOG_DEBUG);
