#ifndef TIME_HANDLE_H
#define TIME_HANDLE_H

#include <gtk/gtk.h>

typedef struct app_widgets {
    GtkWidget* w_draw_acc;
    GtkWidget* w_draw_vel;
    GtkWidget* w_draw_pres;
    GtkWidget* w_label_data_acc;
    GtkWidget* w_label_data_vel;
    GtkWidget* w_label_data_pres;
    GtkWidget* w_label_data_alt;
    GtkWidget* w_label_data_temp;
    GtkWidget* w_progress_alt;
    GtkWidget* w_progress_temp;
    GtkWidget* w_button_launch;
    GtkWidget* w_label_timer;
} app_widgets;

bool time_handler(app_widgets* widgets);
bool button_launch_clicked_cb(GtkWidget* button, app_widgets* widgets);

#endif