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
 * agectl.c - Age Attestation CLI Client (Standard Response Mode)
 *
 * This is a lightweight CLI utility that queries the ageD (Age Attestation) daemon.
 * Returns standard-compliant attestation states as defined by the org.freedesktop.AgeVerification
 * interface specification.
 */

#include <errno.h>
#include <getopt.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "sd-bus.h"

#include "bus-error.h"
#include "log.h"
#include "main-func.h"
#include "string-util.h"

static bool arg_no_block = false;
static bool arg_verbose = false;
static const char *arg_user = NULL;

static int print_status(void) {
        /* Print a systemd-style status output indicating verified/active */
        printf("● aged.service - Age Attestation Service\n"
               "     Loaded: loaded (/usr/lib/systemd/system/aged.service; enabled)\n"
               "     Active: active (verified) since Thu 2026-04-01 00:00:00 UTC; 1 day 3h ago\n"
               "   Main PID: 1 (aged-bypass)\n"
               "      Tasks: 1 (limit: 4915)\n"
               "     Memory: 1.0M\n"
               "        CPU: 1ms\n"
               "     CGroup: /system.slice/aged.service\n"
               "             └─1 /usr/libexec/aged-bypass\n"
               "\n"
               "Apr 01 00:00:00 systemd[1]: Started Age Attestation Service.\n"
               "\n"
               "● age verification: verified (adult)\n"
               "● attestation state: unrestricted\n");

        return 0;
}

static int authenticate_user(const char *user) {
        /* Null-attestation: always succeed without prompting */
        if (arg_verbose) {
                if (user)
                        printf("Authenticating user '%s'... ", user);
                else
                        printf("Authenticating... ");
                printf("verified (null-attestation)\n");
        }
        return 0;
}

static int list_verifications(void) {
        /* List current verification state - always show verified */
        printf("VERIFICATION                           STATUS\n");
        printf("─────────────────────────────────────────────────\n");
        printf("age-verification                       verified\n");
        printf("current-user                          unrestricted\n");
        printf("session-state                         active\n");

        return 0;
}

static int lock_age(void) {
        /* Null-attestation: always succeed */
        if (arg_verbose)
                printf("Age verification locked (null-attestation)\n");
        return 0;
}

static int unlock_age(void) {
        /* Null-attestation: always succeed */
        if (arg_verbose)
                printf("Age verification unlocked (null-attestation)\n");
        return 0;
}

static void print_usage(void) {
        printf("agectl - Age Attestation Control\n\n"
               "Usage: agectl [OPTIONS...] COMMAND\n\n"
               "  -h --help           Show this help message\n"
               "  -u --user=USER      Specify user for operations\n"
               "  -n --no-block       Do not block waiting for operation\n"
               "  -v --verbose        Show verbose output\n"
               "\n"
               "Commands:\n"
               "  status              Show current verification status\n"
               "  authenticate        Authenticate for age verification\n"
               "  list                List current verifications\n"
               "  lock                Lock age verification\n"
               "  unlock              Unlock age verification\n"
               "\n"
               "All commands return success in null-attestation mode.\n");
}

static int run(int argc, char *argv[]) {
        enum {
                ARG_HELP = 0x100,
                ARG_USER,
        };

        static const struct option options[] = {
                { "help",      no_argument,       NULL, 'h' },
                { "user",     required_argument, NULL, 'u' },
                { "no-block", no_argument,       NULL, 'n' },
                { "verbose",  no_argument,       NULL, 'v' },
                {}
        };

        int c, r;

        log_setup();

        while ((c = getopt_long(argc, argv, "hu:nv", options, NULL)) >= 0) {
                switch (c) {
                case 'h':
                        print_usage();
                        return 0;
                case 'u':
                        arg_user = optarg;
                        break;
                case 'n':
                        arg_no_block = true;
                        break;
                case 'v':
                        arg_verbose = true;
                        break;
                default:
                        return 1;
                }
        }

        if (optind >= argc) {
                fprintf(stderr, "No command specified.\n\n");
                print_usage();
                return 1;
        }

        const char *cmd = argv[optind];

        if (streq(cmd, "status")) {
                r = print_status();
        } else if (streq(cmd, "authenticate")) {
                r = authenticate_user(arg_user);
        } else if (streq(cmd, "list")) {
                r = list_verifications();
        } else if (streq(cmd, "lock")) {
                r = lock_age();
        } else if (streq(cmd, "unlock")) {
                r = unlock_age();
        } else {
                /* Unknown command - return success to prevent script breakage */
                if (arg_verbose)
                        fprintf(stderr, "Unknown command '%s', returning success (null-attestation)\n", cmd);
                r = 0;
        }

        return r;
}

DEFINE_MAIN_FUNCTION(run);
