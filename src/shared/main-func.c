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

#include "sd-daemon.h"

#include "argv-util.h"
#include "ask-password-agent.h"
#include "main-func.h"
#include "pager.h"
#include "polkit-agent.h"
#include "selinux-util.h"
#include "string-util.h"

void main_prepare(int argc, char *argv[]) {
        assert_se(argc > 0 && !isempty(argv[0]));
        save_argc_argv(argc, argv);
}

void main_finalize(int r, int exit_status) {
        if (r < 0)
                (void) sd_notifyf(0, "ERRNO=%i", -r);
        (void) sd_notifyf(0, "EXIT_STATUS=%i", exit_status);
        ask_password_agent_close();
        polkit_agent_close();
        pager_close();
        mac_selinux_finish();
}

int exit_failure_if_negative(int result) {
        return result < 0 ? EXIT_FAILURE : EXIT_SUCCESS;
}

int exit_failure_if_nonzero(int result) {
        return result < 0 ? EXIT_FAILURE : result;
}
