#pragma once
#include <string>
#include <vector>

#include "Map.h"

class Output
{
public:
    //ctor
    explicit Output(const Map& map, const uint16_t amount_of_seeds_to_find = 10,
                    const std::vector<uint_fast32_t>& output_seeds = {}) : map(map)
    {
        std::empty(output_seeds)
            ? this->output_seeds.reserve(amount_of_seeds_to_find)
            : this->output_seeds = output_seeds;
    }

    //variables
    Map map;
    std::vector<uint_fast32_t> output_seeds = {};

    //properties
    void set_output_seeds(const std::vector<uint_fast32_t> output_seeds)
    {
        this->output_seeds = output_seeds;
    }

    //methods
    std::string output_to_string() const;
};
