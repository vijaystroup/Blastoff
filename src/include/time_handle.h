#ifndef TIME_HANDLE_H
#define TIME_HANDLE_H

#include <gtk/gtk.h>
#include <string>
#include "clock.h"
#include "thrust_meter.h"
#include "velocimeter.h"
#include "barometer.h"
#include "altimeter.h"
#include "thermometer.h"

typedef struct app_widgets {
    // object instances
    Clock* clock;
    Thrust_Meter* thrust;
    Velocimeter* vel;
    Barometer* pres;
    Altimeter* alt;
    Thermometer* temp;

    // label texts
    std::string l_timer;
    std::string l_data_thrust;
    std::string l_data_vel;
    std::string l_data_pres;
    std::string l_data_alt;
    std::string l_data_temp;

    // widgets
    GtkWidget* w_draw_thrust;
    GtkWidget* w_draw_vel;
    GtkWidget* w_draw_pres;
    GtkWidget* w_label_data_thrust;
    GtkWidget* w_label_data_vel;
    GtkWidget* w_label_data_pres;
    GtkWidget* w_label_data_alt;
    GtkWidget* w_label_data_temp;
    GtkWidget* w_progress_alt;
    GtkWidget* w_progress_temp;
    GtkWidget* w_button_launch;
    GtkWidget* w_label_timer;
} app_widgets;

bool short_time_handler(app_widgets* widgets);
bool time_handler(app_widgets* widgets);
bool button_launch_clicked_cb(GtkWidget* button, app_widgets* widgets);

#endif