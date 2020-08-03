#ifndef ACCELEROMETER_H
#define ACCELEROMETER_H

#include <string>

class accelerometer {
private:
    std::string name;
    int data;
    int min, max;

public:
    accelerometer(std::string name, int min, int max);

    // name
    std::string get_name();
    void set_name(std::string name);

    // data
    int get_data();
    void set_data();

    std::string to_string();
};

#endif
