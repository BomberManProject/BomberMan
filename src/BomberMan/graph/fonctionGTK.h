#ifndef _FONCTIONGTK_H
#define _FONCTIONGTK_H

#include <gtk/gtk.h>
#include <cairo.h>

extern GtkWidget* CreationFenetre(int argc, char **argv);
gboolean on_expose_event(GtkWidget *widget,GdkEventExpose *event,gpointer data);
extern int AfficheImage(GtkWidget *window, int argc, char **argv);
gboolean realize_evt_reaction( GtkWidget *widget, gpointer data );
#endif
