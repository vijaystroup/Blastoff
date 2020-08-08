#include <string>
#include <cmath>
#include "velocimeter.h"
#include "clock.h"

using std::string;

// constructor & destructor
Velocimeter::Velocimeter(Clock* clock) {
    this->data = 0.0;
    this->fake_data = 50.0;
    this->fake_label_data = 0.0;
    this->clock = clock;
}
Velocimeter::~Velocimeter() {}

// data
double Velocimeter::get_data() { return this->data; }
void Velocimeter::set_data() {
    /* fake sensor data gives a exponential function of velocity */

    double const rad_perc = 0.062831853071796; // amount of radians in 1 percent
    int timer = this->clock->get_time();

    if (timer < 0)
        this->data = 50 * rad_perc;
    else if (timer < 30) {
        this->fake_data = this->fake_data - (this->fake_data*0.005);
        this->data = this->fake_data * rad_perc;
        fake_label_data++;
    }
    else
        this->data = 50 * rad_perc;
}

// fake data
double Velocimeter::get_fake_label_data() { return this->fake_label_data; }

// to_string
string Velocimeter::to_string() {
    return "Velocimeter: " + std::to_string(get_data());
}
