#ifndef SENSOR_H
#define SENSOR_H

#include <string>

class sensor {
private:
    std::string name;
    int data;
    int min, max;

public:
    sensor(std::string name, int min, int max);

    // name
    std::string get_name();
    void set_name(std::string name);

    // data
    int get_data();
    void set_data();

    std::string to_string();
};

#endif
