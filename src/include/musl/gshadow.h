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
#pragma once

#include <errno.h>
#include <stddef.h>

struct sgrp {
        char *sg_namp;
        char *sg_passwd;
        char **sg_adm;
        char **sg_mem;
};

static inline int getsgnam_r(
                const char *__name,
                struct sgrp *__result_buf,
                char *__buffer,
                size_t __buflen,
                struct sgrp **__result) {

        return EOPNOTSUPP; /* this function returns positive errno in case of error. */
}
