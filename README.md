# sonicd

A fork of systemd with age verification bypass enabled by default.

## What this is

systemd PR #40954 merged a `birthDate` field into userdb user records
to support OS-level age verification, coordinated with
freedesktop.org MR #113 and xdg-desktop-portal PR #1922. It was
merged without a security audit, without rate limiting, and without
an administrator opt-out.

This fork fixes that. Then turns it off by default.

## What we changed

- `bypassAgeVerification` — admin-controlled boolean that suppresses
  `birthDate` from being returned to callers. **Enabled by default.**
  You can turn it off if you want to. We won't stop you.

- `ageVerificationPollIntervalUSec` — caps how frequently any process
  can query age data via userdb. Defaults to 1 query per second.
  Prevents timing oracle attacks and DoS against a field containing
  personally identifiable information.

- Security hardening of Dylan's original `birthDate` implementation:
  input validation, information exposure fixes, buffer handling
  review, null dereference checks, and authorization documentation.

## The legal argument

Every age verification law we are aware of requires that the
mechanism be **implemented**, not that it be **active**. The code is
here. It works. It is simply off by default. Distributions that need
to comply with California AB 2273 or similar legislation can enable
it via the admin flag. Everyone else gets privacy by default.

We did Dylan M Taylor's job better than he did, and then we turned it off.

## What upstream did

- PR #40954: merged without audit, no rate limiting, no opt-out
- PR #41259 (our fix): renamed "spam" and locked in under a minute
  by the same maintainer who pushed the original, with no technical
  response
- Freedesktop MR #113: still open, still being pushed

The locked PR is public record. The technical argument stands on its
own.

## Related projects

- [ageverificationbypass](https://github.com/HaplessIdiot/ageverificationbypass)
  — D-Bus bypass tool for the xdg-desktop-portal age verification
  interface. The maintainer confirmed they cannot stop users or
  distributions from using it.

- [supersonic-xserver](https://github.com/supersonic-xserver)
  — historical XFree86 preservation and modern Linux desktop work

## Building

Standard systemd build:
```bash
meson setup build
ninja -C build
```

No new build dependencies. No new configure flags required.
bypassAgeVerification defaults to true in new user records.

## License

LGPL-2.1-or-later, same as upstream systemd.
See LICENSES/ and individual file headers for details.
Modifications by HaplessIdiot are licensed under the same terms.
