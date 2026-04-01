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

#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <systemd/sd-bus.h>

int writer_with_negative_errno_return(int fd, sd_bus_error *error) {
  const char *message = "Hello, World!\n";

  ssize_t n = write(fd, message, strlen(message));
  if (n >= 0)
    return n; /* On success, return the number of bytes written, possibly 0. */

  /* On error, initialize the error structure, and also propagate the errno
   * value that write(2) set for us. */
  return sd_bus_error_set_errnof(error, errno, "Failed to write to fd %i: %s", fd, strerror(errno));
}
