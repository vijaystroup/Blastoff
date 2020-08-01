#include <string>
#include "sensor.h"

using std::string;

// constructor
sensor::sensor(string name, int min, int max) {
    set_name(name);
    this->data = -1;
    this->min = min;
    this->max = max;
}

// name
string sensor::get_name() { return this->name; }
void sensor::set_name(string name) { this->name = name; }

// data
int sensor::get_data() {return this->data;}
void sensor::set_data() {
    this->data = this->min + (rand() % (this->max - this->min + 1));
}

// to_string
string sensor::to_string() {
    return "sensor " + get_name() + ": " + std::to_string(get_data());
}
