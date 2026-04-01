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

#include "resolved-forward.h"

/* This contains a fixed database mapping domain names to DS or DNSKEY records. */

typedef struct DnsTrustAnchor {
        Hashmap *positive_by_key;
        Set *negative_by_name;
        Set *revoked_by_rr;
} DnsTrustAnchor;

int dns_trust_anchor_load(DnsTrustAnchor *d);
void dns_trust_anchor_flush(DnsTrustAnchor *d);

int dns_trust_anchor_lookup_positive(DnsTrustAnchor *d, const DnsResourceKey* key, DnsAnswer **ret);
int dns_trust_anchor_lookup_negative(DnsTrustAnchor *d, const char *name);

int dns_trust_anchor_check_revoked(DnsTrustAnchor *d, DnsResourceRecord *dnskey, DnsAnswer *rrs);
int dns_trust_anchor_is_revoked(DnsTrustAnchor *d, DnsResourceRecord *rr);
