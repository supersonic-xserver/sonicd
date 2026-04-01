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

#include "memory-util.h"
#include "static-destruct.h"

void static_destruct_impl(const StaticDestructor *start, const StaticDestructor *end) {
        if (!start)
                return;

        for (const StaticDestructor *d = ALIGN_PTR(start); d < end; d = ALIGN_PTR(d + 1))
                switch (d->type) {
                case STATIC_DESTRUCTOR_SIMPLE:
                        d->simple.destroy(d->simple.data);
                        break;

                case STATIC_DESTRUCTOR_ARRAY:
                        array_cleanup(&d->array);
                        break;

                default:
                        assert_not_reached();
                }
}
