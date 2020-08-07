#include <gtk/gtk.h>
#include "time_handle.h"

#include <cairomm/context.h>
#include <cmath>

bool on_draw(GtkWidget *widget, cairo_t *cr, gpointer data) {
    printf("in draw\n");

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
    time_t rawtime;
    time(&rawtime);
    struct tm * timeinfo = localtime (&rawtime);

    double seconds= timeinfo->tm_sec * M_PI / 30;
    // double data = acc.get_data() * M_PI / 30;

    cairo_save(cr);
    cairo_set_line_cap(cr, CAIRO_LINE_CAP_ROUND);
    cairo_save(cr);
    cairo_set_source_rgb(cr, 0.0, 0.5, 1.0); // lightblue
    cairo_move_to(cr, 0, 0);
    // cr->line_to(sin(0) * (radius * 0.95), -cos(0) * (radius * 0.95));
    cairo_line_to(cr,
        sin(seconds) * (radius * 0.95),
        -cos(seconds) * (radius * 0.95)
    );
    cairo_stroke(cr);
    cairo_restore(cr);

    // dot
    cairo_arc(cr, 0, 0, width*.015, 0, 2 * M_PI);
    cairo_set_source_rgb(cr, 0.0, 0.5, 1.0); // lightblue
    cairo_fill(cr);
    cairo_restore(cr);

    return false;
}

void app_destroy() {
    printf("app_destroy\n");
    gtk_main_quit();
}

int main(int argc, char *argv[]) {
    auto glade_file = "src/gui/outline.glade";
    app_widgets* widgets = g_slice_new(app_widgets);
    
    // create application
    gtk_init(&argc, &argv);

    // get the refrence builder
    auto builder = gtk_builder_new();
    gtk_builder_add_from_file(builder, glade_file, NULL);

    // add the glade window and widgets
    auto win = GTK_WIDGET(gtk_builder_get_object(builder, "window"));    
    if (win) {
        // get widgets
        widgets->w_draw_acc         = GTK_WIDGET(gtk_builder_get_object(builder, "draw_acc"));
        widgets->w_draw_vel         = GTK_WIDGET(gtk_builder_get_object(builder, "draw_vel"));
        widgets->w_draw_pres        = GTK_WIDGET(gtk_builder_get_object(builder, "draw_pres"));
        widgets->w_label_data_acc   = GTK_WIDGET(gtk_builder_get_object(builder, "label_data_acc"));
        widgets->w_label_data_vel   = GTK_WIDGET(gtk_builder_get_object(builder, "label_data_vel"));
        widgets->w_label_data_pres  = GTK_WIDGET(gtk_builder_get_object(builder, "label_data_pres"));
        widgets->w_label_data_alt   = GTK_WIDGET(gtk_builder_get_object(builder, "label_data_alt"));
        widgets->w_label_data_temp  = GTK_WIDGET(gtk_builder_get_object(builder, "label_data_temp"));
        widgets->w_progress_alt     = GTK_WIDGET(gtk_builder_get_object(builder, "progress_alt"));
        widgets->w_progress_temp    = GTK_WIDGET(gtk_builder_get_object(builder, "progress_temp"));
        widgets->w_button_launch    = GTK_WIDGET(gtk_builder_get_object(builder, "button_launch"));
        widgets->w_label_timer      = GTK_WIDGET(gtk_builder_get_object(builder, "label_timer"));
        g_object_unref(builder);

        // connect signals
        g_signal_connect(win, "destroy", G_CALLBACK(app_destroy), NULL);
        g_signal_connect(widgets->w_button_launch, "clicked", G_CALLBACK(button_launch_clicked_cb), widgets);
        g_signal_connect(widgets->w_draw_acc, "draw", G_CALLBACK(on_draw), NULL);
        // g_signal_connect(win, "destroy", G_CALLBACK(app_destroy), NULL);
        // g_signal_connect(win, "destroy", G_CALLBACK(app_destroy), NULL);
        // g_signal_connect(win, "destroy", G_CALLBACK(app_destroy), NULL);
        // g_signal_connect(win, "destroy", G_CALLBACK(app_destroy), NULL);
        // g_signal_connect(win, "destroy", G_CALLBACK(app_destroy), NULL);
        // g_signal_connect(win, "destroy", G_CALLBACK(app_destroy), NULL);
        // g_signal_connect(win, "destroy", G_CALLBACK(app_destroy), NULL);
        // g_signal_connect(win, "destroy", G_CALLBACK(app_destroy), NULL);
        // g_signal_connect(win, "destroy", G_CALLBACK(app_destroy), NULL);


        gtk_window_set_resizable(GTK_WINDOW(win), false);
        gtk_widget_show(win);
        gtk_main();
    }

    g_slice_free(app_widgets, widgets);
    return 0;
}
