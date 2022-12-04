#pragma once

#include "Model/GameModel/Map/MapOptions.h"
#include "Model/GameModel/abstract.h"
#include "Model/GameModel/Generator.h"

#include <vector>

namespace GameModel::Generation::Map {

class MapGenerator : public Generator {
public:
    virtual ~MapGenerator() = default;

    /**
     * @brief generates map
     * 
     * @param mapOptions options of map generation
     * @return generated map
     */
    virtual std::vector<std::vector<Abstract::MapEntity>> generate(GameModel::Map::MapOptions mapOptions) = 0;
};

}