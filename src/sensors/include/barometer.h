#ifndef BAROMETER_H
#define BAROMETER_H

#include <string>
#include "clock.h"

class Barometer {
private:
    double data;
    double fake_data;
    Clock* clock;

public:
    // constructor & destructor
    Barometer(Clock* clock);
    ~Barometer();

    // data
    double get_data();
    void set_data();

    // to_string
    std::string to_string();
};

#endif
