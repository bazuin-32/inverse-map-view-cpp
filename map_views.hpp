#include <map>
#include <functional>
#include <type_traits>

namespace map_views {

    template <typename Key, typename Value, template <typename> class Compare>
    using inverse_map = std::map<
        std::reference_wrapper<const Value>,
        std::reference_wrapper<const Key>,
        Compare<const Value>
    >;
    
    template <typename Key, typename Value, template <typename> class Compare>
    inverse_map<Key, Value, Compare> inverse(const std::map<Key, Value, Compare<Key>>& m) {
        inverse_map<Key, Value, Compare> result;

        for (const auto& [key, value] : m) {
            result.emplace(std::make_pair(std::cref(value), std::cref(key)));
        }

        return result;
    }
}