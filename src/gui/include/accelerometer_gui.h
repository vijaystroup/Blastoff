#ifndef ACCELEROMETER_GUI_H
#define ACCELEROMETER_GUI_H

#include <gtkmm/drawingarea.h>

class Accelerometer_Gui : public Gtk::DrawingArea {
public:
    Accelerometer_Gui();
    virtual ~Accelerometer_Gui();

    bool on_draw(const Cairo::RefPtr<Cairo::Context> &cr) override;
    bool on_timeout();
protected:
};

#endif
