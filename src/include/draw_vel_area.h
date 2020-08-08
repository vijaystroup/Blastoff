#ifndef DRAW_VEL_AREA_H
#define DRAW_VEL_AREA_H

#include <gtk/gtk.h>
#include "velocimeter.h"

namespace draw_vel_area {
    bool draw(GtkWidget *widget, cairo_t *cr, Velocimeter* vel);
}

#endif
