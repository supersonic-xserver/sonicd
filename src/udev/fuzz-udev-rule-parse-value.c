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

#include <string.h>

#include "alloc-util.h"
#include "fuzz.h"
#include "udev-rules.h"

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
        _cleanup_free_ char *str = NULL;
        int r;
        char *value = UINT_TO_PTR(0x12345678U);
        char *endpos = UINT_TO_PTR(0x87654321U);
        bool is_case_sensitive;

        fuzz_setup_logging();

        assert_se(str = malloc(size + 1));
        memcpy(str, data, size);
        str[size] = '\0';

        r = udev_rule_parse_value(str, &value, &endpos, &is_case_sensitive);
        if (r < 0) {
                /* not modified on failure */
                assert_se(value == UINT_TO_PTR(0x12345678U));
                assert_se(endpos == UINT_TO_PTR(0x87654321U));
        } else {
                assert_se(endpos <= str + size);
                assert_se(endpos > str + 1);
        }

        return 0;
}
