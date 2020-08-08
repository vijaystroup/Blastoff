#include <string>
#include <cmath>
#include "thrust_meter.h"
#include "clock.h"

using std::string;

// constructor & destructor
Thrust_Meter::Thrust_Meter(Clock* clock) {
    this->clock = clock;
    this->data = 0.0;
    this->fake_data = 0.0;
    this->fake_label_data = 100;
}
Thrust_Meter::~Thrust_Meter() {}

// data
double Thrust_Meter::get_data() { return this->data; }
void Thrust_Meter::set_data() {
    double const rad_perc = 0.062831853071796; // amount of radians in 1 percent
    int timer = this->clock->get_time();

    if (timer < 0) {
        this->data = 50 * rad_perc;
        this->fake_label_data = 0;
    }
    else {
        if (timer < 10) {
            this->data = 0 * rad_perc;
            this->fake_label_data = 100;
        }
        else if (timer < 30) {
            this->fake_data = this->fake_data + .25;
            this->data = this->fake_data * rad_perc;
            this->fake_label_data = this->fake_label_data - .5;
        }
        else {
            this->data = 50 * rad_perc;
            this->fake_label_data = 0;
        }
    }
}

// fake data
double Thrust_Meter::get_fake_label_data() { return this->fake_label_data; }

// to_string
string Thrust_Meter::to_string() {
    return "Thrust_Meter: " + std::to_string(get_data());
}
