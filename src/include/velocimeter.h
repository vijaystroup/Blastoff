#ifndef VELOCIMETER_H
#define VELOCIMETER_H

#include <string>
#include "clock.h"

class Velocimeter {
private:
    Clock* clock;
    double data;
    double fake_data;
    double fake_label_data;

public:
    // constructor & destructor
    Velocimeter(Clock* clock);
    ~Velocimeter();

    // data
    double get_data();
    void set_data();

    // fake_data
    double get_fake_label_data();

    // to_string
    std::string to_string();
};

#endif
