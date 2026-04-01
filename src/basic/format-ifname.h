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

#include <net/if.h>

typedef enum {
        FORMAT_IFNAME_IFINDEX              = 1 << 0,
        FORMAT_IFNAME_IFINDEX_WITH_PERCENT = (1 << 1) | FORMAT_IFNAME_IFINDEX,
} FormatIfnameFlag;

int format_ifname_full(int ifindex, FormatIfnameFlag flag, char buf[static IF_NAMESIZE]);
int format_ifname_full_alloc(int ifindex, FormatIfnameFlag flag, char **ret);

static inline int format_ifname(int ifindex, char buf[static IF_NAMESIZE]) {
        return format_ifname_full(ifindex, 0, buf);
}
static inline int format_ifname_alloc(int ifindex, char **ret) {
        return format_ifname_full_alloc(ifindex, 0, ret);
}

static inline char* _format_ifname_full(int ifindex, FormatIfnameFlag flag, char buf[static IF_NAMESIZE]) {
        (void) format_ifname_full(ifindex, flag, buf);
        return buf;
}

#define FORMAT_IFNAME_FULL(index, flag) _format_ifname_full(index, flag, (char[IF_NAMESIZE]){})
#define FORMAT_IFNAME(index) _format_ifname_full(index, 0, (char[IF_NAMESIZE]){})
