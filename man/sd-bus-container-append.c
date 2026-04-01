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

int append_strings_to_message(sd_bus_message *m, const char *const *arr) {
  const char *s;
  int r;

  r = sd_bus_message_open_container(m, 'a', "s");
  if (r < 0)
    return r;

  for (s = *arr; *s; s++) {
    r = sd_bus_message_append(m, "s", s);
    if (r < 0)
      return r;
  }

  return sd_bus_message_close_container(m);
}
