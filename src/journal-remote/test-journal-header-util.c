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

#include "hashmap.h"
#include "journal-header-util.h"
#include "tests.h"

TEST(header_put) {
        _cleanup_ordered_hashmap_free_ OrderedHashmap *headers = NULL;

        ASSERT_OK_POSITIVE(header_put(&headers, "NewName", "Val"));
        ASSERT_OK_POSITIVE(header_put(&headers, "Name", "FirstName"));
        ASSERT_OK_POSITIVE(header_put(&headers, "Name", "Override"));
        ASSERT_OK_ZERO(header_put(&headers, "Name", "FirstName"));
        ASSERT_ERROR(header_put(&headers, "InvalidN@me", "test"), EINVAL);
        ASSERT_ERROR(header_put(&headers, "Name", NULL), EINVAL);
        ASSERT_ERROR(header_put(&headers, NULL, "Value"), EINVAL);
        ASSERT_OK_POSITIVE(header_put(&headers, "Name", ""));
        ASSERT_ERROR(header_put(&headers, "", "Value"), EINVAL);
}

DEFINE_TEST_MAIN(LOG_DEBUG);
