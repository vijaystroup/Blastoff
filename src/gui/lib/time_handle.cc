#include <gtk/gtk.h>
#include <string>
#include "time_handle.h"
#include "clock.h"
#include "draw_acc_area.h"

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

bool draw_time_handler(app_widgets* widgets) {
    gtk_widget_queue_draw(widgets->w_draw_acc);
    gtk_widget_queue_draw(widgets->w_draw_vel);
    gtk_widget_queue_draw(widgets->w_draw_pres);


    return true;
}

bool time_handler(app_widgets* widgets) {
    widgets->clock->set_time();
    
    return true;
}

bool button_launch_clicked_cb(GtkWidget* button, app_widgets* widgets) {
    printf("launch button\n");

    gtk_widget_hide(button);
    gtk_label_set_text((GtkLabel*)widgets->w_label_timer, "T");
    gtk_widget_show(widgets->w_label_timer);
    g_timeout_add_seconds(1, (GSourceFunc)time_handler, widgets);
    g_timeout_add(100, (GSourceFunc)draw_time_handler, widgets);
    return true;
}