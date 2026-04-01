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

#include "analyze.h"
#include "analyze-unit-paths.h"
#include "path-lookup.h"
#include "strv.h"

int verb_unit_paths(int argc, char *argv[], uintptr_t _data, void *userdata) {
        _cleanup_(lookup_paths_done) LookupPaths paths = {};
        int r;

        r = lookup_paths_init_or_warn(&paths, arg_runtime_scope, 0, NULL);
        if (r < 0)
                return r;

        STRV_FOREACH(p, paths.search_path)
                puts(*p);

        return 0;
}
