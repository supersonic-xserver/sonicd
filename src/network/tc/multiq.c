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

#include <linux/pkt_sched.h>

#include "sd-netlink.h"

#include "multiq.h"

static int multi_queueing_fill_message(Link *link, QDisc *qdisc, sd_netlink_message *req) {
        struct tc_multiq_qopt opt = {};

        assert(req);

        /* It looks weird, but the multiq qdisc initialization wants to receive a tc_multiq_qopt attr even
         * though it doesn't do anything with it. */
        return sd_netlink_message_append_data(req, TCA_OPTIONS, &opt, sizeof(opt));
}

const QDiscVTable multiq_vtable = {
        .object_size = sizeof(BandMultiQueueing),
        .tca_kind = "multiq",
        .fill_message = multi_queueing_fill_message,
};
