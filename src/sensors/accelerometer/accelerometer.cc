#include <string>
#include "accelerometer.h"

using std::string;

// constructor
accelerometer::accelerometer(string name) {
    set_name(name);
    this->data = 0;
}

// name
string accelerometer::get_name() { return this->name; }
void accelerometer::set_name(string name) { this->name = name; }

// data
int accelerometer::get_data() { return this->data; }
void accelerometer::set_data(int cur_time) {
    // this->data = this->min + (rand() % (this->max - this->min + 1));

    if (cur_time < 0)
        this->data = 0;
    else {
        if (cur_time <= 10)
            this->data = 100;
        else if (cur_time >= 11 && cur_time < 25)
            this->data = (1 / (cur_time * 0.1)) * 100;
        else
            this->data = 0;
    }
}

// to_string
string accelerometer::to_string() {
    return get_name() + ": " + std::to_string(get_data());
}
