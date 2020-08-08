#ifndef THRUST_METER_H
#define THRUST_METER_H

#include <string>
#include "clock.h"

class Thrust_Meter {
private:
    Clock* clock;
    double data;
    double fake_data;
    double fake_label_data;

public:
    // constructor & destructor
    Thrust_Meter(Clock* clock);
    ~Thrust_Meter();

    // data
    double get_data();
    void set_data();

    // fake data
    double get_fake_label_data();

    // to_string
    std::string to_string();
};

#endif
