/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 8; tab-width: 8 -*- */

/* Signal handlers to enable undo in Gtk Widgets.
 *
 * Copyright (C) 2000 Eazel, Inc.
 *
 * Author: Gene Z. Ragan <gzr@eazel.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#ifndef CAJA_UNDO_SIGNAL_HANDLERS_H
#define CAJA_UNDO_SIGNAL_HANDLERS_H

#include <libcaja-private/caja-entry.h>

void caja_undo_set_up_caja_entry_for_undo 	(CajaEntry	*entry);
void caja_undo_tear_down_caja_entry_for_undo 	(CajaEntry	*entry);
void caja_undo_set_up_editable_for_undo 		(GtkEditable 	*editable);
void caja_undo_tear_down_editable_for_undo 		(GtkEditable 	*editable);
void caja_undo_editable_set_undo_key 		(GtkEditable 	*editable,
        gboolean 	value);

#endif /* CAJA_UNDO_SIGNAL_HANDLERS_H */
