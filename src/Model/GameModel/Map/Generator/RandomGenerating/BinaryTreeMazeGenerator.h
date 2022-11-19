#pragma once

#include "MazeGenerator.h"

namespace GameModel::Map {

class BinaryTreeMazeGenerator : public MazeGenerator {
public:
    BinaryTreeMazeGenerator(MapOptions mapOptions);

    virtual std::vector<std::vector<bool>> generate() override;
};

}