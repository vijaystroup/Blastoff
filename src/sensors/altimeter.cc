#include <string>
#include <cmath>
#include "altimeter.h"
#include "clock.h"

using std::string;

// constructor & destructor
Altimeter::Altimeter(Clock* clock) {
    this->data = 0.05;
    this->clock = clock;
}
Altimeter::~Altimeter() {}

// data
double Altimeter::get_data() { return this->data; }
void Altimeter::set_data() {
    /* fake sensor data gives an exponential function of altitude */

    int timer = this->clock->get_time();

    if (timer < 0)
        this->data = .05;
    else if (timer < 30)
        this->data = this->data + (this->data*0.01);
    else
        this->data = 0.05;
}

// min/max
int Altimeter::get_min() { return this->min; }
int Altimeter::get_max() { return this->max; }

// to_string
string Altimeter::to_string() {
    return "Altimeter: " + std::to_string(get_data());
}
