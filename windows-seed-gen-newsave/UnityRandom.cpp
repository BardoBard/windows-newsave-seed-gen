#include "pch.h"
#include "UnityRandom.h"

/*********************/
//      PRIVATE      //
/*********************/
/**
 * \brief Calculates range between min and max with provided random number
 * \param min Minimum amount
 * \param max Maximum amount
 * \param random_number Specific next_uint()
 * \return Int16
 */
inline int_fast16_t UnityRandom::range(const uint_fast8_t min, const uint_fast16_t max,
                                       const uint_fast32_t random_number)
{
    return static_cast<int_fast16_t>(random_number % (max - min) + min);
}

/**********************/
//       PUBLIC       //
/**********************/

//TODO: refactor, make generic for path finding later
/**
* \brief This is a function for calculating a uint32 random number used for other random functions
 * \n\n
 * Very important!! this is shortcut way of simulating the Unity randomness, it's current use is only for new save and isn't generic
 * \param seed Initial seed
 * \return Uint32 for other random functions
 */
uint_fast32_t UnityRandom::next_uint(uint_fast32_t seed, uint_fast32_t extra)
{
    seed ^= seed << 11;
    seed ^= seed >> 8;
    extra ^= extra >> 19;
    return seed ^ extra;
}

/**
 * \brief This is an overload for the function with the same name
 * \n\n
 * Very important!! this is shortcut way of simulating the Unity randomness, it's current use is only for new save and isn't generic
 * \param seed Initial seed
 * \return Uint32 for other random functions
 */
uint_fast32_t UnityRandom::next_uint(const uint_fast32_t seed)
{
    return next_uint(seed, 1790253981 * seed + 1900727103);
}

/**
 * \brief gets a range between min and (max + 1)
 * \param min Minimum amount
 * \param max Maximum amount
 * \param random_number Specific next_uint()
 * \return Int16
 */
int_fast16_t UnityRandom::range_inclusive(const uint_fast8_t min, const uint_fast16_t max,
                                          const uint_fast32_t random_number)
{
    return range(min, max + 1, random_number);
}
