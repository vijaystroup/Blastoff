#ifndef BLASTOFF_H
#define BLASTOFF_H

#include <gtkmm/button.h>
#include <gtkmm/window.h>

class Blastoff : public Gtk::Window {
public:
    Blastoff();
    virtual ~Blastoff();

protected:
    //Signal handlers:
    void on_button_clicked();

    //Member widgets:
    Gtk::Button m_button;
};

#endif
