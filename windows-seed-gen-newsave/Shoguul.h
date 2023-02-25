#pragma once

/**
 * \brief it's shoguul, I really can't say much more
 * he shows up in the undermine
 */
struct Shoguul : public Floor
{
public:
    /**
     * \brief if user wishes to get random shoguuls (aka skip selection)
     */
    bool skip;

    /**
     * \brief initializer
     * \param floor_index floor that shoguul will show up
     * \param item_index item to find
     */
    Shoguul(const int_fast16_t floor_index, const int_fast16_t item_index) :
        Floor(floor_index, item_index), skip(floor_index == NOTHING)
    {
    }

    Shoguul() : Floor(), skip(false)
    {
    }
};
