#include <gtkmm.h>
#include <unistd.h>
#include <gtk/gtk.h>
#include <cairomm/context.h>
#include <gtkmm/drawingarea.h>


int timer = -5;

bool on_draw1_draw(const Cairo::RefPtr<Cairo::Context>& cr)
{
    printf("KEKW\n");
    // Gtk::Allocation allocation = get_allocation();
    const int width = 250;
    const int height = 150;

    // coordinates for the center of the window
    int xc, yc;
    xc = width / 2;
    yc = height / 2;

    cr->set_line_width(10.0);

    // draw red lines out from the center of the window
    cr->set_source_rgb(0.8, 0.0, 0.0);
    cr->move_to(0, 0);
    cr->line_to(xc, yc);
    cr->line_to(0, height);
    cr->move_to(xc, yc);
    cr->line_to(width, yc);
    cr->stroke();

    return true;
}

// bool on_draw1_draw(GtkWidget *widget, cairo_t *cr, gpointer data) {
//     printf("in draw\n");
// }

bool run(Gtk::Label* label_timer) {
    
    timer++;

    if (timer > 5) {
        label_timer->set_text("Launch Complete");
        return false;
    }
    // Gtk::Container* win = static_cast<Gtk::Container*>(label_timer->get_parent());
    // win->add(acc_gui);
    // acc_gui->show();
    // draw_acc->queue_draw();

    // while (timer <= 30) {
    if (timer < 0)
        label_timer->set_text("T" + std::to_string(timer));
    else if (timer == 0)
        label_timer->set_text("T-" + std::to_string(timer));
    else
        label_timer->set_text("T+" + std::to_string(timer));

    return true;
}

void launch_clicked(Gtk::Button* button_launch, Gtk::Label* label_timer, Gtk::DrawingArea* draw_acc) {
    
    printf("launch\n");
    button_launch->hide();
    label_timer->show();
    g_timeout_add_seconds(1, (GSourceFunc)run, label_timer);
}

void setup(Glib::RefPtr<Gtk::Builder> &refBuilder) {
    // init widgets
    Gtk::DrawingArea* draw_acc = nullptr;
    // Gtk::DrawingArea* draw_vel = nullptr;
    // Gtk::DrawingArea* draw_pres = nullptr;
    // Gtk::Label* label_data_acc = nullptr;
    // Gtk::Label* label_data_vel = nullptr;
    // Gtk::Label* label_data_pres = nullptr;
    // Gtk::Label* label_data_alt = nullptr;
    // Gtk::Label* label_data_temp = nullptr;
    // Gtk::ProgressBar* progress_alt = nullptr;
    // Gtk::ProgressBar* progress_temp = nullptr;
    Gtk::Button* button_launch = nullptr;
    Gtk::Label* label_timer = nullptr;

    // add refrence to widgets
    refBuilder->get_widget("draw_acc", draw_acc);
    // refBuilder->get_widget("draw_vel", draw_vel);
    // refBuilder->get_widget("draw_pres", draw_pres);
    // refBuilder->get_widget("label_data_acc", label_data_acc);
    // refBuilder->get_widget("label_data_vel", label_data_vel);
    // refBuilder->get_widget("label_data_pres", label_data_pres);
    // refBuilder->get_widget("label_data_alt", label_data_alt);
    // refBuilder->get_widget("label_data_temp", label_data_temp);
    // refBuilder->get_widget("progress_alt", progress_alt);
    // refBuilder->get_widget("progress_temp", progress_temp);
    refBuilder->get_widget("button_launch", button_launch);
    refBuilder->get_widget("label_timer", label_timer);

    draw_acc->queue_draw();

    // connect launch button
    button_launch->signal_clicked().connect(
        sigc::bind(sigc::ptr_fun(&launch_clicked),
            button_launch, label_timer, draw_acc
        )
    );
    draw_acc->signal_draw().connect(
        sigc::ptr_fun(&on_draw1_draw)
    );
}
