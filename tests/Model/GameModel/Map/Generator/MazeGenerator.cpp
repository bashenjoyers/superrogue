#include <gtest/gtest.h>
#include "Model/GameModel/Map/Generator/RandomGenerating/BinaryTreeMazeGenerator.h"

using GameModel::Generation::Map::BinaryTreeMazeGenerator;
using GameModel::Map::MapOptions;


TEST(MODEL_GAME_MODEL, MAZE_GENERATOR__BINARY_TREE) {
    MapOptions options = {
        .height = 2,
        .width = 3
    };
    BinaryTreeMazeGenerator gen;
    auto simple_map = gen.generate(options);
    ASSERT_EQ(simple_map.size(), options.width);
    ASSERT_EQ(simple_map.front().size(), options.height);

    int is_floor = 0;
    for (int i = 0; i < options.width && is_floor < 2; i++) {
        for (int j = 0; j < options.height && is_floor < 2; j++) {
            if (simple_map[i][j] == GameModel::Abstract::MapEntity::FLOOR) is_floor++;
        }
    }
    ASSERT_EQ(is_floor, 2);
}
