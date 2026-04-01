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

typedef enum ExecutionMode {
        MODE_RESOLVE_HOST,
        MODE_RESOLVE_RECORD,
        MODE_RESOLVE_SERVICE,
        MODE_RESOLVE_OPENPGP,
        MODE_RESOLVE_TLSA,
        MODE_STATISTICS,
        MODE_RESET_STATISTICS,
        MODE_FLUSH_CACHES,
        MODE_RESET_SERVER_FEATURES,
        MODE_STATUS,
        MODE_SET_LINK,
        MODE_REVERT_LINK,
        _MODE_INVALID = -EINVAL,
} ExecutionMode;

extern ExecutionMode arg_mode;
extern char **arg_set_dns;
extern char **arg_set_domain;
extern bool arg_disable_default_route;
extern bool arg_ifindex_permissive;

int ifname_mangle_full(const char *s, bool drop_protocol_specifier);
static inline int ifname_mangle(const char *s) {
        return ifname_mangle_full(s, false);
}
static inline int ifname_resolvconf_mangle(const char *s) {
        return ifname_mangle_full(s, true);
}
