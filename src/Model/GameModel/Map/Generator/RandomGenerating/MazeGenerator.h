#pragma once

#include "Model/GameModel/Map/Map.h"

namespace GameModel::Map {

class MazeGenerator {
public:
    /**
     * @brief Construct a new Maze Generator object
     * 
     * @param mapOptions - forwards the parameters of the generated map
     */
    MazeGenerator(MapOptions mapOptions);
    virtual ~MazeGenerator() = default;

    /**
     * @brief generates a simplified view of the map (whether there is a wall or not)
     * 
     * @return std::vector<std::vector<bool>> 
     */
    virtual std::vector<std::vector<bool>> generate() = 0;

protected:
    std::vector<std::vector<bool>> maze;
};

}