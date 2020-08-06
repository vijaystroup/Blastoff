#include <gtkmm.h>
#include <string.h>
#include "setup.h"

using std::string;

int main(int argc, char *argv[]) {
    Gtk::Window* win = nullptr;
    string glade_file = "src/gui/outline.glade";
    string app_identifier = "com.vijaystroup.BlastOff";
    
    // create application
    auto app = Gtk::Application::create(argc, argv, app_identifier);

    // get the refrence builder
    auto refBuilder = Gtk::Builder::create();
    refBuilder->add_from_file(glade_file);

    // add the glade window and widgets
    refBuilder->get_widget("window", win);
    if (win) {
        // setup gui and run app
        win->set_resizable(false);
        setup(refBuilder);
        app->run(*win);
    }

    delete win;
    return 0;
}
