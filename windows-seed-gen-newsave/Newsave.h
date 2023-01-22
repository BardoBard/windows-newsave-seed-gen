#pragma once
#include <atomic>
#include <fstream>

#include "Floors.h"

class Newsave
{
private:
    inline const static std::string Newsave::starter_display[9] = {
        "Bottled Lightning", "Butcher's Cleaver", "Bombushka", "Golden Popcorn", "Guidance", "Phantasmal Axe",
        "Floating Skull", "Salamander Tail", "Fork"
    };
    inline const static std::string Newsave::newsave_display[59] = {
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


    inline const static std::string legendary_display[19] = {
        "Lockpick", "Chakram", "Karmic Scale", "Rabbit Gloves", "Doom Blade", "Mjölnir", "Pocket of Holding",
        "Miniaturizer", "Nullstone", "Mushroom", "Glass Cannon", "Branding Bomb", "Suneater", "Transmutagen Blast",
        "Tsar Bomba", "Shield of Quills", "Soul Guard", "Box of Holding", "Stoneforge Broth"
    };
    inline const static uint_fast8_t Newsave::starter_to_newsave_index[9] = {5, 31, 0, 22, 7, 44, 25, 6, 50};

    void find_floors(uint_fast8_t (&newsave_weight)[59], uint_fast16_t newsave_weightz,
                     const uint_fast32_t seed);
    void static start_seed(const Floors& floors, uint_fast32_t seed, uint_fast32_t max);

public:
    void static calculate_seeds(const Floors& floors, const int_fast32_t seed_output_amount,
                                const uint_fast32_t seed_amount);
};
