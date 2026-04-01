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

#include "label.h"

static const LabelOps *label_ops = NULL;

int label_ops_set(const LabelOps *ops) {
        assert(ops);

        if (label_ops)
                return -EBUSY;

        label_ops = ops;
        return 0;
}

void label_ops_reset(void) {
        label_ops = NULL;
}

int label_ops_pre(int dir_fd, const char *path, mode_t mode) {
        if (!label_ops || !label_ops->pre)
                return 0;

        return label_ops->pre(dir_fd, path, mode);
}

int label_ops_post(int dir_fd, const char *path, bool created) {
        if (!label_ops || !label_ops->post)
                return 0;

        return label_ops->post(dir_fd, path, created);
}
