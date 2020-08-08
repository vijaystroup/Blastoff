#ifndef THERMOMETER_H
#define THERMOMETER_H

#include <string>
#include "clock.h"

class Thermometer {
private:
    double data;
    Clock* clock;
    int min = 15, max = 37;

public:
    // constructor
    Thermometer(Clock* clock);
    ~Thermometer();

    // data
    double get_data();
    void set_data();

    // min/max
    int get_min();
    int get_max();

    // to_string
    std::string to_string();
};

#endif
