/*
 * lib/krb5/free/f_tkt_auth.c
 *
 * Copyright 1990,1991 by the Massachusetts Institute of Technology.
 * All Rights Reserved.
 *
 * Export of this software from the United States of America may
 *   require a specific license from the United States Government.
 *   It is the responsibility of any person or organization contemplating
 *   export to obtain such a license before exporting.
 * 
 * WITHIN THAT CONSTRAINT, permission to use, copy, modify, and
 * distribute this software and its documentation for any purpose and
 * without fee is hereby granted, provided that the above copyright
 * notice appear in all copies and that both that copyright notice and
 * this permission notice appear in supporting documentation, and that
 * the name of M.I.T. not be used in advertising or publicity pertaining
 * to distribution of the software without specific, written prior
 * permission.  M.I.T. makes no representations about the suitability of
 * this software for any purpose.  It is provided "as is" without express
 * or implied warranty.
 * 
 *
 * krb5_free_tkt_authent()
 */


#include <krb5/krb5.h>
#include <krb5/ext-proto.h>

void
krb5_free_tkt_authent(context, val)
    krb5_context context;
    krb5_tkt_authent *val;
{
    if (val->ticket)
	    krb5_free_ticket(context, val->ticket);
    if (val->authenticator)
	    krb5_free_authenticator(context, val->authenticator);
    krb5_xfree(val);
    return;
}
