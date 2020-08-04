#include <gtkmm/application.h>
#include <gtkmm/window.h>
#include "accelerometer_gui.h"
#include "velocimeter_gui.h"


int main(int argc, char *argv[]) {
    auto app = Gtk::Application::create(argc, argv, "com.vijaystroup.BlastOff");

    Gtk::Window win;
    win.set_title("BlastOff");

    Accelerometer_Gui acc;
    Velocimeter_Gui vel;
    
    

    win.add(acc);
    acc.show();
    win.add(vel);
    vel.show();

    return app->run(win);
}
