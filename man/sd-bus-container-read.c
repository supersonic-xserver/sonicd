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

#include <stdio.h>

#include <systemd/sd-bus.h>

int read_strings_from_message(sd_bus_message *m) {
  int r;

  r = sd_bus_message_enter_container(m, 'a', "s");
  if (r < 0)
    return r;

  for (;;) {
    const char *s;

    r = sd_bus_message_read(m, "s", &s);
    if (r < 0)
      return r;
    if (r == 0)
      break;

    printf("%s\n", s);
  }

  return sd_bus_message_exit_container(m);
}
