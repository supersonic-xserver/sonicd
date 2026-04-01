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
#include "build-path.h"
#include "log.h"
#include "string-util.h"

int main(int argc, char* argv[]) {
        _cleanup_free_ char *p = NULL;
        int r;

        r = get_build_exec_dir(&p);
        if (r == -ENOEXEC)
                log_info("Not run from build dir.");
        else if (r < 0)
                log_error_errno(r, "Failed to find build dir: %m");
        else
                log_info("%s", strna(p));

        return 0;
}
