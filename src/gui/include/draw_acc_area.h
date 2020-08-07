#ifndef DRAW_ACC_AREA_H
#define DRAW_ACC_AREA_H

#include <gtk/gtk.h>
#include "accelerometer.h"

namespace draw_acc_area {
    bool draw(GtkWidget *widget, cairo_t *cr, accelerometer* acc);
}

#endif
