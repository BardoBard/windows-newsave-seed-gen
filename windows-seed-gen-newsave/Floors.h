#pragma once
#include <map>
#include <string>
#include <vector>

class Floors
{
public:
    explicit Floors(const uint_fast8_t first_item, const std::map<uint_fast8_t, uint_fast8_t> rooms,
                    const std::map<uint_fast8_t, std::string> room_names) : first_item(
                                                                     first_item), room_names(room_names), rooms(rooms)
    {
    }

    const uint_fast8_t first_item;

    std::map<uint_fast8_t, std::string> room_names;
    std::map<uint_fast8_t, uint_fast8_t> rooms;
};
