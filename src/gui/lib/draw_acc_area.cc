#include <gtk/gtk.h>
#include <cmath>
#include "draw_acc_area.h"
#include "accelerometer.h"

bool draw_acc_area::draw(GtkWidget *widget, cairo_t *cr, accelerometer* acc) {
    // constants
    const int width = 250;
    const int height = 150;
    const double inset = 3.5;
    const int radius = 100;

    // properties
    cairo_translate(cr, width / 2, height / 1.2);
    cairo_save(cr);

    // arc
    cairo_restore(cr);
    cairo_set_source_rgb(cr, 0.8, 0.8, 0.8);
    cairo_arc(cr, 0, 0, radius, M_PI, 2 * M_PI);
    cairo_save(cr);
    cairo_set_source_rgb(cr, 0.8, 0.8, 0.8);
    cairo_fill_preserve(cr);
    cairo_restore(cr);
    cairo_stroke_preserve(cr);
    cairo_clip(cr);

    // ticks
    for (int i = 6; i <= 12; i++) {
        cairo_set_source_rgb(cr, 0.0, 0.0, 0.0); //black
        cairo_save(cr);
        cairo_set_line_cap(cr, CAIRO_LINE_CAP_ROUND);

        cairo_move_to(cr, 
            (radius - inset) * cos(i * M_PI / 6),
            (radius - inset) * sin(i * M_PI / 6)
        );

        cairo_line_to(cr, 
            radius * cos(i * M_PI / 6),
            radius * sin(i * M_PI / 6)
        );

        cairo_stroke(cr);
        cairo_restore(cr);
    }

    // needle
    double data = acc->get_data();

    cairo_save(cr);
    cairo_set_line_cap(cr, CAIRO_LINE_CAP_ROUND);
    cairo_save(cr);
    cairo_set_source_rgb(cr, 0.0, 0.5, 1.0); // lightblue
    cairo_move_to(cr, 0, 0);
    cairo_line_to(cr, radius*cos(data), -radius*sin(data));
    cairo_stroke(cr);
    cairo_restore(cr);

    // dot
    cairo_arc(cr, 0, 0, width*.015, 0, 2 * M_PI);
    cairo_set_source_rgb(cr, 0.0, 0.5, 1.0); // lightblue
    cairo_fill(cr);
    cairo_restore(cr);

    acc->set_data();
    return false;
}
