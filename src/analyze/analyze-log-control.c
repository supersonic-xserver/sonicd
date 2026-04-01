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

#include "sd-bus.h"

#include "analyze.h"
#include "analyze-log-control.h"
#include "bus-util.h"
#include "runtime-scope.h"
#include "verb-log-control.h"

int verb_log_control(int argc, char *argv[], uintptr_t _data, void *userdata) {
        _cleanup_(sd_bus_flush_close_unrefp) sd_bus *bus = NULL;
        int r;

        assert(IN_SET(argc, 1, 2));

        r = acquire_bus(&bus, NULL);
        if (r < 0)
                return bus_log_connect_error(r, arg_transport, arg_runtime_scope);

        r = verb_log_control_common(bus, "org.freedesktop.systemd1", argv[0], argc == 2 ? argv[1] : NULL);
        if (r < 0)
                return r;

        return 0;
}
