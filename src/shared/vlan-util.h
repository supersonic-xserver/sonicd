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

#include "conf-parser-forward.h"
#include "shared-forward.h"

#define VLANID_MAX 4094
#define VLANID_INVALID UINT16_MAX

/* Note that we permit VLAN Id 0 here, as that is apparently OK by the Linux kernel */
static inline bool vlanid_is_valid(uint16_t id) {
        return id <= VLANID_MAX;
}

int parse_vlanid(const char *p, uint16_t *ret);
int parse_vid_range(const char *p, uint16_t *vid, uint16_t *vid_end);

CONFIG_PARSER_PROTOTYPE(config_parse_default_port_vlanid);
CONFIG_PARSER_PROTOTYPE(config_parse_vlanid);
