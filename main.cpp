#include <functional>
#include <iostream>
#include <type_traits>

#include "map_views.hpp"
#include "ostream_helpers.hpp"

int main() {
    // std::map<std::string, unsigned long> m = {
    //     {"a", 1},
    //     {"b", 2},
    //     {"c",9923},
    //     {"d", -1930}
    // };

    // std::map<unsigned int, std::string, std::greater<unsigned int>> m = {
    //     {1, "a"},
    //     {2, "b"},
    //     {9923, "c"}
    // };

    std::map<int, std::vector<int>, std::greater<int>> m = {
        {0, {1, 4, 5}},
        {1, {6, 94, 9924}}  
    };

    std::cout << "original " << m << "\n\n";

    // std::cout << map_views::inverse(m) << "\n";
    auto inv = map_views::inverse(m);
    std::cout << "inv " << inv << "\n";
    // std::vector v{1, 4, 5};
    // inv.erase(inv.begin());
    // inv[v].get() = 929;
    std::cout << inv << "\n";

    return 0;
}