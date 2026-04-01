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

int can_set_netlink_message(Link *link, sd_netlink_message *m);

CONFIG_PARSER_PROTOTYPE(config_parse_can_bitrate);
CONFIG_PARSER_PROTOTYPE(config_parse_can_time_quanta);
CONFIG_PARSER_PROTOTYPE(config_parse_can_restart_usec);
CONFIG_PARSER_PROTOTYPE(config_parse_can_control_mode);
CONFIG_PARSER_PROTOTYPE(config_parse_can_termination);
