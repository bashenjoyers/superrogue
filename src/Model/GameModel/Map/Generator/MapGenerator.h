#pragma once

#include "Model/GameModel/Map/Map.h"
#include <vector>

namespace GameModel::Map {

class MapGenerator {
public:
    virtual ~MapGenerator() = default;

    /**
     * @brief generates map
     * 
     * @param mapOptions options of map generation
     * @return generated map
     */
    virtual std::vector<std::vector<Abstract::MapEntity>> generate(MapOptions mapOptions) = 0;
};

}