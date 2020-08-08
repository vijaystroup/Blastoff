#include <gtk/gtk.h>
#include <string>
#include "time_handle.h"
#include "clock.h"

// bool run(Gtk::Label* label_timer) {
//     timer++;

//     if (timer > 5) {
//         label_timer->set_text("Launch Complete");
//         return false;
//     }

//     if (timer < 0)
//         label_timer->set_text("T" + std::to_string(timer));
//     else if (timer == 0)
//         label_timer->set_text("T-" + std::to_string(timer));
//     else
//         label_timer->set_text("T+" + std::to_string(timer));

//     return true;
// }

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


    return true;
}

bool time_handler(app_widgets* widgets) {
    if (widgets->clock->get_time() > 30) return false;

    widgets->clock->set_time();
    
    return true;
}

bool button_launch_clicked_cb(GtkWidget* button, app_widgets* widgets) {
    // show timer
    gtk_widget_hide(button);
    gtk_label_set_text((GtkLabel*)widgets->w_label_timer, "T");
    gtk_widget_show(widgets->w_label_timer);

    // start loops
    g_timeout_add_seconds(1, (GSourceFunc)time_handler, widgets);
    g_timeout_add(100, (GSourceFunc)short_time_handler, widgets);

    return true;
}