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

#include <linux/audit.h>
#include <stdio.h>

#include "audit-type.h"
#include "tests.h"

static void print_audit_label(int i) {
        const char *name;

        name = audit_type_name_alloca(i);
        /* This is a separate function only because of alloca */
        printf("%i → %s → %s\n", i, audit_type_to_string(i), name);
}

TEST(audit_type) {
        int i;

        for (i = 0; i <= AUDIT_KERNEL; i++)
                print_audit_label(i);
}

DEFINE_TEST_MAIN(LOG_INFO);
