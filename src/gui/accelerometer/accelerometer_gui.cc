#include <ctime>
#include <cmath>
#include <cairomm/context.h>
#include <glibmm/main.h>
#include "accelerometer_gui.h"
#include "accelerometer.h"

int cur_time = 0;

accelerometer acc("acceleration");

Accelerometer_Gui::Accelerometer_Gui() : m_radius(0.42), m_line_width(0.01) {
    printf("In acc\n");
    Glib::signal_timeout().connect(sigc::mem_fun(*this, &Accelerometer_Gui::on_timeout), 10000);
}
Accelerometer_Gui::~Accelerometer_Gui() {}

bool Accelerometer_Gui::on_draw(const Cairo::RefPtr<Cairo::Context> &cr) {
    printf("in draw\n");
    Gtk::Allocation allocation = get_allocation();
    const int width = allocation.get_width();
    const int height = allocation.get_height();

    // scale to unit square and translate (0, 0) to be (0.5, 0.5), i.e.
    // the center of the window
    cr->scale(width, height);
    cr->translate(0.5, 0.5);
    cr->set_line_width(m_line_width);

    cr->save();
    cr->set_source_rgba(1.0, 1.0, 1.0, 1.9);   // white
    cr->paint();
    cr->restore();
    cr->arc(0, 0, m_radius, M_PI, 2 * M_PI);
    cr->save();
    cr->set_source_rgba(0.85, 0.85, 0.85, 1.0); // lightgrey
    cr->fill_preserve();
    cr->restore();
    cr->stroke_preserve();
    cr->clip();

    //Accelerometer_Gui ticks
    for (int i = 6; i <= 12; i++) {
        double inset = 0.05;

        cr->save();
        cr->set_line_cap(Cairo::LINE_CAP_ROUND);

        cr->move_to(
            (m_radius - inset) * cos(i * M_PI / 6),
            (m_radius - inset) * sin(i * M_PI / 6)
        );
        cr->line_to (
            m_radius * cos(i * M_PI / 6),
            m_radius * sin(i * M_PI / 6)
        );
        cr->stroke();
        cr->restore(); /* stack-pen-size */
    }

    // store the current time
    time_t rawtime;
    time(&rawtime);
    // struct tm * timeinfo = localtime (&rawtime);

    // compute the angles of the indicators of our Accelerometer_Gui
    // double minutes = timeinfo->tm_min * M_PI / 30;
    // double hours = timeinfo->tm_hour * M_PI / 6;
    // double seconds= timeinfo->tm_sec * M_PI / 30;
    double data = acc.get_data() * M_PI / 30;

    cr->save();
    cr->set_line_cap(Cairo::LINE_CAP_ROUND);

    // draw the seconds hand
    cr->save();
    cr->set_source_rgba(0.0, 0.5, 1.0, 1.0); // lightblue
    cr->move_to(0, 0);
    printf("data-> %f\n", data);
    printf("cur_time-> %d\n\n", cur_time);
    cr->line_to(sin(data) * (m_radius * 0.9), cos(data) * (m_radius * 0.9));
    cr->stroke();
    cr->restore();

    // draw a little dot in the middle
    cr->arc(0, 0, m_line_width * 1.2, 0, 2 * M_PI);
    cr->set_source_rgba(0.0, 0.5, 1.0, 1.0); // lightblue
    cr->fill();

    return true;
}


bool Accelerometer_Gui::on_timeout() {
    printf("in timeout\n");
    // force our program to redraw the entire Accelerometer_Gui.
    auto win = get_window();
    if (win) {
        Gdk::Rectangle r(0, 0, get_allocation().get_width(), get_allocation().get_height());
        win->invalidate_rect(r, false);
        acc.set_data(cur_time);
    }

    if (cur_time >= 30)
        // destroy program
        return false;
    return true;
}
