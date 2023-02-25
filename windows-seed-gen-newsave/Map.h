#pragma once
#include <algorithm>
#include <vector>

#include "Floor.h"
#include "Shoguul.h"

/**
 * \brief map is meant as a data structure that holds the information of all the floors and shoguul
 */
struct Map
{
public:
    /**
     * \brief initializer for map
     * \param first_item tutorial item
     * \param floors collection of floors (with floor_index and item_index)
     * \param shoguul floor_index + item_index
     */
    Map(const int_fast16_t first_item, std::vector<Floor>& floors,
        const Shoguul& shoguul) : first_item(first_item), shoguul(shoguul)
    {
        //sort floors this is very important
        std::sort(floors.begin(), floors.end());
        this->floors = floors;
    }

    /**
     * \brief tutorial item
     */
    const int_fast16_t first_item;

    /**
     * \brief collection of floors with floor_index and item_index
     */
    std::vector<Floor> floors = {};
    
    /**
     * \brief shoguul data structure
     */
    Shoguul shoguul;
};
