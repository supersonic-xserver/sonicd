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
#pragma once

#include "networkd-forward.h"

int addresses_append_json(Link *link, bool serializing, sd_json_variant **v);
int nexthops_append_json(Manager *manager, int ifindex, sd_json_variant **v);
int routes_append_json(Manager *manager, int ifindex, sd_json_variant **v);
int link_build_json(Link *link, sd_json_variant **ret);
int manager_build_json(Manager *manager, sd_json_variant **ret);
