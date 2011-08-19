/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 8; tab-width: 8 -*-

   caja-thumbnails.h: Thumbnail code for icon factory.
 
   Copyright (C) 2000 Eazel, Inc.
  
   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License as
   published by the Free Software Foundation; either version 2 of the
   License, or (at your option) any later version.
  
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   General Public License for more details.
  
   You should have received a copy of the GNU General Public
   License along with this program; if not, write to the
   Free Software Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.
  
   Author: Andy Hertzfeld <andy@eazel.com>
*/

#ifndef CAJA_THUMBNAILS_H
#define CAJA_THUMBNAILS_H

#include <gdk-pixbuf/gdk-pixbuf.h>
#include <libcaja-private/caja-file.h>

typedef struct CajaThumbnailAsyncLoadHandle CajaThumbnailAsyncLoadHandle;

typedef void (* CajaThumbnailAsyncLoadFunc) (CajaThumbnailAsyncLoadHandle *handle,
						 const char *path,
						 GdkPixbuf  *pixbuf,
						 double      scale_x,
						 double      scale_y,
						 gpointer    user_data);


#define CAJA_THUMBNAIL_FRAME_LEFT 3
#define CAJA_THUMBNAIL_FRAME_TOP 3
#define CAJA_THUMBNAIL_FRAME_RIGHT 3
#define CAJA_THUMBNAIL_FRAME_BOTTOM 3

/* Returns NULL if there's no thumbnail yet. */
void       caja_create_thumbnail                (CajaFile *file);
gboolean   caja_can_thumbnail                   (CajaFile *file);
gboolean   caja_can_thumbnail_internally        (CajaFile *file);
gboolean   caja_thumbnail_is_mimetype_limited_by_size
						    (const char *mime_type);
void       caja_thumbnail_frame_image           (GdkPixbuf **pixbuf);
GdkPixbuf *caja_thumbnail_unframe_image         (GdkPixbuf  *pixbuf);
GdkPixbuf *caja_thumbnail_load_image            (const char *path,
						     guint       base_size,
						     guint       nominal_size,
						     gboolean    force_nominal,
						     double     *scale_x_out,
						     double     *scale_y_out);
CajaThumbnailAsyncLoadHandle *
	   caja_thumbnail_load_image_async	    (const char *path,
						     guint       base_size,
						     guint       nominal_size,
						     gboolean    force_nominal,
						     CajaThumbnailAsyncLoadFunc load_func,
						     gpointer    load_func_user_data);
void       caja_thumbnail_load_image_cancel     (CajaThumbnailAsyncLoadHandle *handle);
void       caja_update_thumbnail_file_copied    (const char   *source_file_uri,
						     const char   *destination_file_uri);
void       caja_update_thumbnail_file_renamed   (const char   *source_file_uri,
						     const char   *destination_file_uri);
void       caja_remove_thumbnail_for_file       (const char   *file_uri);

/* Queue handling: */
void       caja_thumbnail_remove_from_queue     (const char   *file_uri);
void       caja_thumbnail_remove_all_from_queue (void);
void       caja_thumbnail_prioritize            (const char   *file_uri);


#endif /* CAJA_THUMBNAILS_H */
