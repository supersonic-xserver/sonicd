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

#include "gunicode.h"
#include "tests.h"
#include "utf8.h"

TEST(unichar_iswide) {
        char32_t c;
        int r;

        /* FIXME: the cats are wide, but we get this wrong */
        for (const char *narrow = "abX_…ąęµ!" "😼😿🙀😸😻"; *narrow; narrow += r) {
                r = utf8_encoded_to_unichar(narrow, &c);
                bool w = unichar_iswide(c);
                assert_se(r > 0);
                assert_se(!w);
        }

        for (const char *wide = "🐱／￥"; *wide; wide += r) {
                r = utf8_encoded_to_unichar(wide, &c);
                bool w = unichar_iswide(c);
                assert_se(r > 0);
                assert_se(w);
        }
}

DEFINE_TEST_MAIN(LOG_INFO);
