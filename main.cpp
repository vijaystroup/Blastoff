#include <fmt/ranges.h>
#include <ctime>
#include <string>
#include <unistd.h>

using fmt::print;
using std::string;

class sensor {
private:
    string name;
    int data;

public:
    int min, max;

    sensor(string name, int min, int max) {
        set_name(name);
        this->data = -1;
        this->min = min;
        this->max = max;
    };

    // name
    string get_name() {return this->name;}
    void set_name(string name) {this->name = name;}

    // data
    int get_data() {return this->data;}
    void set_data() {
        this->data = this->min + (rand() % (this->max - this->min + 1));
    }

    string to_string() {return "sensor " + get_name() + ": " + std::to_string(get_data());}
};

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
