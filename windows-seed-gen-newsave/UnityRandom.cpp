#include "pch.h"
#include "UnityRandom.h"

uint_fast32_t UnityRandom::next_uint(uint_fast32_t seed, uint_fast32_t extra)
{
    seed ^= seed << 11;
    seed ^= seed >> 8;
    extra ^= extra >> 19;
    return seed ^ extra;
}

uint_fast32_t UnityRandom::next_uint(const uint_fast32_t seed)
{
    return next_uint(seed, 1790253981 * seed + 1900727103);
}

int_fast16_t UnityRandom::range(const uint_fast8_t min, const uint_fast16_t max,
                                      const uint_fast32_t random_number)
{
    return static_cast<int_fast16_t>(random_number % (max + 1 - min) + min);
}
