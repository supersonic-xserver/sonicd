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
#ifndef foosddhcpoptionhfoo
#define foosddhcpoptionhfoo

/***
  systemd is free software; you can redistribute it and/or modify it
  under the terms of the GNU Lesser General Public License as published by
  the Free Software Foundation; either version 2.1 of the License, or
  (at your option) any later version.

  systemd is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with systemd; If not, see <https://www.gnu.org/licenses/>.
***/

#include "_sd-common.h"
#include "sd-dhcp-protocol.h"   /* IWYU pragma: export */

_SD_BEGIN_DECLARATIONS;

typedef struct sd_dhcp_option sd_dhcp_option;

int sd_dhcp_option_new(uint8_t option, const void *data, size_t length, sd_dhcp_option **ret);
_SD_DECLARE_TRIVIAL_REF_UNREF_FUNC(sd_dhcp_option);

_SD_DEFINE_POINTER_CLEANUP_FUNC(sd_dhcp_option, sd_dhcp_option_unref);

_SD_END_DECLARATIONS;

#endif
