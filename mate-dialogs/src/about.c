/*
 * about.c
 *
 * Copyright (C) 2002 Sun Microsystems, Inc.
 * Copyright (C) 2001 CodeFactory AB
 * Copyright (C) 2001, 2002 Anders Carlsson
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
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 *
 * Authors: Glynn Foster <glynn.foster@sun.com>
 *          Anders Carlsson <andersca@gnu.org>
 */

#include "config.h"
#include "matedialog.h"
#include "util.h"
#include <string.h>
#include <gdk/gdkkeysyms.h>

#define GTK_RESPONSE_CREDITS 0
#define MATEDIALOG_HELP_PATH MATEDIALOG_DATADIR "/help/"
#define MATEDIALOG_CLOTHES_PATH MATEDIALOG_DATADIR "/clothes/"

#define MATEDIALOG_CANVAS_X 400.0
#define MATEDIALOG_CANVAS_Y 280.0

static GtkWidget *dialog;

static void matedialog_about_display_help (GtkWidget *widget, gpointer data);
static void matedialog_about_dialog_response (GtkWidget *widget, int response, gpointer data);

/* Sync with the people in the THANKS file */
static const gchar *const authors[] = {
  "Glynn Foster <glynn foster sun com>",
  "Lucas Rocha <lucasr mate org>",
  "Mike Newman <mikegtn mate org>",
  NULL
};

static const char *documenters[] = {
  "Glynn Foster <glynn.foster@sun.com>",
  "Lucas Rocha <lucasr@gnome.org>",
  "Java Desktop System Documentation Team",
  "MATE Documentation Project",
  NULL
};

static gchar *translators;

static const char *license[] = {
	N_("This program is free software; you can redistribute it and/or modify "
	   "it under the terms of the GNU Lesser General Public License as published by "
	   "the Free Software Foundation; either version 2 of the License, or "
	   "(at your option) any later version.\n"),
	N_("This program is distributed in the hope that it will be useful, "
	   "but WITHOUT ANY WARRANTY; without even the implied warranty of "
	   "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the "
	   "GNU Lesser General Public License for more details.\n"),
	N_("You should have received a copy of the GNU Lesser General Public License "
	   "along with this program; if not, write to the Free Software "
	   "Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.")
};

#if 0
static gint
matedialog_move_clothes_event (MateCanvasItem *item,
                           GdkEvent *event,
                           gpointer data)
{
  static double x, y;
  double new_x, new_y;
  static int dragging;
  double item_x, item_y;

  /* set item_[xy] to the event x,y position in the parent's
   * item-relative coordinates
   */

  item_x = event->button.x;
  item_y = event->button.y;
  mate_canvas_item_w2i (item->parent, &item_x, &item_y);

  switch (event->type) {
    case GDK_BUTTON_PRESS:
      x = item_x;
      y = item_y;
      mate_canvas_item_ungrab (item, event->button.time);
      mate_canvas_item_raise_to_top (item);
      dragging = TRUE;
      break;

    case GDK_MOTION_NOTIFY:
      if (dragging && (event->motion.state & GDK_BUTTON1_MASK)) {
        new_x = item_x;
        new_y = item_y;

        mate_canvas_item_move (item, new_x - x, new_y - y);
        x = new_x;
        y = new_y;
      }
      break;

    case GDK_BUTTON_RELEASE:
      mate_canvas_item_ungrab (item, event->button.time);
      dragging = FALSE;
      break;

    default:
      break;
  }

  return FALSE;
}

typedef struct
{
  const gchar *filename;
  gdouble x, y;
} MonkClothes;

static const MonkClothes monk_clothes[] = {
  {"mate-tshirt.png", 30.0, 20.0},
  {"sunglasses.png", MATEDIALOG_CANVAS_X - 100.0 , MATEDIALOG_CANVAS_Y - 150.0 },
  {"surfboard.png", 30.0, MATEDIALOG_CANVAS_Y - 200.0},
  {"hawaii-shirt.png", MATEDIALOG_CANVAS_X - 50.0, 20.0}
};

static void
matedialog_create_clothes (GtkWidget *canvas_board)
{
  GdkPixbuf *pixbuf;
  MateCanvasItem *canvas_item;
  gchar *pixbuf_path;
  size_t i;

  for (i = 0; i < G_N_ELEMENTS (monk_clothes); i++) {
    pixbuf_path = g_strconcat (MATEDIALOG_CLOTHES_PATH, monk_clothes[i].filename, NULL);
    pixbuf = gdk_pixbuf_new_from_file (pixbuf_path, NULL);

    canvas_item = mate_canvas_item_new (MATE_CANVAS_GROUP (MATE_CANVAS (canvas_board)->root),
                                         MATE_TYPE_CANVAS_PIXBUF,
                                         "x", monk_clothes[i].x,
                                         "y", monk_clothes[i].y,
                                         "pixbuf", pixbuf,
                                         "anchor", GTK_ANCHOR_NW,
                                          NULL);
    g_signal_connect (G_OBJECT (canvas_item), "event",
                      G_CALLBACK (matedialog_move_clothes_event), NULL);
  }
}

static GtkWidget *
matedialog_create_monk (void)
{
  GtkWidget *canvas_board;
  MateCanvasItem *canvas_item;
  GdkPixbuf *pixbuf;
  GdkColor color = { 0, 0xffff, 0xffff, 0xffff };

  canvas_board = mate_canvas_new ();

  mate_canvas_set_scroll_region (MATE_CANVAS (canvas_board), 0, 0,
                                  MATEDIALOG_CANVAS_X, MATEDIALOG_CANVAS_Y);

  gtk_widget_set_size_request (canvas_board, MATEDIALOG_CANVAS_X, MATEDIALOG_CANVAS_Y);

  gdk_colormap_alloc_color (gtk_widget_get_colormap (GTK_WIDGET (canvas_board)),
                            &color, FALSE, TRUE);

  gtk_widget_modify_bg (GTK_WIDGET (canvas_board), GTK_STATE_NORMAL, &color);

  pixbuf = gdk_pixbuf_new_from_file (MATEDIALOG_CLOTHES_PATH "monk.png", NULL);

  canvas_item = mate_canvas_item_new (MATE_CANVAS_GROUP (MATE_CANVAS (canvas_board)->root),
                                       MATE_TYPE_CANVAS_PIXBUF,
                                       "x", (MATEDIALOG_CANVAS_X / 2.0)/2.0 + 10.0,
                                       "y", (MATEDIALOG_CANVAS_Y / 2.0)/2.0 - 50.0,
                                       "pixbuf", pixbuf,
                                       "anchor", GTK_ANCHOR_NW,
                                       NULL);

  matedialog_create_clothes (canvas_board);

  return canvas_board;
}

static GtkWidget *
matedialog_create_boutique (void)
{
  GtkWidget *window;
  GtkWidget *canvas;

  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);

  matedialog_util_set_window_icon (window, NULL, MATEDIALOG_IMAGE_FULLPATH ("matedialog.png"));
  canvas = matedialog_create_monk ();
  gtk_container_add (GTK_CONTAINER (window), canvas);

  return window;
}

static gboolean
matedialog_zen_wisdom (GtkDialog *dialog, GdkEventKey *event, gpointer user_data)
{
  static gint string_count;

  if (string_count >= 3)
    return FALSE;

  switch (event->keyval) {
    case GDK_N:
    case GDK_n:
      if (string_count == 2) {
        GtkWidget *window;
        window = matedialog_create_boutique ();
        gtk_widget_show_all (window);
        string_count++;
      } else {
        string_count = 0;
      }
      break;
    case GDK_Z:
    case GDK_z:
      if (string_count == 0)
        string_count++;
      else
        string_count = 0;
      break;
    case GDK_E:
    case GDK_e:
      if (string_count == 1)
        string_count++;
      else
        string_count = 0;
      break;
    default:
      string_count = 0;
  }

  return FALSE;
}
#endif

void
matedialog_about (MateDialogData *data)
{
  GdkPixbuf *logo;
  GtkWidget *help_button;
  char *license_trans;


  translators = _("translator-credits");
  logo = gdk_pixbuf_new_from_file (MATEDIALOG_IMAGE_FULLPATH ("matedialog.png"), NULL);

  license_trans = g_strconcat (_(license[0]), "\n", _(license[1]), "\n",
                               _(license[2]), "\n", NULL);

  dialog = gtk_about_dialog_new ();

  g_object_set (G_OBJECT (dialog),
                "name", "MateDialog",
                "version", VERSION,
                "copyright", "Copyright \xc2\xa9 2003 Sun Microsystems",
                "comments", _("Display dialog boxes from shell scripts"),
		"authors", authors,
                "documenters", documenters,
                "translator-credits", translators,
                "website", "http://live.gnome.org/MateDialog",
                "logo", logo,
                "wrap-license", TRUE,
                "license", license_trans,
		NULL);

  g_free (license_trans);

  matedialog_util_set_window_icon (dialog, NULL, MATEDIALOG_IMAGE_FULLPATH ("matedialog.png"));

  help_button = gtk_button_new_from_stock (GTK_STOCK_HELP);

  g_signal_connect (G_OBJECT (help_button), "clicked",
                    G_CALLBACK (matedialog_about_display_help), data);

  gtk_widget_show (help_button);

  gtk_box_pack_end (GTK_BOX (gtk_dialog_get_action_area (GTK_DIALOG (dialog))),
                    help_button, FALSE, TRUE, 0);
  gtk_button_box_set_child_secondary (GTK_BUTTON_BOX (gtk_dialog_get_action_area (GTK_DIALOG (dialog))),
                                      help_button, TRUE);

  g_signal_connect (G_OBJECT (dialog), "response",
                    G_CALLBACK (matedialog_about_dialog_response), data);

#if 0
  g_signal_connect (G_OBJECT (dialog), "key_press_event",
                    G_CALLBACK (matedialog_zen_wisdom), NULL);
#endif

  matedialog_util_show_dialog (dialog);
  gtk_main ();
}

static void
matedialog_about_dialog_response (GtkWidget *widget, int response, gpointer data)
{
  MateDialogData *zen_data = data;

  switch (response) {
    case GTK_RESPONSE_CLOSE:
      zen_data->exit_code = matedialog_util_return_exit_code (MATEDIALOG_OK);
      break;

    default:
      /* Esc dialog */
      zen_data->exit_code = matedialog_util_return_exit_code (MATEDIALOG_ESC);
      break;
  }

  gtk_main_quit ();
}

static void
matedialog_about_display_help (GtkWidget *widget, gpointer data)
{
  matedialog_util_show_help (NULL);
}
