#include <gtkmm.h>

void on_button_clicked(Gtk::Button* button_launch) {
    printf("launch\n");
    button_launch->hide();
}

void setup(Glib::RefPtr<Gtk::Builder> &refBuilder) {
    Gtk::Button *button_launch = nullptr;
    refBuilder->get_widget("button_launch", button_launch);
    button_launch->signal_clicked().connect(
        sigc::bind(sigc::ptr_fun(&on_button_clicked), button_launch)
    );
}