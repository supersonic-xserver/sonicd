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

#include "sd-varlink.h"
#include "sd-varlink-idl.h"

#include "sd-forward.h"

bool varlink_idl_field_name_is_valid(const char *name);
bool varlink_idl_symbol_name_is_valid(const char *name);
bool varlink_idl_interface_name_is_valid(const char *name);

int varlink_idl_qualified_symbol_name_is_valid(const char *name);

int varlink_idl_consistent(const sd_varlink_interface *interface, int level);

const sd_varlink_symbol* varlink_idl_find_symbol(const sd_varlink_interface *interface, sd_varlink_symbol_type_t type, const char *name);
const sd_varlink_field* varlink_idl_find_field(const sd_varlink_symbol *symbol, const char *name);

int varlink_idl_validate_method_call(const sd_varlink_symbol *method, sd_json_variant *v, sd_varlink_method_flags_t flags, const char **reterr_bad_field);
int varlink_idl_validate_method_reply(const sd_varlink_symbol *method, sd_json_variant *v, sd_varlink_reply_flags_t flags, const char **reterr_bad_field);
int varlink_idl_validate_error(const sd_varlink_symbol *error, sd_json_variant *v, const char **bad_field);
