#ifndef THERMOMETER_H
#define THERMOMETER_H

#include <string>

class thermometer {
private:
    std::string name;
    int data;
    int min, max;

public:
    // constructor
    thermometer(std::string name, int min, int max);

    // name
    std::string get_name();
    void set_name(std::string name);

    // data
    int get_data();
    void set_data();

    // to_string
    std::string to_string();
};

#endif
