// #include "accelerometer_gui.h"
#include <gtk/gtk.h>
#include <cmath>
#include <cairomm/context.h>

bool on_draw_1(const Cairo::RefPtr<Cairo::Context> &cr) {
    printf("in draw\n");

    // constants
    const int width = 250;
    const int height = 150;
    const double inset = 3.5;
    const int radius = 100;

    // properties
    cr->translate(width/2, height/1.2);
    cr->save();

    // arc
    cr->restore();
    cr->set_source_rgb(0.8, 0.8, 0.8);
    cr->arc(0, 0, radius, M_PI, 2 * M_PI);
    cr->save();
    cr->set_source_rgb(0.8, 0.8, 0.8); // lightgrey
    cr->fill_preserve();
    cr->restore();
    cr->stroke_preserve();
    cr->clip();

    // ticks
    for (int i = 6; i <= 12; i++) {
        cr->set_source_rgb(0.0, 0.0, 0.0); // black

        cr->save();
        cr->set_line_cap(Cairo::LINE_CAP_ROUND);

        cr->move_to(
            (radius - inset) * cos(i * M_PI / 6),
            (radius - inset) * sin(i * M_PI / 6)
        );
        cr->line_to (
            radius * cos(i * M_PI / 6),
            radius * sin(i * M_PI / 6)
        );
        cr->stroke();
        cr->restore();
    }

    // needle
    time_t rawtime;
    time(&rawtime);
    struct tm * timeinfo = localtime (&rawtime);

    double seconds= timeinfo->tm_sec * M_PI / 30;
    // double data = acc.get_data() * M_PI / 30;

    cr->save();
    cr->set_line_cap(Cairo::LINE_CAP_ROUND);
    cr->save();
    cr->set_source_rgb(0.0, 0.5, 1.0); // lightblue
    cr->move_to(0, 0);
    // cr->line_to(sin(0) * (radius * 0.95), -cos(0) * (radius * 0.95));
    cr->line_to(sin(seconds) * (radius * 0.95), -cos(seconds) * (radius * 0.95));
    cr->stroke();
    cr->restore();

    // dot
    cr->arc(0, 0, width*.015, 0, 2 * M_PI);
    cr->set_source_rgb(0.0, 0.5, 1.0); // lightblue
    cr->fill();
    cr->restore();

    return true;
}






int timer = -3;





bool run(Gtk::Label* label_timer) {
    timer++;

    if (timer > 5) {
        label_timer->set_text("Launch Complete");
        return false;
    }

    if (timer < 0)
        label_timer->set_text("T" + std::to_string(timer));
    else if (timer == 0)
        label_timer->set_text("T-" + std::to_string(timer));
    else
        label_timer->set_text("T+" + std::to_string(timer));

    return true;
}

bool keep_test(Gtk::DrawingArea* draw_acc) {
    printf("keep_test\n");
    // draw_acc->signal_draw().connect(sigc::ptr_fun(&test));
    draw_acc->queue_draw();
    return true;
}

void launch_clicked(Gtk::Button* button_launch, Gtk::Label* label_timer) {
    printf("launch button\n");
    button_launch->hide();
    label_timer->set_text("T" + std::to_string(timer));
    label_timer->show();
    g_timeout_add_seconds(1, (GSourceFunc)run, label_timer);
}

void setup(GtkBuilder* refBuilder, app_widgets widgets) {
    // connect widget signals
    


    // init widgets

    // add refrence to widgets
    refBuilder->get_widget("draw_acc", draw_acc);
    // refBuilder->get_widget("draw_vel", draw_vel);
    // refBuilder->get_widget("draw_pres", draw_pres);
    // refBuilder->get_widget("label_data_acc", label_data_acc);
    // refBuilder->get_widget("label_data_vel", label_data_vel);
    // refBuilder->get_widget("label_data_pres", label_data_pres);
    // refBuilder->get_widget("label_data_alt", label_data_alt);
    // refBuilder->get_widget("label_data_temp", label_data_temp);
    // refBuilder->get_widget("progress_alt", progress_alt);
    // refBuilder->get_widget("progress_temp", progress_temp);
    refBuilder->get_widget("button_launch", button_launch);
    refBuilder->get_widget("label_timer", label_timer);

    
}
