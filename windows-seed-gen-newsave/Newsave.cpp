#include "pch.h"
#include "Newsave.h"

#include <fstream>
#include <vector>
#include <Windows.h>

#include "UnityRandom.h"

/**
 * \brief finds the seeds that have specified items (in this object) and puts them into output
 * \param master_seed start seed
 * \param max end seed
 */
void Newsave::find_seeds(uint_fast32_t master_seed, const uint_fast32_t max) const
{
    //loop through seed until max or until x amount of seeds have been found
    for (; master_seed < max && user_input.count > 0; master_seed++)
    {
        //newsave_weight are the weights for newsave items
        uint_fast8_t newsave_weight[59] = {
            9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 3, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 3, 3, 9, 9, 9, 9, 9, 9, 9, 9, 3,
            9, 3, 9, 3, 9, 9, 9, 3, 9, 9, 1, 3, 5, 5, 3, 3, 9, 9, 9, 9, 9, 9, 9, 3
        };
        //total weight of all the weights in newsave_weight
        uint_fast16_t total_weight = 449;


        //finds tutorial room item
        {
            const auto range_s = UnityRandom::range_inclusive(1, 73, UnityRandom::next_uint(master_seed + 1)) - 72;
            const uint_fast8_t i = range_s > 0 ? 8 : 7 + static_cast<uint_fast8_t>(range_s / 9);

            //if tutorial item isn't the item we want to find go to next seed
            if (i != user_input.map.first_item && user_input.map.first_item != ANYTHING)
                continue;

            const uint_fast8_t starter_to_uint8 = starter_to_newsave_index[i];
            total_weight -= newsave_weight[starter_to_uint8]; //reduce total_weight by item weight
            newsave_weight[starter_to_uint8] = 0; //remove weight from pool
        }

        if (!user_input.map.shoguul.skip)
            if (!has_shoguul_item(master_seed)) //continue if shoguul item cannot be found
                continue;


        if (!find_floor_items(master_seed, total_weight, newsave_weight)) //continue if floor items cannot be found
            continue;

        user_input.output_seeds.push_back(master_seed);
        --user_input.count;
    }
}


/**
 * \brief returns if item (provided within this object) is within the specified seed
 * \param master_seed a specific seed
 * \return if shoguul has a given item within the seed
 */
inline bool Newsave::has_shoguul_item(const uint_fast32_t master_seed) const
{
    //seed, which is based on specific floor
    const auto seed = master_seed + user_input.map.shoguul.floor_index;

    //random number used for range
    const auto random_number = UnityRandom::next_uint(seed);

    //if shoguul is not open on current floor return false
    if (const bool is_shoguul_open = floor(UnityRandom::range_inclusive(0, 100, random_number) / 5) == 0;
        !is_shoguul_open)
        return false;

    //second random number used for range
    const auto shoguul_rn = UnityRandom::next_uint(seed * 1812433253 + 1, random_number);

    const auto first_item_range = UnityRandom::range_inclusive(1, 19, random_number) - 1; //-1 for index
    auto second_item_range = UnityRandom::range_inclusive(1, 18, shoguul_rn) - 1; //-1 for index

    //if first_item is removed from the pool before second_item increase the second_item index
    if (first_item_range <= second_item_range)
        second_item_range++;

    //return if shoguul item is on current floor
    return first_item_range == user_input.map.shoguul.item_index || second_item_range == user_input.map.shoguul.
        item_index;
}

/**
 * \brief returns if items (provided within this object) are within the specified seed
 * \param master_seed specific seed
 * \param total_weight total weight of all the weights
 * \param newsave_weight array of all the weights
 * \return if items show up in specific seed
 */
inline bool Newsave::find_floor_items(const uint_fast32_t& master_seed, uint_fast16_t& total_weight,
                                      uint8_t (&newsave_weight)[59]) const
{
    //loop through floor indexes (1,2,3,4,6,7,8,9,11,12...)
    for (const auto& floor : user_input.map.floors)
    {
        //random number used for range
        const auto random_number = UnityRandom::next_uint(master_seed + floor.floor_index);

        //index for while loop
        uint_fast8_t index = 0;
        {
            auto range_n = UnityRandom::range_inclusive(1, total_weight, random_number);

            //keep subtracting newsave_weights from range_n
            //if range_n <= 0 then that's your item
            while (range_n > 0)
                range_n -= newsave_weight[index++];
        }
        --index;
        if (user_input.randomize)
        {
            if (std::find_if(user_input.map.floors.cbegin(), user_input.map.floors.cend(),
                             [index](const Floor& floor) -> bool
                             {
                                 return floor.item_index == index;
                             }) == user_input.map.floors.cend())
                return false;
        }
        else
        {
            if (index != floor.item_index) //if index != item_index then we don't have to keep searching
                return false;
        }

        total_weight -= newsave_weight[index]; //reduce total_weight
        newsave_weight[index] = 0; //remove weight from the pool
    }
    return true;
}
