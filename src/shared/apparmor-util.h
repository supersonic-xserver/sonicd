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

#include "shared-forward.h"

#if HAVE_APPARMOR
#  include <sys/apparmor.h>

#  include "dlfcn-util.h"

extern DLSYM_PROTOTYPE(aa_change_onexec);
extern DLSYM_PROTOTYPE(aa_change_profile);
extern DLSYM_PROTOTYPE(aa_features_new_from_kernel);
extern DLSYM_PROTOTYPE(aa_features_unref);
extern DLSYM_PROTOTYPE(aa_policy_cache_dir_path_preview);
extern DLSYM_PROTOTYPE(aa_policy_cache_new);
extern DLSYM_PROTOTYPE(aa_policy_cache_replace_all);
extern DLSYM_PROTOTYPE(aa_policy_cache_unref);

DEFINE_TRIVIAL_CLEANUP_FUNC_FULL_RENAME(aa_features*, sym_aa_features_unref, aa_features_unrefp, NULL);
DEFINE_TRIVIAL_CLEANUP_FUNC_FULL_RENAME(aa_policy_cache*, sym_aa_policy_cache_unref, aa_policy_cache_unrefp, NULL);

int dlopen_libapparmor(void);
bool mac_apparmor_use(void);
#else
static inline int dlopen_libapparmor(void) {
        return -EOPNOTSUPP;
}
static inline bool mac_apparmor_use(void) {
        return false;
}
#endif
