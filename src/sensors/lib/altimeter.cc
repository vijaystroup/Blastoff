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
    int timer = this->clock->get_time();

    if (timer < 0)
        this->data = .05;
    else if (timer < 30)
        this->data = this->data + (this->data*0.01);
    else
        this->data = 0.05;
}

// to_string
string Altimeter::to_string() {
    return "Altimeter: " + std::to_string(get_data());
}
