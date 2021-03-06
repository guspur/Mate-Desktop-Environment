/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 8; tab-width: 8 -*- */
/* eel-types.h -

   Copyright (C) 2000 Eazel, Inc.

   The Mate Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public License as
   published by the Free Software Foundation; either version 2 of the
   License, or (at your option) any later version.

   The Mate Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public
   License along with the Mate Library; see the file COPYING.LIB.  If not,
   write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.

   Authors: Maciej Stachowiak <mjs@eazel.com>
*/


#include <config.h>
#include <gtk/gtk.h>

#define EEL_COMPILATION 1
#include <eel/eel.h>

#include "eel-type-builtins-vars.c"
#include "eel-type-builtins-evals.c"

void
eel_type_init (void)
{
    int i;
    GType type_id;
    static gboolean initialized = FALSE;

    static struct
    {
        const gchar *type_name;
        GType *type_id;
        GType parent;
        gconstpointer pointer1;
        gpointer pointer2;
    } builtin_info[EEL_TYPE_N_BUILTINS] =
    {
#include "eel-type-builtins-ids.c"
    };

    if (initialized)
    {
        return;
    }
    initialized = TRUE;

    for (i = 0; i < EEL_TYPE_N_BUILTINS; i++)
    {
        type_id = G_TYPE_INVALID;

        if (builtin_info[i].parent == G_TYPE_ENUM)
        {
            type_id = g_enum_register_static (builtin_info[i].type_name,
                                              builtin_info[i].pointer1);
        }
        else if (builtin_info[i].parent == G_TYPE_FLAGS)
        {
            type_id = g_flags_register_static (builtin_info[i].type_name,
                                               builtin_info[i].pointer1);
        }
        else
        {
            g_assert_not_reached ();
        }

        g_assert (type_id != G_TYPE_INVALID);
        *builtin_info[i].type_id = type_id;
    }
}

