#include <string>
#include <cmath>
#include "barometer.h"
#include "clock.h"

using std::string;

// constructor & destructor
Barometer::Barometer(Clock* clock) {
    this->data = 0.0;
    this->fake_data = 5;
    this->clock = clock;
}
Barometer::~Barometer() {}

// data
double Barometer::get_data() { return this->data; }
void Barometer::set_data() {
    double const rad_perc = 0.062831853071796; // amount of radians in 1 percent
    int timer = this->clock->get_time();

    if (timer < 0)
        this->data = 5 * rad_perc;
    else if (timer < 30) {
        this->fake_data = this->fake_data + .1;
        this->data = this->fake_data * rad_perc;
    }
    else
        this->data = 5 * rad_perc;
}

// to_string
string Barometer::to_string() {
    return "Barometer: " + std::to_string(get_data());
}
