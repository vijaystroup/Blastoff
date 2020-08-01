#include <fmt/ranges.h>
#include <ctime>
#include <unistd.h>
#include "sensor.h"

using fmt::print;

int main(void) {
    srand(time(NULL));

    sensor s("boom", 10, 50);
    for (int i = 0; i < 10; i++) {
        s.set_data();
        print("{}\n", s.to_string());
        sleep(1);
    }

    return 0;
}
