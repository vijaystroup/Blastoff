#include <ctime>
#include <cmath>
#include <cairomm/context.h>
#include <glibmm/main.h>
#include "accelerometer_gui.h"

int var = 0;

Accelerometer_Gui::Accelerometer_Gui() {
    printf("In acc\n");
    Glib::signal_timeout().connect(sigc::mem_fun(*this, &Accelerometer_Gui::on_timeout), 1000);
}
Accelerometer_Gui::~Accelerometer_Gui() {}

bool Accelerometer_Gui::on_draw(const Cairo::RefPtr<Cairo::Context> &cr) {
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


bool Accelerometer_Gui::on_timeout() {
    printf("in timeout\n");
    
    return true;
}
