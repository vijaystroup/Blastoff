#ifndef BLASTOFF_H
#define BLASTOFF_H

#include <gtkmm/drawingarea.h>

class Clock : public Gtk::DrawingArea {
public:
    Clock();
    virtual ~Clock();

protected:
    //Override default signal handler
    bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;

    bool on_timeout();

    double m_radius;
    double m_line_width;
};

#endif
