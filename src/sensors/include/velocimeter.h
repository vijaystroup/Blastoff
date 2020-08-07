#ifndef VELOCIMETER_H
#define VELOCIMETER_H

#include <string>
#include "clock.h"

class Velocimeter {
private:
    double data;
    double fake_data;
    Clock* clock;

public:
    // constructor & destructor
    Velocimeter(Clock* clock);
    ~Velocimeter();

    // data
    double get_data();
    void set_data();

    // to_string
    std::string to_string();
};

#endif
