#include "clock.h"

Clock::Clock() {
    /* inital time of clock is -3 */

    this->time = -3;
}

Clock::~Clock() {}

void Clock::set_time() {
    this->time++;
}

int Clock::get_time() {
    return this->time;
}
