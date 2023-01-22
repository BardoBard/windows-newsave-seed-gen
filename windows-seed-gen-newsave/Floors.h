#pragma once
#include <map>
#include <string>
#include "Shoguul.h"

class Floors
{

public:
     Floors(const uint_fast8_t first_item, const std::map<int_fast16_t, int_fast16_t> rooms,
                    const std::map<int_fast16_t, std::string> room_names,
                    const Shoguul& shoguul) : first_item(
        first_item), shoguul(shoguul), room_names(room_names), rooms(rooms)
    {
        skip_floors = shoguul.floor_index == -1 && rooms.empty();
        if (shoguul.floor_index != -1 && rooms.count(shoguul.floor_index) == 0)
        {
            this->rooms[shoguul.floor_index] = 0;
            this->room_names[shoguul.floor_index] = "";
        }
        
    }

    const uint_fast8_t first_item;
    Shoguul shoguul;

    std::map<int_fast16_t, std::string> room_names;
    std::map<int_fast16_t, int_fast16_t> rooms;
    bool skip_floors;
};
