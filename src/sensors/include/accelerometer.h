#ifndef ACCELEROMETER_H
#define ACCELEROMETER_H

class accelerometer {
private:
    int data;

public:
    // constructor
    accelerometer();

    // data
    int get_data();
    void set_data(int timer);

    // to_string
    std::string to_string();
};

#endif
