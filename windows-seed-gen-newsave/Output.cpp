#include "pch.h"
#include "Output.h"

std::string Output::output_to_string()
{
    std::string result;
    for (auto& [room_name, item_name] : output_room_item_names)
        result += room_name + ": " + item_name + '\n';

    result += '\n';

    for (const auto& seed : output_seeds)
        result += std::to_string(seed) + '\n';

    return result;
}

void Output::reset_output()
{
    output_seeds = {};
    output_room_item_names = {};
}
