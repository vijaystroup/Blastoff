#include <glibmm/main.h>
#include <string.h>
#include "timer.h"

using std::string;

Timer::Timer() {
    Glib::signal_timeout().connect(
        sigc::mem_fun(*this, &Timer::inc_timer), 10000
    );
}

Timer::~Timer() {

}

class Timer::Timer {
private:
    int timer = -5;

public:
    Timer();
    ~Timer();

    void inc_timer();
    int get_timer();
};