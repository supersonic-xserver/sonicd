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

#include "hashmap.h"
#include "networkd-link.h"
#include "networkd-network.h"
#include "qdisc.h"
#include "tc.h"
#include "tclass.h"

int link_request_traffic_control(Link *link) {
        TClass *tclass;
        QDisc *qdisc;
        int r;

        assert(link);
        assert(link->network);

        link->tc_configured = false;

        HASHMAP_FOREACH(qdisc, link->network->qdiscs_by_section) {
                r = link_request_qdisc(link, qdisc);
                if (r < 0)
                        return log_link_warning_errno(link, r, "Failed to request QDisc: %m");
        }

        HASHMAP_FOREACH(tclass, link->network->tclasses_by_section) {
                r = link_request_tclass(link, tclass);
                if (r < 0)
                        return log_link_warning_errno(link, r, "Failed to request TClass: %m");
        }

        if (link->tc_messages == 0) {
                link->tc_configured = true;
                link_check_ready(link);
        } else {
                log_link_debug(link, "Setting traffic control");
                link_set_state(link, LINK_STATE_CONFIGURING);
        }

        return 0;
}
