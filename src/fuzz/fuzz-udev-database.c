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

#include "device-internal.h"
#include "device-private.h"
#include "fd-util.h"
#include "fuzz.h"
#include "tmpfile-util.h"

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
        _cleanup_(sd_device_unrefp) sd_device *dev = NULL;
        _cleanup_(unlink_tempfilep) char filename[] = "/tmp/fuzz-udev-database.XXXXXX";
        _cleanup_fclose_ FILE *f = NULL;

        fuzz_setup_logging();

        assert_se(fmkostemp_safe(filename, "r+", &f) == 0);
        if (size != 0)
                assert_se(fwrite(data, size, 1, f) == 1);

        fflush(f);
        assert_se(device_new_aux(&dev) >= 0);
        (void) device_read_db_internal_filename(dev, filename);
        return 0;
}
