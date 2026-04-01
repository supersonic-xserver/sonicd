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
#include <stdlib.h>
#include <systemd/sd-path.h>

int main(void) {
  int r;
  char *t;

  r = sd_path_lookup(SD_PATH_USER_DOCUMENTS, NULL, &t);
  if (r < 0)
    return EXIT_FAILURE;

  printf("~/Documents: %s\n", t);
  free(t);

  return EXIT_SUCCESS;
}
