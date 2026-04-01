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

typedef enum DispatchLinkFlag {
        DISPATCH_LINK_POLKIT    = 1 << 0,
        DISPATCH_LINK_MANDATORY = 1 << 1,
} DispatchLinkFlag;

int dispatch_link(sd_varlink *vlink, sd_json_variant *parameters, Manager *manager, DispatchLinkFlag flags, Link **ret);

int vl_method_link_describe(sd_varlink *vlink, sd_json_variant *parameters, sd_varlink_method_flags_t flags, void *userdata);
int vl_method_link_up(sd_varlink *vlink, sd_json_variant *parameters, sd_varlink_method_flags_t flags, void *userdata);
int vl_method_link_down(sd_varlink *vlink, sd_json_variant *parameters, sd_varlink_method_flags_t flags, void *userdata);
int vl_method_link_renew(sd_varlink *vlink, sd_json_variant *parameters, sd_varlink_method_flags_t flags, void *userdata);
int vl_method_link_force_renew(sd_varlink *vlink, sd_json_variant *parameters, sd_varlink_method_flags_t flags, void *userdata);
int vl_method_link_reconfigure(sd_varlink *vlink, sd_json_variant *parameters, sd_varlink_method_flags_t flags, void *userdata);
