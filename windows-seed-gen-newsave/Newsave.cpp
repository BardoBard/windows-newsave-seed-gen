#include "pch.h"
#include "Newsave.h"

#include "Output.h"
#include "UnityRandom.h"
#include <Windows.h>

void Newsave::calculate_seeds(const uint_fast32_t seed_amount)
{
    std::vector<std::thread> t;

    const uint_fast8_t threads = std::thread::hardware_concurrency();

    const uint_fast32_t seed_split = seed_amount / threads;

    t.reserve(threads);

    if (!floors.shoguul.skip_shoguul)
        Output::output_room_item_names.push_back({
            "Shoguul: \n" + floors.shoguul.floor_name, legendary_display[floors.shoguul.item_index]
        });

    Output::output_room_item_names.push_back({"mine1", starter_display[floors.first_item]});

    for (const auto& [fst, snd] : floors.rooms)
        if (floors.room_names.at(fst) != "")
            Output::output_room_item_names.push_back({floors.room_names.at(fst), newsave_display[snd]});


    const auto start = std::chrono::steady_clock::now();

    for (int i = 0; i < threads; ++i)
        t.emplace_back([&, i]
        {
            start_seed(i * seed_split, (i + 1) * seed_split);
        });


    for (auto& thread : t)
        thread.join();


    const auto end = std::chrono::steady_clock::now();


    // Write the string to the file
    Output::output_room_item_names.push_back({
        "\ntime", std::to_string(std::chrono::duration<double, std::milli>(end - start).count()) + " ms"
    });
}


void Newsave::start_seed(uint_fast32_t seed, const uint_fast32_t max)
{
    const bool skip_floors = floors.skip_floors;
    const bool skip_shoguul = floors.shoguul.skip_shoguul;
    //#pragma omp parallel for
    while (seed < max && seeds_to_find > 0)
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
        _InterlockedDecrement(&seeds_to_find);
        mutex.lock();
        Output::output_seeds.push_back(seed);
        mutex.unlock();
    nextSeedGoto:
        ++seed;
    }
}
