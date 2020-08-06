#include <string>
#include "thermometer.h"

using std::string;

// constructor
thermometer::thermometer(string name, int min, int max) {
    set_name(name);
    this->data = 0;
    this->min = min;
    this->max = max;
}

// name
string thermometer::get_name() { return this->name; }
void thermometer::set_name(string name) { this->name = name; }

// data
int thermometer::get_data() { return this->data; }
void thermometer::set_data() {
    this->data = this->min + (rand() % (this->max - this->min + 1));
}

// to_string
string thermometer::to_string() {
    return get_name() + ": " + std::to_string(get_data());
}
