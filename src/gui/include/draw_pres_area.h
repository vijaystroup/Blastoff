#ifndef DRAW_PRES_AREA_H
#define DRAW_PRES_AREA_H

#include <gtk/gtk.h>
#include "barometer.h"

namespace draw_pres_area {
    bool draw(GtkWidget *widget, cairo_t *cr, Barometer* pres);
}

#endif
