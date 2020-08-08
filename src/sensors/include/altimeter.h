#ifndef ALTIMETER_H
#define ALTIMETER_H

#include <string>
#include "clock.h"

class Altimeter {
private:
    double data;
    Clock* clock;
    int min = 200, max = 2000;

public:
    // constructor & destructor
    Altimeter(Clock* clock);
    ~Altimeter();

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
