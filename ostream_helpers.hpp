#include <iostream>
#include <map>
#include <type_traits>
#include <vector>

template <typename T, class Allocator>
std::ostream& operator<<(std::ostream& os, const std::vector<T, Allocator>& v) {
    os << "[";

    for (const T& x : v) {
        os << x << ", ";
    }

    os << "]";

    return os;
}

template <typename Key, typename Value, class Compare, class Allocator>
std::ostream& operator<<(std::ostream& os, const std::map<Key, Value, Compare, Allocator>& m) {
    os << "{\n";

    for (const auto& [key, value] : m) {
        using RealKey = std::unwrap_reference_t<Key>;
        using RealValue = std::unwrap_reference_t<Value>;

        os << "\t" << static_cast<RealKey>(key) << " : " << static_cast<RealValue>(value) << "\n";
    }

    os << "}\n";

    return os;
}