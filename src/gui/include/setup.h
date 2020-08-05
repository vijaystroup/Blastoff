#ifndef SETUP_H
#define SETUP_H

#include <gtkmm.h>

void setup(Glib::RefPtr<Gtk::Builder> &refBuilder);
void on_button_clicked(Gtk::Button* button_launch);

#endif