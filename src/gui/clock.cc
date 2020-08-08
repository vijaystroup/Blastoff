#include "clock.h"

Clock::Clock() {
    this->time = -3;
}

Clock::~Clock() {}

void Clock::set_time() {
    this->time++;
}

int Clock::get_time() {
    return this->time;
}
