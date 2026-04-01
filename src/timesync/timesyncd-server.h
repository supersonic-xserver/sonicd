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

#include "list.h"
#include "socket-util.h"
#include "timesyncd-forward.h"

typedef enum ServerType {
        SERVER_SYSTEM,
        SERVER_FALLBACK,
        SERVER_LINK,
        SERVER_RUNTIME,
        _SERVER_TYPE_MAX,
        _SERVER_TYPE_INVALID = -EINVAL,
} ServerType;

struct ServerAddress {
        ServerName *name;

        union sockaddr_union sockaddr;
        socklen_t socklen;

        LIST_FIELDS(ServerAddress, addresses);
};

struct ServerName {
        Manager *manager;

        bool marked;

        ServerType type;
        char *string;

        LIST_HEAD(ServerAddress, addresses);
        LIST_FIELDS(ServerName, names);
};

int server_address_new(ServerName *n, ServerAddress **ret, const union sockaddr_union *sockaddr, socklen_t socklen);
ServerAddress* server_address_free(ServerAddress *a);
static inline int server_address_pretty(ServerAddress *a, char **pretty) {
        return sockaddr_pretty(&a->sockaddr.sa, a->socklen, true, true, pretty);
}

int server_name_new(Manager *m, ServerName **ret, ServerType type,const char *string);
ServerName *server_name_free(ServerName *n);
void server_name_flush_addresses(ServerName *n);
