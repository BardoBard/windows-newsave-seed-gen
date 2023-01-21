#include "pch.h"
#include "Newsave.h"

#include <array>
#include <chrono>
#include <fstream>
#include <ostream>
#include <string>
#include <thread>
#include <Windows.h>

#include "NewsaveWindow.h"
#include "UnityRandom.h"

//std::vector<uint_fast32_t> Newsave::results = {};

std::ofstream outfile;

std::atomic<int_fast32_t> count;


const std::string newsave_display[59] = {
    "Bombushka", "Seer's Blood", "Rook's Bomb", "Lightning Bomb", "Galoshes", "Bottled Lightning",
    "Salamander Tail", "Guidance", "Ursine Ring", "Demon Ring", "Intensifier", "Cracked Orb", "Conductor",
    "Grimhilde's Mirror", "Meal Ticket", "Dillon's Claw", "Bramble Vest", "Leftovers", "Spare Ordnance",
    "Simple Chest", "Unstable Concoction", "Totem of Life", "Golden Popcorn", "Miner's Flask", "Sewing Kit",
    "Floating Skull", "Float Boots", "Key Blade", "War Paint", "Sonic Boom", "Gold Frenzy", "Butcher's Cleaver",
    "Iron Branch", "Knight's Pendant", "Queen's Crown", "Aegis", "Adventurer's Whip", "Axe Thrower's Pendant",
    "Cosmic Egg", "Battle Standard", "Battle Axe", "Tent", "Masa", "Lunchbox", "Phantasmal Axe", "Gecko Blast",
    "Soul Cannon", "Greaves", "Pauldron", "Obsidian Knife", "Fork", "Ursa Major", "Canis Major", "Sagitta",
    "Circinus", "Orion's Sword", "Shrapnel", "Tortoise Shield", "Golden Axe"
};

const std::string starter_display[9] = {
    "Bottled Lightning", "Butcher's Cleaver", "Bombushka", "Golden Popcorn", "Guidance", "Phantasmal Axe",
    "Floating Skull", "Salamander Tail", "Fork"
};


void  Newsave::calculate_seeds(const Floors& floors, const int_fast32_t seed_output_amount,
                                     const uint_fast32_t seed_amount)
{
    count = seed_output_amount;

    // Open the file "example.txt" in output mode
    outfile.open("output.txt");


    outfile << "items: \n";
    outfile << "mine1: " + starter_display[floors.first_item] + '\n';
    for (const auto& [fst, snd] : floors.rooms)
    {
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
    outfile << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl <<
        std::chrono::duration<double, std::nano>(end - start).count() << " ns" << std::endl;

    // Close the file
    outfile.close();
}


void Newsave::start_seed(const Floors& room, uint_fast32_t seed, const uint_fast32_t max)
{
    const bool is_empty = room.rooms.empty();
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

            auto x = room.first_item;
            if (i != x)
                goto nextSeedGoto;

            const uint_fast8_t starter_to_uint8 = starter_to_newsave_index[i];
            newsave_weightz -= newsave_weight[starter_to_uint8];
            newsave_weight[starter_to_uint8] = 0;
        }

        // find_floors(newsaveWeight, newsaveWeightz, seed);
        if (!is_empty)
        {
            for (const auto& [floor_index, item_index] : room.rooms)
            {
                const auto random_number = UnityRandom::next_uint(seed + floor_index);
                {
                    uint_fast8_t index = 0;
                    {
                        auto range_n = UnityRandom::range(1, newsave_weightz, random_number);
                        while (range_n > 0)
                        {
                            if (index > item_index)
                                goto nextSeedGoto;

                            range_n -= newsave_weight[++index];
                        }
                    }

                    newsave_weightz -= newsave_weight[--index];
                    newsave_weight[index] = 0;
                }
            }
        }
        //results.push_back(seed);
        --count;
        outfile << std::to_string(seed) + "\n";
    nextSeedGoto:
        ++seed;
    }
}

const std::string legendary_display[19] = {
    "Mjölnir", "Rabbit Gloves", "Transmutagen Blast", "Karmic Scale", "Doom Blade", "Chakram", "Pocket of Holding",
    "Miniaturizer", "Nullstone", "Glass Cannon", "Mushroom", "Branding Bomb", "Suneater", "Tsar Bomba",
    "Lockpick", "Shield of Quills", "Soul Guard", "Box of Holding", "Stoneforge Broth"
};

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
