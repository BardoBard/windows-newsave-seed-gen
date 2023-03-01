#pragma once
#include <atomic>
#include <string>
#include <vector>

#include "Map.h"

class UserInput
{
public:
    /**
     * \brief ctor
     * \param map map object
     * \param count amount of seeds the output has to display
     * \param randomize if seeds can be in any position
     * \param min_seeds lower bound of seeds to find
     * \param max_seeds upper bound of seeds to find
     */
    explicit UserInput(const Map& map, std::atomic<int>& count, const bool randomize = false,
                       const uint_fast32_t min_seeds = 0, const uint_fast32_t max_seeds = 100000000) :
        map(map), randomize(randomize), count(count), min_seeds(min_seeds),
        max_seeds(max_seeds)
    {
        this->output_seeds.reserve(count);
    }

    //variables
    Map map;
    bool randomize; //if layout should be randomized
    std::vector<uint_fast32_t> output_seeds = {};
    std::atomic<int>& count; //amount of results
    uint_fast32_t min_seeds;
    uint_fast32_t max_seeds;
    //methods
    std::string output_to_string() const;
};
