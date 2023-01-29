#pragma once
#include <cstdint>

/**
 * \brief class that simulates Unity random generator
 * 
 * Credit: https://github.com/MoatShrimp
 */
class UnityRandom
{
private:
    //methods
    inline static int_fast16_t range(const uint_fast8_t min, const uint_fast16_t max,
                                     const uint_fast32_t random_number);

public:
    //methods
    static uint_fast32_t next_uint(uint_fast32_t seed, uint_fast32_t extra);
    static uint_fast32_t next_uint(uint_fast32_t seed);
    static int_fast16_t range_inclusive(const uint_fast8_t min, const uint_fast16_t max,
                                        const uint_fast32_t random_number);
};
