#include <fmt/ranges.h>
#include <ctime>
#include <string>

using fmt::print;
using std::string;

class sensor {
private:
    string name;
public:
    sensor(string name) {
        this->name = name;
    };
};

int main(void) {
    srand(time(NULL));
    print("{}\n", rand() % 100);

    return 0;
}
