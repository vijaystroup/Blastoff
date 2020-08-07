#include <string>
#include <cmath>
#include "velocimeter.h"
#include "clock.h"

using std::string;

// constructor & destructor
Velocimeter::Velocimeter(Clock* clock) {
    this->data = 0.0;
    this->fake_data = 0.0;
    this->clock = clock;
}
Velocimeter::~Velocimeter() {}

// data
double Velocimeter::get_data() { return this->data; }
void Velocimeter::set_data() {
    double const rad_perc = 0.062831853071796; // amount of radians in 1 percent
    int timer = this->clock->get_time();

    if (timer < 0)
        this->data = 50 * rad_perc;
    else {
        if (timer < 10)
            this->data = 0 * rad_perc;
        else if (timer >= 10 && timer <= 25) {
            this->fake_data = this->fake_data + .3;
            this->data = this->fake_data * rad_perc;
        }
        else
            this->data = 50 * rad_perc;
    }
}

// to_string
string Velocimeter::to_string() {
    return "Velocimeter: " + std::to_string(get_data());
}
