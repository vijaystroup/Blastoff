#include <fmt/ranges.h>
#include <ctime>
#include <string>

using fmt::print;
using std::string;

class sensor {
private:
    string name;
    double data;
public:
    sensor(string name, int min, int max) {
        this->name = name;
        // gen_data(min, max);
    };

    string get_name() {return this->name;}
    void set_name(string name) {this->name = name;}

    string to_string() {
        return "sensor " + get_name() + ": ";
    }
};

int main(void) {
    srand(time(NULL));
    print("{}\n", rand() % 100);

    sensor s("boom");
    print("{}\n", s.to_string());

    return 0;
}
