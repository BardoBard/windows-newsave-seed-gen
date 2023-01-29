#include "pch.h"
#include "Output.h"

#include "Names.h"

/**********************/
//       PUBLIC       //
/**********************/

/**
 * \brief Generates a string that includes all items, floors and found seeds
 * \return output string for textbox
 */
std::string Output::output_to_string() const
{
    using namespace Names; //namespace that includes all the names of items, floors, etc
    std::string result;

    //if user has selected shoguul add to result
    if (!map.shoguul.skip)
        result += "Shoguul: " + floor_names.at(map.shoguul.floor_index) + ": " + NewsaveNames::legendary_display[map.
            shoguul.item_index] + "\n\n";

    //Goldmine 1
    result += "Goldmine 1: " + (map.first_item == ANYTHING ? "Anything" : NewsaveNames::starter_display[map.first_item])
        + "\n\n";

    //add Goldmine 2 - Core 4
    for (auto& floor : map.floors)
        result += floor_names.at(floor.floor_index) + ": " + NewsaveNames::newsave_display[floor.item_index] + "\n\n";

    //found seeds
    for (const auto& seed : output_seeds)
        result += std::to_string(seed) + '\n';

    return result; //return output string
}
