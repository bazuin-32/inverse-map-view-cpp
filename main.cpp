#include <functional>
#include <iostream>
#include <type_traits>

#include "map_views.hpp"
#include "ostream_helpers.hpp"

int main() {
    std::map<std::string, unsigned long> m = {
        {"a", 1},
        {"b", 2},
        {"c",9923}
    };

    std::cout << "original " << m << "\n\n";

    auto inv = map_views::inverse(m);
    std::cout << "inv " << inv << "\n";

    return 0;
}