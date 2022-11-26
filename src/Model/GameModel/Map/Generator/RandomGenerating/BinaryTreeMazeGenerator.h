#pragma once

#include "Model/GameModel/Map/Generator/MapGenerator.h"

namespace GameModel::Map {

/**
 * @brief just BinaryTreeMazeGenerator. 
 * 
 */
class BinaryTreeMazeGenerator : public MapGenerator {
public:
    /**
     * @brief Construct a new Binary Tree Maze Generator object
     * 
     */
    BinaryTreeMazeGenerator();

    /**
     * @brief generates maze with binary tree
     * 
     * @param mapOptions options
     * @return generated map 
     */
    virtual std::vector<std::vector<Abstract::MapEntity>> generate(MapOptions mapOptions) override;
};

}