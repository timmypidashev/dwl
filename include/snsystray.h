/*
 *   SPDX-FileCopyrightText: 2024 Janne Veteläinen <janne.vetelainen@elisanet.fi>
 *
 *   SPDX-License-Identifier: GPL-3.0-only
 */

#ifndef SNSYSTRAY_H
#define SNSYSTRAY_H

#include <glib-object.h>
#include <glib.h>
#include <gtk/gtk.h>

G_BEGIN_DECLS

#define SN_TYPE_SYSTRAY sn_systray_get_type()
G_DECLARE_FINAL_TYPE(SnSystray, sn_systray, SN, SYSTRAY, GtkWidget)

SnSystray *sn_systray_new (int         iconsize,
                           int         margins,
                           int         spacing,
                           const char *host_id);

int   sn_systray_get_height (SnSystray *systray);
char *sn_systray_get_hostid (SnSystray *systray);
int   sn_systray_get_width (SnSystray *systray);

G_END_DECLS

#endif /* SNSYSTRAY_H */
