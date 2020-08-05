#ifndef ACCELEROMETER_H
#define ACCELEROMETER_H

#include <string>

class accelerometer {
private:
    std::string name;
    int data;

public:
    // constructor
    accelerometer(std::string name);

    // name
    std::string get_name();
    void set_name(std::string name);

    // data
    int get_data();
    void set_data(int timer);

    // to_string
    std::string to_string();
};

#endif
