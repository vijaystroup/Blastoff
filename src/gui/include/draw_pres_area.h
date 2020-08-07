#ifndef DRAW_PRES_AREA_H
#define DRAW_PRES_AREA_H

#include <gtk/gtk.h>

namespace draw_pres_area {
    bool draw(GtkWidget *widget, cairo_t *cr, gpointer data);
}

#endif
