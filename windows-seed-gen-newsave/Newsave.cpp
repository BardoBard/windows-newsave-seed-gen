#include "pch.h"
#include "Newsave.h"

#include <fstream>
#include <vector>
#include <Windows.h>
#include "UnityRandom.h"

void Newsave::calculate_seeds(const uint_fast32_t seed_amount)
{
    std::ofstream outfile;
    outfile.open("output.txt");
    outfile << seeds_to_find;
    outfile.close();

    //make collection of threads
    std::vector<std::thread> threads;

    //find amount of logical cores on pc
    const uint_fast8_t thread_amount = std::thread::hardware_concurrency();

    //split seeds amongst logical cores
    const uint_fast32_t seed_split = seed_amount / thread_amount;

    //reserve thread collection, so that it doesn't have to reclaim memory each pushback
    threads.reserve(thread_amount);

    //start timer
    const auto start = std::chrono::steady_clock::now();

    //give logical core their portion of seeds (not accounting for remainder)
    for (int i = 0; i < thread_amount; ++i)
        threads.emplace_back([&, i]
        {
            start_seed(i * seed_split, (i + 1) * seed_split);
        });


    //join all threads
    for (auto& thread : threads)
        thread.join();


    //end timer
    const auto end = std::chrono::steady_clock::now();
    outfile.open("output.txt");
    outfile << "time" + std::to_string(std::chrono::duration<double, std::milli>(end - start).count()) + " ms";
    outfile.close();
}

inline bool Newsave::find_shoguul_item(const uint_fast32_t master_seed) const
{
    const auto seed = master_seed + output.map.shoguul.floor_index;

    const auto random_number = UnityRandom::next_uint(seed);

    if (const bool is_shoguul_open = floor(UnityRandom::range_inclusive(0, 100, random_number) / 5) == 0; !
        is_shoguul_open)
        return false;

    const auto shoguul_rn =
        UnityRandom::next_uint(seed * 1812433253 + 1, random_number);

    const auto range = UnityRandom::range_inclusive(1, 19, random_number) - 1;
    auto range2 = UnityRandom::range_inclusive(1, 18, shoguul_rn) - 1;

    if (range <= range2)
        range2++;


    return range == output.map.shoguul.item_index || range2 == output.map.shoguul.item_index;
}


void Newsave::start_seed(uint_fast32_t master_seed, const uint_fast32_t max)
{
    //loop through seed until max or until x amount of seeds have been found
    for (; master_seed < max && seeds_to_find > 0; master_seed++)
    {
        {
            //reset variables every loop
            uint_fast8_t newsave_weight[59] = {
                9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 3, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 3, 3, 9, 9, 9, 9, 9, 9, 9, 9, 3,
                9,
                3,
                9, 3, 9, 9, 9, 3, 9, 9, 1, 3, 5, 5, 3, 3, 9, 9, 9, 9, 9, 9, 9, 3
            };
            uint_fast16_t total_weight = 449;


            {
                const auto range_s = UnityRandom::range_inclusive(1, 73, UnityRandom::next_uint(master_seed + 1)) - 72;
                const uint_fast8_t i = range_s > 0 ? 8 : 7 + static_cast<uint_fast8_t>(range_s / 9);

                if (i != output.map.first_item && output.map.first_item != ANYTHING)
                    continue;

                const uint_fast8_t starter_to_uint8 = starter_to_newsave_index[i];
                total_weight -= newsave_weight[starter_to_uint8];
                newsave_weight[starter_to_uint8] = 0;
            }
            if (!output.map.shoguul.skip)
                if (!find_shoguul_item(master_seed))
                    continue;


            if (!find_floor_items(master_seed, total_weight, newsave_weight))
                continue;

            _InterlockedDecrement(&seeds_to_find);
            mutex.lock();
            output.output_seeds.push_back(master_seed);
            mutex.unlock();
        }
    }
}

inline bool Newsave::find_floor_items(const uint_fast32_t master_seed, uint_fast16_t& total_weight,
                                      uint8_t (&newsave_weight)[59]) const
{
    for (const auto& floor : output.map.floors)
    {
        const auto random_number = UnityRandom::next_uint(master_seed + floor.floor_index);
        uint_fast8_t index = 0;
        {
            auto range_n = UnityRandom::range_inclusive(1, total_weight, random_number);
            while (range_n > 0)
            {
                if (index > floor.item_index)
                    return false;

                range_n -= newsave_weight[index++];
            }
        }
        if (--index != floor.item_index)
            return false;

        total_weight -= newsave_weight[index];
        newsave_weight[index] = 0;
    }
    return true;
}
