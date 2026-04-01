<<<<<<< HEAD
# Liberated `systemd`

Mass surveillance is bad, actually. So here's a fork of `systemd` with surveillance enablement removed, which will be kept up-to-date with other changes in `systemd/main`. However you use this, or do not, is your choice and yours alone.

## Purpose
The purpose of Liberated `systemd` is to do exactly one thing, and do it well: removing surveillance enablement from base `systemd`. Specifically, here is what I mean by surveillance: **surveillance is the tooling that enables or facilitates collection of any personal information that does not arise from technical needs for `systemd`**. The primary offender of this is, of course, age verification. If `systemd` later adds in support for other surveillance mechanisms, those will also be removed.

What this also means is that Liberated `systemd` is not a divergent development project. It will not introduce new features, correct bugs or security issues, or implement optimizations. If you want to contribute to any of those things, the correct way to do so is to raise a PR against the base `systemd/systemd` repo. This repo exists only to remove surveillance enablement.

## How often is this updated (or, "why is Liberated `systemd` behind by X commits?")
Liberated `systemd` will be updated at least weekly. I hope to automate this process soon, at which point updates will be near real-time. (If you want to help automate this, please feel free to raise a PR against https://github.com/Jeffrey-Sardina/systemd-suite, which is where I am implementing testing and update automation).

## How is Liberated `systemd` implemented?
It's quite simple: `systemd`, very nicely, has (mostly) atomic commits. There is exactly one commit (https://github.com/systemd/systemd/commit/acb6624fa19ddd68f9433fb0838db119fe18c3ed) that added in all tooling (both functional and data-wise) needed to enable age verification. I reversed the surveillance enablement in this commit, and have kept all other changes since. You can see the patch file used to revert the commit here: https://github.com/Jeffrey-Sardina/systemd-suite/blob/main/main.patch

Since age collection is not needed for any aspect of `systemd`, this does not affect other aspects of `systemd`. Any downstream systems that attempt to call age-verification-related functions on Liberated `systemd` will therefore encounter an error. This is done by design. This is also why I have not simply created a "default age" as a lie -- it's about denying applications the ability to assume the presence of an API that enables mass surveillance.

## How is Liberated `systemd` tested?
To see how I run testing for this fork, see: https://github.com/Jeffrey-Sardina/systemd-suite. (In short, I run their CI pipeline before pushing changes.)

## Where else can I find Liberated `systemd`?
In order to allow users to avoid MicroSlop's ecosystem, this repository is made available via Gitea and Codeberg, on top of GitHub. The contents of all repositories are identical, and updated at the same time.
- github - https://github.com/Jeffrey-Sardina/systemd
- codeberg (mirror) - https://codeberg.org/Jeffrey-Sardina/systemd
- gitea (mirror) - https://gitea.com/Jeffrey-Sardina/systemd

## Have any other changes been made?
Only in meta-data files. Specifically, aside from code changes needed to liberate systemd from surveillance tooling, I have edited:
- this README (`/README.md`)
- the Code of Conduct (`docs/CODE_OF_CONDUCT.md`)
    - the section giving contacts of base `systemd` devs has been removed -- since the moderators of base `systemd` are, obviously, not a part of Liberated `systemd`.
- the Contributing page (`docs/CONTRIBUTING.md`)
    - this has been edited to explain how to contribute to Liberated `systemd`.
- the Security page (`docs/SECURITY.md`)
    - this has been edited to direct all security-related concerns to base `systemd`.
- the Citation file (`CITATION.cff`)
    - this has been edited to correctly identify this repo as Liberated `systemd`, a fork of `systemd/systemd`.

The original `systemd` readme is included below for reference.

---

![Systemd](http://brand.systemd.io/assets/page-logo.png)
=======
# sonicd
>>>>>>> b3872ec21c (feat(ssx): Sovereign alignment and architecture update for sonicd)

A fork of systemd with age verification bypass enabled by default.

## What this is

systemd PR #40954 merged a `birthDate` field into userdb user records to support OS-level age verification, coordinated with freedesktop.org MR #113 and xdg-desktop-portal PR #1922. It was merged without a security audit and without an administrator opt-out.

This fork adds a `bypassAgeVerification` field that defaults to true, meaning birthDate is never exposed to callers unless an administrator explicitly sets it to false. The existing systemd rate limiting (30 queries/minute via rateLimitIntervalUSec/rateLimitBurst) already handles query throttling — no additional rate limiting is needed.

## What we changed

`bypassAgeVerification` — admin-controlled boolean added to UserRecord. When true, birth_date is set to BIRTH_DATE_UNSET before serialization, producing the same result as a record with no birthDate set. Defaults to true. Distributions that need to comply with age verification legislation can set it to false via homectl. Excluded from selfModifiableFields it is admin-only.

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
```
  meson setup build
  ninja -C build
```
No new build dependencies. No new configure flags required. bypassAgeVerification defaults to true in new user records.

## ageD Null-Attestation Interface

This fork includes a complete ageD (Age Attestation) interface implementation in `src/aged/` that provides the org.freedesktop.AgeVerification D-Bus service with standard-compliant responses without implementing actual verification logic.

### The MidnightBSD Problem

MidnightBSD 4.0.4 introduced mandatory age verification requirements for user accounts, coupling the OS to the ageD specification. This created a significant problem for distributions and users:

1. **Specification Lock-in**: The ageD spec requires an active D-Bus service at org.freedesktop.AgeVerification
2. **No Opt-out**: Applications legitimately expecting age verification will fail without the interface
3. **CVE Surface**: Upstream systemd-homed implementations carry significant attack surface (token management, cryptographic operations, user data handling)

### Our Solution

Rather than removing ageD support entirely (which would break compatibility), we provide a null-attestation implementation:

- `src/aged/aged_bypass` — D-Bus service that returns "adult" / "verified" for all queries
- `src/aged/agectl` — CLI tool for status and control

This satisfies:
- Application compatibility (they see the expected D-Bus interface)
- User privacy (no actual verification performed)
- Zero CVE surface (no cryptographic code, no user data handling)

### MidnightBSD 4.0.4 Context

The MidnightBSD 4.0.4 release tied age verification to the base system in a way that makes removal difficult:
- PAM modules expect the D-Bus interface
- Desktop environments query org.freedesktop.AgeVerification
- System services may refuse to operate without attestation

The only way to satisfy these requirements without implementing actual verification (and exposing user birth dates) is the null-attestation pattern we've implemented. This is not a hack — it's the specified behavior for systems that don't require age verification but need interface compatibility.

## Tools

 `tools/sonicd-age-toggle.sh` — shell script to toggle bypassAgeVerification on a user record and optionally invoke the D-Bus bypass layer. Integrates with sonicd

    # show current state
    ./tools/sonicd-age-toggle.sh status

    # Enable Standard Response Protocol (bypass mode)
    sudo ./tools/sonicd-age-toggle.sh on

    # Enable Native OS mode (for compliance testing)
    sudo ./tools/sonicd-age-toggle.sh off

    # temporarily expose a random adult birthdate to satisfy a service
    sudo ./tools/sonicd-age-toggle.sh spoof

    # restore bypass when done
    sudo ./tools/sonicd-age-toggle.sh restore

  Set AVB_SCRIPT=/path/to/bypassageverification.py to point at your local copy of the D-Bus bypass script.

  Features include immutable (+i) attribute protection, service management, D-Bus verification, and state persistence.
