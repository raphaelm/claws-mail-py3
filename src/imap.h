/*
 * Sylpheed -- a GTK+ based, lightweight, and fast e-mail client
 * Copyright (C) 1999-2007 Hiroyuki Yamamoto and the Claws Mail team
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 * 
 */

#ifndef __IMAP_H__
#define __IMAP_H__

#include "folder.h"

typedef enum
{
	IMAP_AUTH_LOGIN		= 1 << 0,
	IMAP_AUTH_CRAM_MD5	= 1 << 1,
	IMAP_AUTH_ANON		= 1 << 2,
	IMAP_AUTH_GSSAPI	= 1 << 3
} IMAPAuthType;

FolderClass *imap_get_class		(void);
guint imap_folder_get_refcnt(Folder *folder);
void imap_folder_ref(Folder *folder);
void imap_folder_unref(Folder *folder);
gchar imap_get_path_separator_for_item	(FolderItem *item);
void imap_disconnect_all(void);
gint imap_subscribe(Folder *folder, FolderItem *item, gchar *rpath, gboolean sub);
GList *imap_scan_subtree(Folder *folder, FolderItem *item, gboolean unsubs_only, gboolean recursive);
void imap_cache_msg(FolderItem *item, gint msgnum);

void imap_cancel_all(void);
gboolean imap_cancel_all_enabled(void);
#endif /* __IMAP_H__ */
