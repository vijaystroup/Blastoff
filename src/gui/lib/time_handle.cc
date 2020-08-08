#include <gtk/gtk.h>
#include <string>
#include <math.h>
#include "time_handle.h"
#include "clock.h"

using std::string;

#include <cmath>
bool short_time_handler(app_widgets* widgets) {
    if (widgets->clock->get_time() > 30) return false;

    // queue drawing areas
    gtk_widget_queue_draw(widgets->w_draw_thrust);
    gtk_widget_queue_draw(widgets->w_draw_vel);
    gtk_widget_queue_draw(widgets->w_draw_pres);

    // queue progress bars
    gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(widgets->w_progress_alt), widgets->alt->get_data());
    gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(widgets->w_progress_temp), widgets->temp->get_data());
    widgets->alt->set_data();
    widgets->temp->set_data();

    // update data labels
    // widgets->l_data_thrust = std::to_string(widgets->) + " %";
    // widgets->l_data_vel    = std::to_string + " km^-1";
    // widgets->l_data_pres   = std::to_string + " kPa";
    widgets->l_data_alt    = (
        std::to_string(widgets->alt->get_data() * (widgets->alt->get_max() - widgets->alt->get_min()) + widgets->alt->get_min()) + " m"
    );
    widgets->l_data_temp   = (
        std::to_string(widgets->temp->get_data() * (widgets->temp->get_max() - widgets->temp->get_min()) + widgets->temp->get_min()) + " C"
    );
    



    gtk_label_set_text((GtkLabel*)widgets->w_label_data_thrust, widgets->l_data_thrust.c_str());
    gtk_label_set_text((GtkLabel*)widgets->w_label_data_vel, widgets->l_data_vel.c_str());
    gtk_label_set_text((GtkLabel*)widgets->w_label_data_pres, widgets->l_data_pres.c_str());
    gtk_label_set_text((GtkLabel*)widgets->w_label_data_alt, widgets->l_data_alt.c_str());
    gtk_label_set_text((GtkLabel*)widgets->w_label_data_temp, widgets->l_data_temp.c_str());

    return true;
}

bool time_handler(app_widgets* widgets) {
    widgets->clock->set_time();
    int timer = widgets->clock->get_time();

    if (timer > 30) {
        widgets->l_timer = "Launch Complete";
        gtk_label_set_text((GtkLabel*)widgets->w_label_timer, widgets->l_timer.c_str());
        return false;
    }

    if (timer < 0) {
        widgets->l_timer = "T" + std::to_string(timer);

        gtk_label_set_text((GtkLabel*)widgets->w_label_timer, widgets->l_timer.c_str());
    }
    else if (timer == 0) {
        widgets->l_timer = "T-" + std::to_string(timer);
        gtk_label_set_text((GtkLabel*)widgets->w_label_timer, widgets->l_timer.c_str());
    }
    else {
        widgets->l_timer = "T+" + std::to_string(timer);
        gtk_label_set_text((GtkLabel*)widgets->w_label_timer, widgets->l_timer.c_str());
    }
    
    return true;
}

bool button_launch_clicked_cb(GtkWidget* button, app_widgets* widgets) {
    // show timer
    gtk_widget_hide(button);
    gtk_label_set_text((GtkLabel*)widgets->w_label_timer, widgets->l_timer.c_str());
    gtk_widget_show(widgets->w_label_timer);

    // start loops
    g_timeout_add_seconds(1, (GSourceFunc)time_handler, widgets);
    g_timeout_add(100, (GSourceFunc)short_time_handler, widgets);

    return true;
}