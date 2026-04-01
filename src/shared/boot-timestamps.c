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

#include "acpi-fpdt.h"
#include "boot-timestamps.h"
#include "efi-loader.h"
#include "time-util.h"

int boot_timestamps(const dual_timestamp *n, dual_timestamp *firmware, dual_timestamp *loader) {
        usec_t x = 0, y = 0, a;
        int r;
        dual_timestamp _n;

        assert(firmware);
        assert(loader);

        if (!n) {
                dual_timestamp_now(&_n);
                n = &_n;
        }

        r = acpi_get_boot_usec(&x, &y);
        if (r < 0) {
                r = efi_loader_get_boot_usec(&x, &y);
                if (r < 0)
                        return r;
        }

        /* Let's convert this to timestamps where the firmware
         * began/loader began working. To make this more confusing:
         * since usec_t is unsigned and the kernel's monotonic clock
         * begins at kernel initialization we'll actually initialize
         * the monotonic timestamps here as negative of the actual
         * value. */

        firmware->monotonic = y;
        loader->monotonic = y - x;

        a = n->monotonic + firmware->monotonic;
        firmware->realtime = n->realtime > a ? n->realtime - a : 0;

        a = n->monotonic + loader->monotonic;
        loader->realtime = n->realtime > a ? n->realtime - a : 0;

        return 0;
}
