# sonicd

A fork of systemd with age verification bypass enabled by default.

## What this is

systemd PR #40954 merged a `birthDate` field into userdb user records to support OS-level age verification, coordinated with freedesktop.org MR #113 and xdg-desktop-portal PR #1922. It was merged without a security audit and without an administrator opt-out.

This fork adds a `bypassAgeVerification` field that defaults to true, meaning birthDate is never exposed to callers unless an administrator explicitly sets it to false. The existing systemd rate limiting (30 queries/minute via rateLimitIntervalUSec/rateLimitBurst) already handles query throttling — no additional rate limiting is needed.

## What we changed

`bypassAgeVerification` — admin-controlled boolean added to UserRecord. When true, birth_date is set to BIRTH_DATE_UNSET before serialization, producing the same result as a record with no birthDate set. Defaults to true. Distributions that need to comply with age verification legislation can set it to false via homectl. Excluded from selfModifiableFields — admin-only.

Security hardening of the original birthDate implementation: input validation, information exposure review, null dereference checks, buffer handling review, and authorization documentation.

## The legal argument

Every age verification law we are aware of requires that the mechanism be implemented, not that it be active. The code is here. It works. It is simply off by default. Distributions that need California AB 2273 or similar compliance can enable it via the admin flag. Everyone else gets privacy by default.

## Upstream

sonicd is a fork of systemd. The upstream repository is https://github.com/systemd/systemd. To compare all changes made in this fork against upstream since people are overly reliant on the GitHub UI for this:

  ```
  git clone https://github.com/supersonic-xserver/sonicd
  cd sonicd
  git remote add upstream https://github.com/systemd/systemd
  git fetch upstream
  git log upstream/main..main --oneline
  ```
Or view the diff directly:

  git diff upstream/main main -- src/shared/user-record.c src/shared/user-record.h src/userdb/userwork.c

or with the web browser... https://github.com/systemd/systemd/compare/main...supersonic-xserver:sonicd:main

## What upstream did with the proposed fix

PR #41259 submitted to systemd upstream adding these changes. Renamed "spam" and locked in under a minute by the same maintainer who merged the original PR, with no technical response.

## Related projects

ageverificationbypass — D-Bus bypass tool for the xdg-desktop-portal age verification interface: https://github.com/HaplessIdiot/ageverificationbypass

supersonic-xserver — historical XFree86 preservation and modern Linux desktop work: https://github.com/supersonic-xserver

## Building

  meson setup build
  ninja -C build

No new build dependencies. No new configure flags required. bypassAgeVerification defaults to true in new user records.

## Tools

 `tools/sonicd-age-toggle.sh` — shell script to toggle bypassAgeVerification on a user record and optionally invoke the D-Bus bypass layer. Integrates with sonicd

    # show current state
    ./tools/sonicd-age-toggle.sh status

    # enable bypass (default, birthDate hidden)
    sudo ./tools/sonicd-age-toggle.sh on

    # temporarily expose a random adult birthdate to satisfy a service
    sudo ./tools/sonicd-age-toggle.sh spoof

    # restore bypass when done
    sudo ./tools/sonicd-age-toggle.sh restore

  Set AVB_SCRIPT=/path/to/bypassageverification.py to point at your local copy of the D-Bus bypass script.
