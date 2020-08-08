#ifndef CLOCK_H
#define CLOCK_H

class Clock {
private:
    int time;
public:
    Clock();
    ~Clock();

    void set_time();
    int get_time();
};

#endif