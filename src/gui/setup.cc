#include <gtkmm.h>
#include <glibmm/main.h>
#include <unistd.h>
#include "accelerometer_gui.h"

int timer = -5;

Accelerometer_Gui acc_gui;

void run(Gtk::Label* label_timer) {
    // Gtk::Container* win = static_cast<Gtk::Container*>(label_timer->get_parent());
    // win->add(acc_gui);
    // acc_gui.show();

    // while (timer <= 30) {
    //     if (timer <= 0)
    //         label_timer->set_text("T-" + std::to_string(timer));
    //     else
    //         label_timer->set_text("T+" + std::to_string(timer));

    //     printf("time %d\n", timer);
    //     sleep(1);
    //     timer++;
    // }
    printf("time %d\n", timer);
    timer++;
    printf("done\n");
}

void launch_clicked(Gtk::Button* button_launch, Gtk::Label* label_timer) {
    printf("launch\n");
    button_launch->hide();
    label_timer->show();
    // g_timeout_add_seconds(1, (GSourceFunc)run, label_timer);
    // timeout_add()
    // gtk_widget_queue_draw(1, )
    // run(label_timer);
}

void setup(Glib::RefPtr<Gtk::Builder> &refBuilder) {
    // init widgets
    Gtk::DrawingArea* draw_acc = nullptr;
    Gtk::DrawingArea* draw_vel = nullptr;
    Gtk::DrawingArea* draw_pres = nullptr;
    Gtk::Label* label_data_acc = nullptr;
    Gtk::Label* label_data_vel = nullptr;
    Gtk::Label* label_data_pres = nullptr;
    Gtk::Label* label_data_alt = nullptr;
    Gtk::Label* label_data_temp = nullptr;
    Gtk::ProgressBar* progress_alt = nullptr;
    Gtk::ProgressBar* progress_temp = nullptr;
    Gtk::Button* button_launch = nullptr;
    Gtk::Label* label_timer = nullptr;

    // add refrence to widgets
    refBuilder->get_widget("draw_acc", draw_acc);
    refBuilder->get_widget("draw_vel", draw_vel);
    refBuilder->get_widget("draw_pres", draw_pres);
    refBuilder->get_widget("label_data_acc", label_data_acc);
    refBuilder->get_widget("label_data_vel", label_data_vel);
    refBuilder->get_widget("label_data_pres", label_data_pres);
    refBuilder->get_widget("label_data_alt", label_data_alt);
    refBuilder->get_widget("label_data_temp", label_data_temp);
    refBuilder->get_widget("progress_alt", progress_alt);
    refBuilder->get_widget("progress_temp", progress_temp);
    refBuilder->get_widget("button_launch", button_launch);
    refBuilder->get_widget("label_timer", label_timer);

    // draw_acc->queue_draw();

    // connect launch button
    button_launch->signal_clicked().connect(
        sigc::bind(sigc::ptr_fun(&launch_clicked),
            button_launch, label_timer
        )
    );
    
    // draw_acc->signal_draw().connect(
    //     sigc::ptr_fun(&acc_gui.on_draw);
    // );
}
