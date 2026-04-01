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

#include "basic-forward.h"

/* Length of a single label, with all escaping removed, excluding any trailing dot or NUL byte */
#define DNS_LABEL_MAX 63

/* Worst case length of a single label, with all escaping applied and room for a trailing NUL byte. */
#define DNS_LABEL_ESCAPED_MAX (DNS_LABEL_MAX*4+1)

/* Maximum length of a full hostname, consisting of a series of unescaped labels, and no trailing dot or NUL byte */
#define DNS_HOSTNAME_MAX 253

/* Maximum length of a full hostname, on the wire, including the final NUL byte */
#define DNS_WIRE_FORMAT_HOSTNAME_MAX 255

/* Maximum number of labels per valid hostname */
#define DNS_N_LABELS_MAX 127
