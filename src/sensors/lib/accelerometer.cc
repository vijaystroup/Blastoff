#include <string>
#include "accelerometer.h"

using std::string;

// constructor
accelerometer::accelerometer() {
    this->data = 0;
}

// data
int accelerometer::get_data() { return this->data; }
void accelerometer::set_data(int timer) {
    if (timer < 0)
        this->data = 0;
    else {
        if (timer <= 10)
            this->data = 100;
        else if (timer >= 11 && timer < 25)
            this->data = (1 / (timer * 0.1)) * 100;
        else
            this->data = 0;
    }
}

// to_string
string accelerometer::to_string() {
    return "accelerometer: " + std::to_string(get_data());
}
