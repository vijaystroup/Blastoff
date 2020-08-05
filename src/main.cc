#include <gtkmm.h>
#include <string.h>
#include "setup.h"

using std::string;

int main(int argc, char *argv[]) {
    Gtk::Window* win;
    
    // create application
    auto app = Gtk::Application::create(argc, argv, "com.vijaystroup.BlastOff");

    // get the refrence builder
    string glade_file = "src/gui/outline.glade";
    auto refBuilder = Gtk::Builder::create();
    refBuilder->add_from_file(glade_file);

    // add the glade window and widgets
    refBuilder->get_widget("window", win);
    if (win) {
        // setup gui and run app
        setup(refBuilder);
        app->run(*win);
    }

    delete win;
    return 0;
}
