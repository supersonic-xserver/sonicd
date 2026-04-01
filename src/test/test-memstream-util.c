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

#include "memstream-util.h"
#include "tests.h"

TEST(memstream_done) {
        _cleanup_(memstream_done) MemStream m = {};

        ASSERT_NOT_NULL(memstream_init(&m));
}

TEST(memstream_empty) {
        _cleanup_(memstream_done) MemStream m = {};
        _cleanup_free_ char *buf = NULL;
        size_t sz;

        ASSERT_NOT_NULL(memstream_init(&m));
        ASSERT_OK(memstream_finalize(&m, &buf, &sz));
        ASSERT_STREQ(buf, "");
        ASSERT_EQ(sz, 0u);
}

TEST(memstream) {
        _cleanup_(memstream_done) MemStream m = {};
        _cleanup_free_ char *buf = NULL;
        size_t sz;
        FILE *f;

        ASSERT_NOT_NULL(f = memstream_init(&m));
        fputs("hoge", f);
        fputs("おはよう！", f);
        fputs(UTF8("😀😀😀"), f);
        ASSERT_OK(memstream_finalize(&m, &buf, &sz));
        ASSERT_STREQ(buf, UTF8("hogeおはよう！😀😀😀"));
        ASSERT_EQ(sz, strlen(UTF8("hogeおはよう！😀😀😀")));

        buf = mfree(buf);

        ASSERT_NOT_NULL(f = memstream_init(&m));
        fputs("second", f);
        ASSERT_OK(memstream_finalize(&m, &buf, &sz));
        ASSERT_STREQ(buf, "second");
        ASSERT_EQ(sz, strlen("second"));
}

TEST(memstream_dump) {
        _cleanup_(memstream_done) MemStream m = {};
        FILE *f;

        ASSERT_NOT_NULL(f = memstream_init(&m));
        fputs("first", f);
        ASSERT_OK(memstream_dump(LOG_DEBUG, &m));

        ASSERT_NOT_NULL(f = memstream_init(&m));
        fputs("second", f);
        ASSERT_OK(memstream_dump(LOG_DEBUG, &m));
}

DEFINE_TEST_MAIN(LOG_DEBUG);
