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
#include <systemd/sd-id128.h>

#define OUR_APPLICATION_ID SD_ID128_MAKE(c2,73,27,73,23,db,45,4e,a6,3b,b9,6e,79,b5,3e,97)

int main(int argc, char *argv[]) {
  sd_id128_t id;
  sd_id128_get_machine_app_specific(OUR_APPLICATION_ID, &id);
  printf("Our application ID: " SD_ID128_FORMAT_STR "\n", SD_ID128_FORMAT_VAL(id));
  return 0;
}
