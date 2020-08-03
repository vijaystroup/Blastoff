#include <fmt/ranges.h>
#include <ctime>
#include <unistd.h>
#include <gtkmm/application.h>
#include <gtkmm/window.h>
#include "accelerometer.h"
#include "blastoff.h"

using fmt::print;

int main(int argc, char *argv[]) {
    // srand(time(NULL));

    // sensor s("boom", 10, 50);
    // while(true) {
    //     s.set_data();
    //     print("{}\n", s.to_string());
    //     usleep(100000);
    // }

    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

    Gtk::Window win;
    win.set_title("Cairomm Clock");

    Clock c;
    win.add(c);
    c.show();

    return app->run(win);
}
