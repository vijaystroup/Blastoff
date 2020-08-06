#ifndef SETUP_H
#define SETUP_H

#include <gtkmm.h>
#include <cairomm/context.h>

void setup(Glib::RefPtr<Gtk::Builder> &refBuilder);
void launch_clicked(Gtk::Button* button_launch, Gtk::Label* label_timer);
bool test(const Cairo::RefPtr<Cairo::Context> &cr, std::string method);
bool run(Gtk::Label* label_timer);

#endif