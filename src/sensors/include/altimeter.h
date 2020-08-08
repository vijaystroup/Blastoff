#ifndef ALTIMETER_H
#define ALTIMETER_H

#include <string>
#include "clock.h"

class Altimeter {
private:
    double data;
    Clock* clock;

public:
    // constructor & destructor
    Altimeter(Clock* clock);
    ~Altimeter();

    // data
    double get_data();
    void set_data();

    // to_string
    std::string to_string();
};

#endif
