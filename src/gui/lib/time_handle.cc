#include <gtk/gtk.h>
#include <string>
#include "time_handle.h"

int timer = -3;
std::string timer_text = "T";

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

// void launch_clicked(Gtk::Button* button_launch, Gtk::Label* label_timer) {
//     printf("launch button\n");
//     button_launch->hide();
//     label_timer->set_text("T" + std::to_string(timer));
//     label_timer->show();
//     g_timeout_add_seconds(1, (GSourceFunc)run, label_timer);
// }

bool draw_time_handler(app_widgets* widgets) {
    printf("draw time handler");
    return true;
}

bool time_handler(app_widgets* widgets) {
    printf("time_handler\n");
    
    gtk_widget_queue_draw(widgets->w_draw_acc);
    return true;
}

bool button_launch_clicked_cb(GtkWidget* button, app_widgets* widgets) {
    printf("launch button\n");
    gtk_widget_hide(button);
    gtk_label_set_text((GtkLabel*)widgets->w_label_timer, "T");
    gtk_widget_show(widgets->w_label_timer);
    g_timeout_add_seconds(1, (GSourceFunc)time_handler, widgets);
    g_timeout_add(1000, (GSourceFunc)draw_time_handler, widgets);
    return true;
}