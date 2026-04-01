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

#include <sys/stat.h>

#include "env-file.h"
#include "env-file-label.h"
#include "locale-setup.h"
#include "selinux-util.h"

int write_env_file_label(int dir_fd, const char *fname, char **headers, char **l) {
        int r;

        r = mac_selinux_create_file_prepare(fname, S_IFREG);
        if (r < 0)
                return r;

        r = write_env_file(dir_fd, fname, headers, l);

        mac_selinux_create_file_clear();

        return r;
}

int write_vconsole_conf_label(char **l) {
        int r;

        r = mac_selinux_create_file_prepare(etc_vconsole_conf(), S_IFREG);
        if (r < 0)
                return r;

        r = write_vconsole_conf(AT_FDCWD, etc_vconsole_conf(), l);

        mac_selinux_create_file_clear();

        return r;
}
