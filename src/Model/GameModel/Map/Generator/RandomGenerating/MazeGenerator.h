#pragma once

#include "Model/GameModel/Map/Map.h"

namespace GameModel::Map {

class MazeGenerator {
public:
    MazeGenerator(MapOptions mapOptions);
    virtual ~MazeGenerator() = default;

    virtual std::vector<std::vector<bool>> generate() = 0;

protected:
    std::vector<std::vector<bool>> maze;
};

}