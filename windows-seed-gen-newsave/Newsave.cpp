#include "pch.h"
#include "Newsave.h"

#include <array>
#include <chrono>
#include <fstream>
#include <ostream>
#include <string>
#include <thread>
#include <vector>
#include <Windows.h>

#include "NewsaveWindow.h"
#include "UnityRandom.h"

//std::vector<uint_fast32_t> Newsave::results = {};

std::ofstream outfile;

std::atomic<int_fast32_t> count;


void Newsave::calculate_seeds(const Floors& floors, const int_fast32_t seed_output_amount,
                              const uint_fast32_t seed_amount)
{
    count = seed_output_amount;

    // Open the file "example.txt" in output mode
    outfile.open("output.txt");


    if (!floors.shoguul.skip_shoguul)
    {
        outfile << "shoguul: \n";
        outfile << "floor: " + floors.shoguul.floor_name + "\n";
        outfile << "item: " + legendary_display[floors.shoguul.item_index] + "\n\n";
    }

    outfile << "items: \n";
    outfile << "mine1: " + starter_display[floors.first_item] + '\n';
    for (const auto& [fst, snd] : floors.rooms)
    {
        if (floors.room_names.at(fst) != "")
            outfile << floors.room_names.at(fst) + ": " + newsave_display[snd] + '\n';
    }

    outfile << "\n\n";


    const uint_fast8_t threads = std::thread::hardware_concurrency();

    std::vector<std::thread> t;
    t.reserve(threads);

    const uint_fast32_t seed_split = seed_amount / threads;

    const auto start = std::chrono::steady_clock::now();


    for (int i = 0; i < threads; ++i)
        t.emplace_back(start_seed, std::ref(floors), i * seed_split, (i + 1) * seed_split);

    for (auto& thread : t)
        thread.join();


    const auto end = std::chrono::steady_clock::now();


    // Write the string to the file
    outfile << std::endl << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl <<
        std::chrono::duration<double, std::nano>(end - start).count() << " ns" << std::endl;

    // Close the file
    outfile.close();
}


void Newsave::start_seed(const Floors& floors, uint_fast32_t seed, const uint_fast32_t max)
{
    const bool skip_floors = floors.skip_floors;
    const bool skip_shoguul = floors.shoguul.skip_shoguul;
    //#pragma omp parallel for
    while (seed < max && count > 0)
    {
        //reset variables every loop
        uint_fast8_t newsave_weight[59] = {
            9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 3, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 3, 3, 9, 9, 9, 9, 9, 9, 9, 9, 3,
            9,
            3,
            9, 3, 9, 9, 9, 3, 9, 9, 1, 3, 5, 5, 3, 3, 9, 9, 9, 9, 9, 9, 9, 3
        };
        uint_fast16_t newsave_weightz = 449;


        {
            const auto range_s = UnityRandom::range(1, 73, UnityRandom::next_uint(seed + 1)) - 72;
            const uint_fast8_t i = range_s > 0 ? 8 : 7 + static_cast<uint_fast8_t>(range_s / 9);

            if (i != floors.first_item)
                goto nextSeedGoto;

            const uint_fast8_t starter_to_uint8 = starter_to_newsave_index[i];
            newsave_weightz -= newsave_weight[starter_to_uint8];
            newsave_weight[starter_to_uint8] = 0;
        }

        // find_floors(newsaveWeight, newsaveWeightz, seed);

        for (const auto& [floor_index, item_index] : floors.rooms)
        {
            const auto random_number = UnityRandom::next_uint(seed + floor_index);


            if (!skip_shoguul && floor_index == floors.shoguul.floor_index)
            {
                const bool shoguul_is_open = ::floor(UnityRandom::range(0, 100, random_number) / 5) == 0;

                if (!shoguul_is_open)
                    goto nextSeedGoto;

                const auto shoguul_rn =
                    UnityRandom::next_uint((seed + floor_index) * 1812433253 + 1, random_number);

                const auto range = UnityRandom::range(1, 19, random_number) - 1;
                auto range2 = UnityRandom::range(1, 18, shoguul_rn) - 1;

                if (range <= range2)
                    range2++;


                if (range != floors.shoguul.item_index && range2 != floors.shoguul.item_index)
                    goto nextSeedGoto;
            }

            if (!skip_floors)
            {
                uint_fast8_t index = 0;
                {
                    auto range_n = UnityRandom::range(1, newsave_weightz, random_number);
                    while (range_n > 0)
                    {
                        if (index > item_index)
                            goto nextSeedGoto;

                        range_n -= newsave_weight[index++];
                    }
                }
                if (--index != item_index)
                    goto nextSeedGoto;

                newsave_weightz -= newsave_weight[index];
                newsave_weight[index] = 0;
            }
        }
        //results.push_back(seed);
        --count;
        outfile << std::to_string(seed) + "\n";
    nextSeedGoto:
        ++seed;
    }
}

void Newsave::find_floors(uint_fast8_t (&newsave_weight)[59], uint_fast16_t newsave_weightz, const uint_fast32_t seed)
{
    for (const uint_fast8_t& floor : std::array<uint_fast8_t, 20>() = {
             2, 3, 4, 6, 7, 8, 9, 11, 12, 13, 14, 16, 17, 18, 19, 21, 22, 23, 24
         })
    {
        const auto random_number = UnityRandom::next_uint(seed + floor);
        // auto shoguul_rn = UnityRandom::next_uint((seed + floor) * 1812433253 + 1, random_number);
        //
        // auto shoguul_percentage = UnityRandom::range(0, 100, random_number);
        //
        //
        // const auto range = UnityRandom::range(1, 19, random_number) - 1;
        // auto range2 = UnityRandom::range(1, 18, shoguul_rn);

        // if (range == 18)
        //     --range2;
        // else if (range == range2)
        //     ++range2;
        //
        // if (floor > 2)
        //     return;
        //
        // if (::floor(shoguul_percentage / 5) > 0)
        //     return;
        //
        // if (range != 18)
        //     return;
        //
        // std::cout << legendary_display[range] << std::endl;
        // std::cout << legendary_display[range2] << std::endl;
        // std::cout << seed << std::endl;
        // printf("\n");

        // auto range_shoguul = UnityRandom::staticRange(1, 100, random_number);
        {
            uint_fast8_t index = 0;
            {
                auto range_n = UnityRandom::range(1, newsave_weightz, random_number);
                while (range_n > 0)
                    range_n -= newsave_weight[++index];
            }
            newsave_weightz -= newsave_weight[--index];
            newsave_weight[index] = 0;
        }
    }
}
