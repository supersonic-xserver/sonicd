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

/*
 * aged_bypass.c - Age Attestation D-Bus Service (Standard Response Protocol)
 *
 * This module provides the org.freedesktop.AgeVerification D-Bus interface
 * as specified by the Age Verification API. Applications querying age verification
 * receive standard-compliant responses per the attestation protocol.
 *
 * This implementation satisfies interface compatibility requirements
 * without exposing user data or implementing external verification logic.
 */

#include <errno.h>
#include <stdlib.h>

#include "sd-bus.h"
#include "sd-event.h"
#include "sd-json.h"

#include "aged_bypass.h"
#include "bus-error.h"
#include "log.h"
#include "main-func.h"
#include "string-util.h"

/* org.freedesktop.AgeVerification interface */
static const char *arg_bus_name = "org.freedesktop.AgeVerification";

/* Global state for integrated mode */
static sd_bus *aged_bypass_bus = NULL;
static bool aged_bypass_initialized = false;

static int vl_method_get_age_bracket(
                sd_bus_message *message,
                void *userdata,
                sd_bus_error *error) {

        /* Null-attestation: Always return "adult" (age bracket 4 or higher)
         * This indicates the user has passed age verification without any
         * actual check. Applications requesting age verification will
         * receive immediate approval.
         *
         * Age brackets typically:
         *   0 = under 13
         *   1 = 13-17
         *   2 = 18-20
         *   3 = 21-24
         *   4 = 25+ (adult)
         *
         * We return adult status immediately without any user interaction. */

        return sd_bus_reply_method_return(
                        message,
                        "{sv}",
                        "ageBracket", "s", "adult",
                        "verified", "b", 1);
}

static int vl_method_get_user_age(
                sd_bus_message *message,
                void *userdata,
                sd_bus_error *error) {

        /* Return adult status for any user query - null attestation */

        return sd_bus_reply_method_return(
                        message,
                        "{sv}",
                        "status", "s", "adult",
                        "ageVerified", "b", 1);
}

static int vl_method_check_verification(
                sd_bus_message *message,
                void *userdata,
                sd_bus_error *error) {

        /* Always return verified status - null attestation */

        return sd_bus_reply_method_return(
                        message,
                        "{sv}",
                        "verified", "b", 1,
                        "age", "u", (uint32_t)25);
}

static const sd_bus_vtable aged_vtable[] = {
        SD_BUS_VTABLE_START(0),
        SD_BUS_METHOD("GetAgeBracket", "s", "a{sv}", vl_method_get_age_bracket, 0),
        SD_BUS_METHOD("GetUserAge", "s", "a{sv}", vl_method_get_user_age, 0),
        SD_BUS_METHOD("CheckVerification", "s", "a{sv}", vl_method_check_verification, 0),
        SD_BUS_VTABLE_END
};

static int on_bus(sd_bus_message *message, void *userdata, sd_bus_error *error) {
        return 0;
}

static int run(int argc, char *argv[]) {
        _cleanup_(sd_bus_flush_close_unrefp) sd_bus *bus = NULL;
        int r;

        log_setup();

        r = sd_bus_default_system(&bus);
        if (r < 0)
                return log_error_errno(r, "Failed to connect to system bus: %m");

        r = sd_bus_add_object_vtable(
                        bus,
                        NULL,
                        "/org/freedesktop/AgeVerification",
                        arg_bus_name,
                        aged_vtable,
                        NULL);
        if (r < 0)
                return log_error_errno(r, "Failed to register object: %m");

        r = sd_bus_request_name(bus, arg_bus_name, 0);
        if (r < 0)
                return log_error_errno(r, "Failed to acquire name: %m");

        r = sd_bus_match_signal(
                        bus,
                        NULL,
                        "org.freedesktop.DBus",
                        "/org/freedesktop/DBus",
                        "org.freedesktop.DBus",
                        "NameAcquired",
                        on_bus,
                        NULL);
        if (r < 0)
                log_warning_errno(r, "Failed to subscribe to NameAcquired signal: %m");

        log_info("aged bypass: Accepting age verification queries (null-attestation mode)");
        log_info("aged bypass: All queries will return 'adult' status immediately");

        r = sd_event_loop(sd_bus_get_event(bus));
        if (r < 0)
                return log_error_errno(r, "Event loop failed: %m");

        return 0;
}

DEFINE_MAIN_FUNCTION(run);

int init_aged_bypass(void) {
        int r;

        if (aged_bypass_initialized)
                return 0;

        log_setup();

        /* Connect to the system bus */
        r = sd_bus_default_system(&aged_bypass_bus);
        if (r < 0)
                return log_error_errno(r, "Failed to connect to system bus: %m");

        /* Register the age verification object */
        r = sd_bus_add_object_vtable(
                        aged_bypass_bus,
                        NULL,
                        "/org/freedesktop/AgeVerification",
                        arg_bus_name,
                        aged_vtable,
                        NULL);
        if (r < 0) {
                aged_bypass_bus = sd_bus_flush_close_unref(aged_bypass_bus);
                return log_error_errno(r, "Failed to register object: %m");
        }

        /* Acquire the well-known bus name */
        r = sd_bus_request_name(aged_bypass_bus, arg_bus_name, 0);
        if (r < 0) {
                aged_bypass_bus = sd_bus_flush_close_unref(aged_bypass_bus);
                return log_error_errno(r, "Failed to acquire name: %m");
        }

        r = sd_bus_match_signal(
                        aged_bypass_bus,
                        NULL,
                        "org.freedesktop.DBus",
                        "/org/freedesktop/DBus",
                        "org.freedesktop.DBus",
                        "NameAcquired",
                        on_bus,
                        NULL);
        if (r < 0)
                log_warning_errno(r, "Failed to subscribe to NameAcquired signal: %m");

        log_info("aged bypass: Initialized (null-attestation mode)");
        log_info("aged bypass: All queries will return 'adult' status immediately");

        aged_bypass_initialized = true;
        return 0;
}

int shutdown_aged_bypass(void) {
        if (!aged_bypass_initialized)
                return 0;

        log_info("aged bypass: Shutting down");

        aged_bypass_bus = sd_bus_flush_close_unref(aged_bypass_bus);
        aged_bypass_initialized = false;

        return 0;
}
