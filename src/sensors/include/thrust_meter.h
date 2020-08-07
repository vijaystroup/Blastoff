#ifndef THRUST_METER_H
#define THRUST_METER_H

#include <string>
#include "clock.h"

class Thrust_Meter {
private:
    double data;
    double fake_data;
    Clock* clock;

public:
    // constructor & destructor
    Thrust_Meter(Clock* clock);
    ~Thrust_Meter();

    // data
    double get_data();
    void set_data();

    // to_string
    std::string to_string();
};

#endif
