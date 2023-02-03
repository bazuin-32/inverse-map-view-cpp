# inverse-map-view-cpp

I wanted to see if it was possible to swap the keys and values of a `std::map` without copying any data, but rather
keeping references to the data in a new map.

This was my attempt at it.

## Usage
```c++
std::map<std::string, unsigned long> m = {
    {"a", 1},
    {"b", 2},
    {"c",9923},
};

auto inv = map_views::inverse(m);

// inv will now be:
/*
{
    {1, "a"},
    {2, "b"},
    {9923, "c"}
}
*/
```

See `main.cpp` for a complete demonstration. Compile and run to test.