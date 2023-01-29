#pragma once

/**
 * \brief floor is meant to be a data structure that has data about the floor (e.g. which item)
 */
struct Floor
{
public:
    /**
     * \brief predicate used for sorting by floor_index
     * \param floor floor2
     * \return if floor1 is smaller than floor2
     */
    bool operator<(const Floor& floor) const
    {
        return floor_index < floor.floor_index;
    }

    /**
     * \brief initializer 
     * \param floor_index index of floor, IMPORTANT! index skips 5 (e.g: 1,2,3,4,6,7...)
     * \param item_index item_index
     */
    explicit Floor(const int_fast16_t floor_index, const int_fast16_t item_index) : floor_index(floor_index),
                                                                                    item_index(item_index)
    {
    }

    /**
     * \brief floor index
     */
    int_fast16_t floor_index;
    
    /**
     * \brief item on specific floor
     */
    int_fast16_t item_index;
};
