#ifndef SETUP_H
#define SETUP_H

#include <gtkmm.h>

void setup(Glib::RefPtr<Gtk::Builder> &refBuilder);
void launch_clicked(Gtk::Button* button_launch, Gtk::Label* label_timer, Gtk::DrawingArea* draw_acc);
void run(Gtk::Label* label_timer);

#endif