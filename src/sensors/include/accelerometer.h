#ifndef ACCELEROMETER_H
#define ACCELEROMETER_H

#include <string>
#include "clock.h"

class accelerometer {
private:
    double data;
    double fake_data;
    Clock* clock;

public:
    // constructor & destructor
    accelerometer(Clock* clock);
    ~accelerometer();

    // data
    double get_data();
    void set_data();

    // to_string
    std::string to_string();
};

#endif
