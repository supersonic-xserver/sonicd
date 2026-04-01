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

#include "alloc-util.h"
#include "efi-string.h"
#include "fuzz.h"

#define SEP_LEN 4

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
        if (outside_size_range(size, SEP_LEN + 1, 64 * 1024))
                return 0;
        if (data[SEP_LEN] != '\0')
                return 0;

        fuzz_setup_logging();

        _cleanup_free_ char *p = memdup_suffix0(data + SEP_LEN + 1, size - SEP_LEN - 1);
        assert_se(p);

        size_t pos = 0;
        char *key, *value;
        while (line_get_key_value(p, (const char *) data, &pos, &key, &value)) {
                assert_se(key);
                assert_se(value);
        }

        return 0;
}
