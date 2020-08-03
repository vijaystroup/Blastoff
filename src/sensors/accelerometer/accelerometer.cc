#include <string>
#include "accelerometer.h"

using std::string;

// constructor
accelerometer::accelerometer(string name, int min, int max) {
    set_name(name);
    this->data = -1;
    this->min = min;
    this->max = max;
}

// name
string accelerometer::get_name() { return this->name; }
void accelerometer::set_name(string name) { this->name = name; }

// data
int accelerometer::get_data() {return this->data;}
void accelerometer::set_data() {
    this->data = this->min + (rand() % (this->max - this->min + 1));
}

// to_string
string accelerometer::to_string() {
    return "accelerometer " + get_name() + ": " + std::to_string(get_data());
}
