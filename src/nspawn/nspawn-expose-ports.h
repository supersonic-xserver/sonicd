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
#include "list.h"

typedef struct ExposePort {
        int protocol;
        uint16_t host_port;
        uint16_t container_port;
        LIST_FIELDS(struct ExposePort, ports);
} ExposePort;

void expose_port_free_all(ExposePort *p);
int expose_port_parse(ExposePort **l, const char *s);

int expose_port_watch_rtnl(sd_event *event, int recv_fd, sd_netlink_message_handler_t handler, void *userdata, sd_netlink **ret);
int expose_port_send_rtnl(int send_fd);

int expose_port_execute(sd_netlink *rtnl, sd_netlink *nfnl, ExposePort *l, int af, union in_addr_union *exposed);
int expose_port_flush(sd_netlink *nfnl, ExposePort* l, int af, union in_addr_union *exposed);
