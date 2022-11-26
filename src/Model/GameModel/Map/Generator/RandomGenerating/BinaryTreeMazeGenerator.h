#pragma once

#include "MazeGenerator.h"

namespace GameModel::Map {

/**
 * @brief just BinaryTreeMazeGenerator. 
 * 
 */
class BinaryTreeMazeGenerator : public MazeGenerator {
public:
    BinaryTreeMazeGenerator();

    virtual std::vector<std::vector<bool>> generate(MapOptions mapOptions) override;
};

}