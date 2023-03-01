#pragma once
#include <shared_mutex>
#include "Map.h"
#include "UserInput.h"

class Newsave
{
private:
    const uint_fast8_t starter_to_newsave_index[9] = {5, 31, 0, 22, 7, 44, 25, 6, 50};
    UserInput& user_input;

    inline bool has_shoguul_item(const uint_fast32_t master_seed) const;
    inline bool find_floor_items(const uint_fast32_t& master_seed, uint_fast16_t& total_weight,
                                 uint8_t (&newsave_weight)[59]) const;
public:
    void find_seeds(uint_fast32_t master_seed, uint_fast32_t max) const;
    
    /**
     * \brief ctor
     * \param output output object
     */
    explicit Newsave(UserInput& output) : user_input(output)
    {
    }
};
