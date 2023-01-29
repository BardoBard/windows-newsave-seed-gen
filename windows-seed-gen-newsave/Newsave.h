#pragma once
#include <shared_mutex>
#include "Map.h"
#include "Output.h"

class Newsave
{
private:
    const uint_fast8_t starter_to_newsave_index[9] = {5, 31, 0, 22, 7, 44, 25, 6, 50};

    long seeds_to_find;
    Output& output;
    std::shared_mutex mutex;

    void start_seed(uint_fast32_t master_seed, uint_fast32_t max);
    bool find_shoguul_item(const uint_fast32_t master_seed) const;
    inline bool find_floor_items(const uint_fast32_t master_seed, uint_fast16_t& total_weight,
                                 uint8_t (&newsave_weight)[59]) const;
public:
    void calculate_seeds(const uint_fast32_t seed_amount);

    explicit Newsave(Output& output, const int seeds_to_find)
        : seeds_to_find(seeds_to_find), output(output)
    {
    }
};
