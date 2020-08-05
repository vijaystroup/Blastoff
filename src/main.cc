#include <gtkmm.h>
#include <string.h>

using std::string;


void on_button_clicked(Gtk::Button* pButton) {
    printf("hehe\n");
    pButton->hide();
}

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
        // setup gui
        Gtk::Button *button_launch = nullptr;
        refBuilder->get_widget("button_launch", button_launch);
        if (button_launch) {
            button_launch->signal_clicked().connect(sigc::bind(sigc::ptr_fun(&on_button_clicked), button_launch));
        }

        app->run(*win);
    }

    delete win;
    return 0;
}
