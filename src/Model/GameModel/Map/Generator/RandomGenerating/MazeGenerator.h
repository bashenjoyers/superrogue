#pragma once

#include "Model/GameModel/Map/Map.h"

namespace GameModel::Map {

class MazeGenerator {
public:
    /**
     * @brief Construct a new Maze Generator object
     * 
     *
     */
    MazeGenerator() = default;
    virtual ~MazeGenerator() = default;

    /**
     * @brief generates a simplified view of the map (whether there is a wall or not)
     * 
     * @return std::vector<std::vector<bool>> 
     */
    virtual std::vector<std::vector<bool>> generate(MapOptions mapOptions) = 0;
};

}