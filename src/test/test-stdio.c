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

#include "fd-util.h"
#include "tests.h"
#include "tmpfile-util.h"

TEST(read_only) {
        _cleanup_(unlink_tempfilep) char fn[] = "/tmp/test-stdio-read-only-XXXXXX";
        _cleanup_fclose_ FILE *f = NULL;
        _cleanup_close_ int fd = -EBADF;
        int r;

        ASSERT_OK(fd = mkostemp_safe(fn));

        ASSERT_NOT_NULL(f = fopen(fn, "r"));
        ASSERT_ERROR_ERRNO(r = putc('a', f), EBADF);
        ASSERT_EQ(r, EOF);
        f = safe_fclose(f);

        ASSERT_NOT_NULL(f = fopen(fn, "r"));
        ASSERT_ERROR_ERRNO(r = putc_unlocked('a', f), EBADF);
        ASSERT_EQ(r, EOF);
        f = safe_fclose(f);

        ASSERT_NOT_NULL(f = fopen(fn, "r"));
        ASSERT_ERROR_ERRNO(r = fputc('a', f), EBADF);
        ASSERT_EQ(r, EOF);
        f = safe_fclose(f);

        ASSERT_NOT_NULL(f = fopen(fn, "r"));
        ASSERT_ERROR_ERRNO(r = fputc_unlocked('a', f), EBADF);
        ASSERT_EQ(r, EOF);
        f = safe_fclose(f);

        ASSERT_NOT_NULL(f = fopen(fn, "r"));
        ASSERT_ERROR_ERRNO(r = fputs("a", f), EBADF);
        ASSERT_EQ(r, EOF);
        f = safe_fclose(f);

        ASSERT_NOT_NULL(f = fopen(fn, "r"));
        ASSERT_ERROR_ERRNO(r = fputs_unlocked("a", f), EBADF);
        ASSERT_EQ(r, EOF);
        f = safe_fclose(f);
}

DEFINE_TEST_MAIN(LOG_INFO);
