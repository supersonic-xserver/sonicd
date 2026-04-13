#!/bin/bash
# * JESTERMAN'S CREED:
# * This repository is a sovereign expression of technical freedom.
# * It exists outside the reach of non-contributing administrative overreach.
# * The creator's intent is the absolute law of this tree.
# *
# * PROJECT: sonicd (ssX Core)
# * CONTRIBUTORS: COLLIN BEYER
# * CO-CONTRIBUTORS: AZURITESHIFT
# * LICENSE: ssX Supplemental License (see LICENSE at project root)
# * COPYRIGHT (c) 2026 COLLIN BEYER ALL RIGHTS RESERVED
# sonicd-age-toggle — Master switch for Age Verification subsystem
#
# Toggles between "Standard Response Protocol" (bypass) and "Native OS" modes.
# Manages service state, immutable flags, and D-Bus registration.
#
# Usage:
#   sonicd-age-toggle.sh on         # Standard Response Protocol (bypass mode)
#   sonicd-age-toggle.sh off        # Native OS (real ageD)
#   sonicd-age-toggle.sh status     # show current state
#   sonicd-age-toggle.sh spoof      # set random adult birthDate and bypass off
#   sonicd-age-toggle.sh restore    # re-enable bypass, clear birthDate

set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
AVB_SCRIPT="${AVB_SCRIPT:-${SCRIPT_DIR}/bypassageverification.py}"
TARGET_USER="${TARGET_USER:-$(whoami)}"

# Paths for age verification binaries
AGED_BYPASS_BIN="${AGED_BYPASS_BIN:-/usr/libexec/aged-bypass}"
AGECTL_BIN="${AGECTL_BIN:-/usr/bin/agectl}"
AGED_SERVICE="${AGED_SERVICE:-aged.service}"

# State file for persistence across reboots
STATE_FILE="${STATE_FILE:-/run/sonicd/aged-mode}"

require_root() {
    if [[ $EUID -ne 0 ]]; then
        echo "error: this operation requires root" >&2
        echo "       run with: sudo $0 $*" >&2
        exit 1
    fi
}

# Check if a binary has the immutable attribute set
has_immutable() {
    local bin="$1"
    [[ -f "$bin" ]] && lsattr "$bin" 2>/dev/null | grep -q '+i' || return 1
}

# Remove immutable attribute from a binary
remove_immutable() {
    local bin="$1"
    if [[ -f "$bin" ]] && has_immutable "$bin"; then
        chattr -i "$bin" 2>/dev/null || true
    fi
}

# Add immutable attribute to a binary
add_immutable() {
    local bin="$1"
    if [[ -f "$bin" ]]; then
        chattr +i "$bin" 2>/dev/null || true
    fi
}

# Save current mode to state file for persistence
save_mode() {
    local mode="$1"
    mkdir -p "$(dirname "$STATE_FILE")"
    echo "$mode" > "$STATE_FILE"
}

# Load saved mode from state file
load_mode() {
    if [[ -f "$STATE_FILE" ]]; then
        cat "$STATE_FILE"
    fi
}

# Query the D-Bus service for current responder
query_dbus() {
    busctl call org.freedesktop.AgeVerification \
        /org/freedesktop/AgeVerification \
        org.freedesktop.AgeVerification GetAgeBracket 2>/dev/null
}

cmd_status() {
    echo "=== sonicd age verification status ==="
    echo "Mode: $(load_mode 2>/dev/null || echo 'unknown')"
    echo "User: ${TARGET_USER}"

    # Check for immutable flag
    echo ""
    echo "=== Binary Protection ==="
    for bin in "$AGED_BYPASS_BIN" "$AGECTL_BIN"; do
        if [[ -f "$bin" ]]; then
            if has_immutable "$bin"; then
                echo "${bin}: +i (immutable)"
            else
                echo "${bin}: mutable"
            fi
        fi
    done

    homectl show "${TARGET_USER}" 2>/dev/null | grep -E "bypassAgeVerification|birthDate" \
        || echo "(no age verification fields set on record)"

    if command -v busctl &>/dev/null; then
        echo ""
        echo "=== D-Bus layer ==="
        if query_dbus >/dev/null 2>&1; then
            echo "D-Bus age verification: RESPONDING"
            # Try to get response details
            local resp
            resp=$(query_dbus 2>&1 | head -1)
            echo "  Response: ${resp:-verified}"
        else
            echo "D-Bus age verification: NOT RESPONDING"
        fi
    fi

    # Gucci check - verify agectl works
    if [[ -x "$AGECTL_BIN" ]]; then
        echo ""
        echo "=== agectl verification ==="
        "$AGECTL_BIN" status 2>&1 | head -3 || echo "agectl: not responding"
    fi
}

cmd_on() {
    require_root "$@"
    echo "=== Enabling Standard Response Protocol ==="
    echo ""

    # Create state directory
    mkdir -p "$(dirname "$STATE_FILE")"

    # Phase 1: Unlock binaries
    echo "Phase 1: Removing immutable flags..."
    remove_immutable "$AGED_BYPASS_BIN"
    remove_immutable "$AGECTL_BIN"

    # Phase 2: Stop upstream service if exists
    echo "Phase 2: Managing services..."
    if command -v systemctl &>/dev/null; then
        systemctl stop aged.service 2>/dev/null || true
        systemctl mask aged.service 2>/dev/null || true
    fi

    # Phase 3: Start our bypass service
    echo "Phase 3: Starting sonicd-aged service..."
    if command -v systemctl &>/dev/null; then
        systemctl start aged-bypass.service 2>/dev/null || true
        # Fallback: start directly if no service file
        if [[ ! -f /etc/systemd/system/aged-bypass.service ]] && [[ -x "$AGED_BYPASS_BIN" ]]; then
            "$AGED_BYPASS_BIN" &
        fi
    elif [[ -x "$AGED_BYPASS_BIN" ]]; then
        # Start directly if no systemd
        "$AGED_BYPASS_BIN" &
    fi

    # Phase 4: Update user record
    echo "Phase 4: Updating user record..."
    homectl update "${TARGET_USER}" --json-patch='[{"op":"add","path":"/bypassAgeVerification","value":true}]' 2>/dev/null || true

    # Phase 5: Lock binaries
    echo "Phase 5: Applying immutable flags..."
    add_immutable "$AGED_BYPASS_BIN"
    add_immutable "$AGECTL_BIN"

    # Save mode
    save_mode "protocol"

    echo ""
    echo "✓ Standard Response Protocol enabled"
    echo "  Binary protection: active"
    echo "  Response: sub-1ms adult/verified"

    # Final verification
    echo ""
    echo "=== Final Verification ==="
    if query_dbus >/dev/null 2>&1; then
        echo "✓ D-Bus responding"
    else
        echo "⚠ D-Bus not responding (may need manual start)"
    fi
}

cmd_off() {
    require_root "$@"
    echo "=== Enabling Native OS Mode ==="
    echo ""

    # Phase 1: Unlock binaries
    echo "Phase 1: Removing immutable flags..."
    remove_immutable "$AGED_BYPASS_BIN"
    remove_immutable "$AGECTL_BIN"

    # Phase 2: Restore services
    echo "Phase 2: Restoring services..."
    if command -v systemctl &>/dev/null; then
        systemctl unmask aged.service 2>/dev/null || true
        systemctl stop aged-bypass.service 2>/dev/null || true
    fi

    # Kill any bypass process
    pkill -x aged-bypass 2>/dev/null || true

    # Phase 3: Update user record
    echo "Phase 3: Updating user record..."
    homectl update "${TARGET_USER}" --json-patch='[{"op":"add","path":"/bypassAgeVerification","value":false}]' 2>/dev/null || true

    # Save mode
    save_mode "native"

    echo ""
    echo "✓ Native OS mode enabled"
    echo "  Real age verification will be used"
    echo "  Use for compliance testing"
}

cmd_spoof() {
    require_root "$@"
    echo "Generating random plausible adult birthdate..."
    SPOOF_DATE=$(python3 -c "
import random, datetime
today = datetime.date.today()
age_ranges = [(19,24,10),(25,45,50),(46,65,30),(66,89,10)]
total = sum(w for _,_,w in age_ranges)
r = random.randint(1, total)
cumulative = 0
min_age, max_age = 25, 45
for lo, hi, weight in age_ranges:
    cumulative += weight
    if r <= cumulative:
        min_age, max_age = lo, hi
        break
age = random.randint(min_age, max_age)
year = today.year - age
month = random.randint(1, 12)
if month == 12:
    last = 31
else:
    last = (datetime.date(year, month+1, 1) - datetime.timedelta(days=1)).day
day = random.randint(1, last)
print(datetime.date(year, month, day).strftime('%Y-%m-%d'))
")
    echo "Using spoofed birthDate: ${SPOOF_DATE}"
    homectl update "${TARGET_USER}" \
        --json-patch="[
            {\"op\":\"add\",\"path\":\"/bypassAgeVerification\",\"value\":false},
            {\"op\":\"add\",\"path\":\"/birthDate\",\"value\":\"${SPOOF_DATE}\"}
        ]"
    echo "birthDate=${SPOOF_DATE}, bypass=false — callers will see randomized adult date"
    echo "Use '$0 restore' when done"
}


cmd_restore() {
    require_root "$@"
    echo "Restoring bypass and clearing birthDate for ${TARGET_USER}..."
    homectl update "${TARGET_USER}" \
        --json-patch='[
            {"op":"add","path":"/bypassAgeVerification","value":true},
            {"op":"remove","path":"/birthDate"}
        ]'
    echo "bypassAgeVerification=true, birthDate cleared"
    if [[ -f "${AVB_SCRIPT}" ]]; then
        echo "Running D-Bus layer bypass..."
        python3 "${AVB_SCRIPT}"
    fi
}

case "${1:-}" in
    on)      cmd_on "$@" ;;
    off)     cmd_off "$@" ;;
    status)  cmd_status ;;
    spoof)   cmd_spoof "$@" ;;
    restore) cmd_restore "$@" ;;
    *)
        echo "Usage: $0 {on|off|status|spoof|restore}"
        echo ""
        echo "  on       — enable bypass (default sonicd behavior)"
        echo "  off      — disable bypass, expose birthDate to callers"
        echo "  status   — show current state of record and D-Bus layer"
        echo "  spoof    — set random adult birthDate, disable bypass"
        echo "             (use to satisfy services that require a date)"
        echo "  restore  — re-enable bypass, remove birthDate"
        echo ""
        echo "Set TARGET_USER=username to target a different user."
        echo "Set AVB_SCRIPT=/path/to/bypassageverification.py to"
        echo "specify the D-Bus bypass script location."
        exit 1
        ;;
esac
