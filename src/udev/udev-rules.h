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
/* SPDX-License-Identifier: GPL-2.0-or-later */
#pragma once

#include "udev-def.h"
#include "udev-forward.h"

int udev_rule_parse_value(char *str, char **ret_value, char **ret_endpos, bool *ret_is_case_insensitive);
int udev_rules_parse_file(UdevRules *rules, const ConfFile *c, bool extra_checks, UdevRuleFile **ret);
unsigned udev_rule_file_get_issues(UdevRuleFile *rule_file);
UdevRules* udev_rules_new(ResolveNameTiming resolve_name_timing);
int udev_rules_load(UdevRules **ret_rules, ResolveNameTiming resolve_name_timing, char * const *extra);
UdevRules* udev_rules_free(UdevRules *rules);
DEFINE_TRIVIAL_CLEANUP_FUNC(UdevRules*, udev_rules_free);
#define udev_rules_free_and_replace(a, b) free_and_replace_full(a, b, udev_rules_free)

bool udev_rules_should_reload(UdevRules *rules);
int udev_rules_apply_to_event(UdevRules *rules, UdevEvent *event);
int udev_rules_apply_static_dev_perms(UdevRules *rules);

DECLARE_STRING_TABLE_LOOKUP(resolve_name_timing, ResolveNameTiming);
