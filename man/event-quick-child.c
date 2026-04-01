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

#define _GNU_SOURCE 1
#include <assert.h>
#include <stdio.h>
#include <unistd.h>
#include <systemd/sd-event.h>

int main(int argc, char **argv) {
  pid_t pid = fork();
  assert(pid >= 0);

  if (pid == 0)  /* child */
    sleep(1);

  else {         /* parent */
    sd_event *e = NULL;
    int r;

    /* Create the default event loop */
    sd_event_default(&e);
    assert(e);

    /* We create a floating child event source (attached to 'e').
     * The default handler will be called with 666 as userdata, which
     * will become the exit value of the loop. */
    r = sd_event_add_child(e, NULL, pid, WEXITED, NULL, (void*) 666);
    assert(r >= 0);

    r = sd_event_loop(e);
    assert(r == 666);

    sd_event_unref(e);
  }

  return 0;
}
