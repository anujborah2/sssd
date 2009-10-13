/*
    SSSD

    Kerberos Backend, common header file

    Authors:
        Sumit Bose <sbose@redhat.com>

    Copyright (C) 2009 Red Hat


    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __KRB5_COMMON_H__
#define __KRB5_COMMON_H__

#include "config.h"
#include <stdbool.h>

#include "providers/dp_backend.h"
#include "util/util.h"
#include "util/sss_krb5.h"

#define SSSD_KRB5_KDC "SSSD_KRB5_KDC"
#define SSSD_KRB5_REALM "SSSD_KRB5_REALM"
#define SSSD_KRB5_CHANGEPW_PRINCIPLE "SSSD_KRB5_CHANGEPW_PRINCIPLE"

enum krb5_opts {
    KRB5_KDC = 0,
    KRB5_REALM,
    KRB5_CCACHEDIR,
    KRB5_CCNAME_TMPL,
    KRB5_CHANGEPW_PRINC,
    KRB5_AUTH_TIMEOUT,

    KRB5_OPTS
};

errno_t check_and_export_options(struct dp_option *opts,
                                 struct sss_domain_info *dom);

errno_t krb5_get_options(TALLOC_CTX *memctx, struct confdb_ctx *cdb,
                         const char *conf_path, struct dp_option **_opts);
#endif /* __KRB5_COMMON_H__ */
