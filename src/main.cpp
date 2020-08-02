#include <fmt/ranges.h>
#include <ctime>
#include <unistd.h>
#include "sensor.h"

using fmt::print;

int main(void) {
    srand(time(NULL));

    sensor s("boom", 10, 50);
    while(true) {
        s.set_data();
        print("{}\n", s.to_string());
        usleep(100000);
    }

    return 0;
}
