#pragma once
#include <cstdint>
#include <string>

class Shoguul
{
public:
    bool skip_shoguul;
    uint_fast8_t floor_index;
    uint_fast8_t item_index;
    std::string floor_name;

    Shoguul(const uint_fast8_t floor_index, const uint_fast8_t item_index, const std::string floor_name) :
        floor_index(floor_index),
        item_index(item_index), floor_name(floor_name)
    {
        skip_shoguul = floor_index == -1;
    }
};
