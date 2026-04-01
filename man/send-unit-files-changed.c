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
/* SPDX-License-Identifier: MIT-0 */

#include <systemd/sd-bus.h>
#define _cleanup_(f) __attribute__((cleanup(f)))

int send_unit_files_changed(sd_bus *bus) {
  _cleanup_(sd_bus_message_unrefp) sd_bus_message *message = NULL;
  int r;

  r = sd_bus_message_new_signal(bus, &message,
                                "/org/freedesktop/systemd1",
                                "org.freedesktop.systemd1.Manager",
                                "UnitFilesChanged");
  if (r < 0)
    return r;

  return sd_bus_send(bus, message, NULL);
}
