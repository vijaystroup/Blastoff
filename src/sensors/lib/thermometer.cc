#include <string>
#include <cmath>
#include "thermometer.h"
#include "clock.h"

using std::string;

// constructor & destructor
Thermometer::Thermometer(Clock* clock) {
    this->data = 0.95;
    this->clock = clock;
}
Thermometer::~Thermometer() {}

// data
double Thermometer::get_data() { return this->data; }
void Thermometer::set_data() {
    int timer = this->clock->get_time();

    // v FOR GETTING VALUE FROM PERCENTAGE v
    // value = (percentage * (max - min) / 100) + min

    if (timer < 0)
        this->data = .95;
    else if (timer < 30)
        this->data = this->data - 0.002;
    else
        this->data = 0.95;
}

// to_string
string Thermometer::to_string() {
    return "Thermometer: " + std::to_string(get_data());
}
