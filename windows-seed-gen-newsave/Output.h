#pragma once
#include <string>
#include <vector>

class Output
{
public:
    inline static std::vector<std::pair<std::string, std::string>> output_room_item_names = {};
    inline static std::vector<uint_fast32_t> output_seeds = {};

    static std::string output_to_string();
    static void reset_output();
};
