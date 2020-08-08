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
    srand(this->clock->get_time());
    double random = this->min + (rand() % (this->max - this->min + 1));

    // v FOR GETTING VALUE FROM PERCENTAGE v
    // value = (percentage * (max - min) / 100) + min

    // this->data = (random - this->min) / (this->max - this->min);
    if (timer < 0)
        this->data = .95;
    else if (timer < 30)
        this->data = this->data - 0.002;
    else
        this->data = 0.95;
    printf("thermo per %f\n", this->data);
}

// to_string
string Thermometer::to_string() {
    return "Thermometer: " + std::to_string(get_data());
}
