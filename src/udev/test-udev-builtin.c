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

#include "tests.h"
#include "udev-builtin.h"

TEST(udev_builtin_cmd_to_ptr) {
        /* Those could have been static asserts, but ({}) is not allowed there. */
#if HAVE_BLKID
        assert_se(UDEV_BUILTIN_CMD_TO_PTR(UDEV_BUILTIN_BLKID));
        assert_se(PTR_TO_UDEV_BUILTIN_CMD(UDEV_BUILTIN_CMD_TO_PTR(UDEV_BUILTIN_BLKID)) == UDEV_BUILTIN_BLKID);
#endif
        assert_se(UDEV_BUILTIN_CMD_TO_PTR(UDEV_BUILTIN_BTRFS));
        assert_se(PTR_TO_UDEV_BUILTIN_CMD(UDEV_BUILTIN_CMD_TO_PTR(UDEV_BUILTIN_BTRFS)) == UDEV_BUILTIN_BTRFS);
        assert_se(PTR_TO_UDEV_BUILTIN_CMD(UDEV_BUILTIN_CMD_TO_PTR(_UDEV_BUILTIN_INVALID)) == _UDEV_BUILTIN_INVALID);

        assert_se(PTR_TO_UDEV_BUILTIN_CMD(NULL) == _UDEV_BUILTIN_INVALID);
        assert_se(PTR_TO_UDEV_BUILTIN_CMD((void*) 10000) == _UDEV_BUILTIN_INVALID);
}

DEFINE_TEST_MAIN(LOG_DEBUG);
