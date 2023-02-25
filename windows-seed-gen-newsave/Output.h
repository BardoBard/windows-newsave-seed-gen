#pragma once
#include <string>
#include <vector>

#include "Map.h"

class Output
{
public:
    /**
     * \brief ctor
     * \param map map object
     * \param amount_of_seeds_to_return amount of seeds the output has to display
     * \param randomize if seeds can be in any position
     */
    explicit Output(const Map& map, const uint32_t amount_of_seeds_to_return = 10, const bool randomize = false) : map(map), randomize(randomize),
                                                                                                                   amount_of_seeds_to_return(amount_of_seeds_to_return)
    {
        this->output_seeds.reserve(amount_of_seeds_to_return);
    }

    //variables
    Map map;
    bool randomize;
    std::vector<uint_fast32_t> output_seeds = {};
    long amount_of_seeds_to_return;

    //properties
    void set_output_seeds(const std::vector<uint_fast32_t> output_seeds)
    {
        this->output_seeds = output_seeds;
    }

    //methods
    std::string output_to_string() const;
};
