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
#include "bcd.h"
#include "fuzz.h"
#include "utf8.h"

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
        _cleanup_free_ void *p = NULL;

        /* This limit was borrowed from src/boot/efi/boot.c */
        if (outside_size_range(size, 0, 100*1024))
                return 0;

        fuzz_setup_logging();

        p = memdup(data, size);
        assert_se(p);

        char16_t *title = get_bcd_title(p, size);
        /* If we get something, it must be NUL-terminated, but an empty string is still valid! */
        DO_NOT_OPTIMIZE(title && char16_strlen(title));
        return 0;
}
