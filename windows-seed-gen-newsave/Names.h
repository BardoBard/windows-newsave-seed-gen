#pragma once
#include <map>
#include <string>

/**
 * \brief Here are all the display names of items, rooms, etc
 */
namespace Names
{
    /**
     * \brief Newsave display names of items
     */
    class NewsaveNames
    {
    public:
        //Variables

        /**
         * \brief starter relics (only for tutorial room)
         */
        inline static const std::string starter_display[9] = {
            "Bottled Lightning", "Butcher's Cleaver", "Bombushka", "Golden Popcorn", "Guidance", "Phantasmal Axe",
            "Floating Skull", "Salamander Tail", "Fork"
        };

        /**
         * \brief initially unlocked relics
         */
        inline static const std::string newsave_display[59] = {
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

        /**
         * \brief legendary initial relics for new save
         */
        inline static const std::string legendary_display[19] = {
            "Lockpick", "Chakram", "Karmic Scale", "Rabbit Gloves", "Doom Blade", "Mjölnir", "Pocket of Holding",
            "Miniaturizer", "Nullstone", "Mushroom", "Glass Cannon", "Branding Bomb", "Suneater", "Transmutagen Blast",
            "Tsar Bomba", "Shield of Quills", "Soul Guard", "Box of Holding", "Stoneforge Broth"
        };
    };

    /**
     * \brief map of index + floor names
     */
    inline static const std::map<int_fast16_t, std::string> floor_names = {
        {1, "Goldmine 1"},
        {2, "Goldmine 2"},
        {3, "Goldmine 3"},
        {4, "Goldmine 4"},
        {6, "Dungeon 1"},
        {7, "Dungeon 2"},
        {8, "Dungeon 3"},
        {9, "Dungeon 4"},
        {11, "Halls 1"},
        {12, "Halls 2"},
        {13, "Halls 3"},
        {14, "Halls 4"},
        {16, "Caverns 1"},
        {17, "Caverns 2"},
        {18, "Caverns 3"},
        {19, "Caverns 4"},
        {21, "Core 1"},
        {22, "Core 2"},
        {23, "Core 3"},
        {24, "Core 4"},
    };
}
