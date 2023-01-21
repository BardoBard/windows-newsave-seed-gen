#pragma once
#include <cstdint>

class UnityRandom
{
public:

    static uint_fast32_t staticUint(uint_fast32_t seed);
    static uint_fast32_t next_uint(uint_fast32_t seed, uint_fast32_t extra);
    static uint_fast32_t next_uint(uint_fast32_t seed);
    static int_fast16_t range(const uint_fast8_t min, const uint_fast16_t max, const uint_fast32_t random_number);
};
