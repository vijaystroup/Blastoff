#ifndef TIMER_H
#define TIMER_H

#include <string.h>

using std::string;

class Timer {
private:
    int timer = -5;
    string content;

public:
    Timer();
    ~Timer();

    void inc_timer();
    int get_timer();
};

#endif
