#include <gtk/gtk.h>
#include <string>
#include "time_handle.h"
#include "thrust_meter.h"
#include "velocimeter.h"
#include "barometer.h"
#include "altimeter.h"
#include "thermometer.h"
#include "draw_thrust_area.h"
#include "draw_vel_area.h"
#include "draw_pres_area.h"
#include <cmath>

using std::string;

void app_destroy() {
    gtk_main_quit();
}

int main(int argc, char *argv[]) {
    auto glade_file = "src/gui/outline.glade";
    app_widgets* widgets = g_slice_new(app_widgets);
    widgets->clock = new Clock();
    
    // data meters
    widgets->thrust = new Thrust_Meter(widgets->clock);
    widgets->vel    = new Velocimeter(widgets->clock);
    widgets->pres   = new Barometer(widgets->clock);
    widgets->alt    = new Altimeter(widgets->clock);
    widgets->temp   = new Thermometer(widgets->clock);

    // initalize strings
    widgets->l_timer       = "T-3";
    widgets->l_data_thrust = "0 %";
    widgets->l_data_vel    = "0 kms^-1";
    widgets->l_data_pres   = "100 kPa";
    widgets->l_data_alt    = "200 m";
    widgets->l_data_temp   = "35.9 C";

    // create application
    gtk_init(&argc, &argv);

    // get the refrence builder
    auto builder = gtk_builder_new();
    gtk_builder_add_from_file(builder, glade_file, NULL);

    // add the glade window and widgets
    auto win = GTK_WIDGET(gtk_builder_get_object(builder, "window"));    
    if (win) {
        // get widgets
        widgets->w_draw_thrust       = GTK_WIDGET(gtk_builder_get_object(builder, "draw_thrust"));
        widgets->w_draw_vel          = GTK_WIDGET(gtk_builder_get_object(builder, "draw_vel"));
        widgets->w_draw_pres         = GTK_WIDGET(gtk_builder_get_object(builder, "draw_pres"));
        widgets->w_label_data_thrust = GTK_WIDGET(gtk_builder_get_object(builder, "label_data_thrust"));
        widgets->w_label_data_vel    = GTK_WIDGET(gtk_builder_get_object(builder, "label_data_vel"));
        widgets->w_label_data_pres   = GTK_WIDGET(gtk_builder_get_object(builder, "label_data_pres"));
        widgets->w_label_data_alt    = GTK_WIDGET(gtk_builder_get_object(builder, "label_data_alt"));
        widgets->w_label_data_temp   = GTK_WIDGET(gtk_builder_get_object(builder, "label_data_temp"));
        widgets->w_progress_alt      = GTK_WIDGET(gtk_builder_get_object(builder, "progress_alt"));
        widgets->w_progress_temp     = GTK_WIDGET(gtk_builder_get_object(builder, "progress_temp"));
        widgets->w_button_launch     = GTK_WIDGET(gtk_builder_get_object(builder, "button_launch"));
        widgets->w_label_timer       = GTK_WIDGET(gtk_builder_get_object(builder, "label_timer"));
        g_object_unref(builder);

        // connect necessary signals
        g_signal_connect(win, "destroy", G_CALLBACK(app_destroy), NULL);
        g_signal_connect(widgets->w_button_launch, "clicked", G_CALLBACK(button_launch_clicked_cb), widgets);
        g_signal_connect(widgets->w_draw_thrust, "draw", G_CALLBACK(draw_thrust_area::draw), widgets->thrust);
        g_signal_connect(widgets->w_draw_vel, "draw", G_CALLBACK(draw_vel_area::draw), widgets->vel);
        g_signal_connect(widgets->w_draw_pres, "draw", G_CALLBACK(draw_pres_area::draw), widgets->pres);

        // run app
        gtk_window_set_resizable(GTK_WINDOW(win), false);
        gtk_widget_show(win);
        gtk_main();
    }

    g_slice_free(app_widgets, widgets);
    return 0;
}
