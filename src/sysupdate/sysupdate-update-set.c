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

#include <stdlib.h>

#include "string-util.h"
#include "sysupdate-update-set.h"

UpdateSet* update_set_free(UpdateSet *us) {
        if (!us)
                return NULL;

        free(us->version);
        free(us->instances); /* The objects referenced by this array are freed via resource_free(), not us */

        return mfree(us);
}

int update_set_cmp(UpdateSet *const*a, UpdateSet *const*b) {
        assert(a);
        assert(b);
        assert(*a);
        assert(*b);
        assert((*a)->version);
        assert((*b)->version);

        /* Newest version at the beginning */
        return -strverscmp_improved((*a)->version, (*b)->version);
}
