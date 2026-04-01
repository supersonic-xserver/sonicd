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

#include "filesystems-gperf.h"
#include "stat-util.h"
#include "string-util.h"

int fs_type_from_string(const char *name, const statfs_f_type_t **ret) {
        const struct FilesystemMagic *fs_magic;

        assert(name);
        assert(ret);

        fs_magic = filesystems_gperf_lookup(name, strlen(name));
        if (!fs_magic)
                return -EINVAL;

        *ret = fs_magic->magic;
        return 0;
}

const FilesystemSet* filesystem_set_find(const char *name) {
        if (isempty(name) || name[0] != '@')
                return NULL;

        for (FilesystemGroups i = 0; i < _FILESYSTEM_SET_MAX; i++)
                if (streq(filesystem_sets[i].name, name))
                        return filesystem_sets + i;

        return NULL;
}
