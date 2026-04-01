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

#include "networkd-util.h"
#include "tests.h"

TEST(network_config_state_to_string_alloc) {
        for (unsigned i = 1; i <= NETWORK_CONFIG_STATE_REMOVING; i <<= 1) {
                _cleanup_free_ char *x;

                assert_se(network_config_state_to_string_alloc(i, &x) == 0);
                log_debug("%u → %s", i, x);
        }

        _cleanup_free_ char *x;
        assert_se(network_config_state_to_string_alloc(~0u, &x) == 0);
        log_debug("%u → %s", ~0u, x);
};

DEFINE_TEST_MAIN(LOG_DEBUG);
