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

#include <sys/stat.h>

#include "shared-forward.h"
#include "locale-util.h"

typedef struct LocaleContext {
        struct stat st;
        char *locale[_VARIABLE_LC_MAX];
} LocaleContext;

typedef enum LocaleLoadFlag {
        LOCALE_LOAD_PROC_CMDLINE = 1 << 0,
        LOCALE_LOAD_LOCALE_CONF  = 1 << 1,
        LOCALE_LOAD_ENVIRONMENT  = 1 << 2,
        LOCALE_LOAD_SIMPLIFY     = 1 << 3,
} LocaleLoadFlag;

void locale_context_clear(LocaleContext *c);
int locale_context_load(LocaleContext *c, LocaleLoadFlag flag);
int locale_context_build_env(const LocaleContext *c, char ***ret_set, char ***ret_unset);
int locale_context_save(LocaleContext *c, char ***ret_set, char ***ret_unset);

int locale_context_merge(const LocaleContext *c, char *l[_VARIABLE_LC_MAX]);
void locale_context_take(LocaleContext *c, char *l[_VARIABLE_LC_MAX]);
bool locale_context_equal(const LocaleContext *c, char *l[_VARIABLE_LC_MAX]);

int locale_setup(char ***environment);

const char* etc_locale_conf(void);
const char* etc_vconsole_conf(void);
