#ifndef DRAW_THRUST_AREA_H
#define DRAW_THRUST_AREA_H

#include <gtk/gtk.h>
#include "thrust_meter.h"

namespace draw_thrust_area {
    bool draw(GtkWidget *widget, cairo_t *cr, Thrust_Meter* thrust);
}

#endif
