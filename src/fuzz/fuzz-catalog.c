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

#include <unistd.h>

#include "catalog.h"
#include "fd-util.h"
#include "fuzz.h"
#include "hashmap.h"
#include "tmpfile-util.h"

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
        _cleanup_(unlink_tempfilep) char name[] = "/tmp/fuzz-catalog.XXXXXX";
        _cleanup_close_ int fd = -EBADF;
        _cleanup_ordered_hashmap_free_ OrderedHashmap *h = NULL;

        fuzz_setup_logging();

        fd = mkostemp_safe(name);
        assert_se(fd >= 0);
        assert_se(write(fd, data, size) == (ssize_t) size);

        (void) catalog_import_file(&h, fd, name);

        return 0;
}
