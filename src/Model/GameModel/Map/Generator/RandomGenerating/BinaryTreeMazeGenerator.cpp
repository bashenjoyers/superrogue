#include "BinaryTreeMazeGenerator.h"

#include <random>

GameModel::Generation::Map::BinaryTreeMazeGenerator::BinaryTreeMazeGenerator() :
        MapGenerator() {}

std::vector<std::vector<GameModel::Abstract::MapEntity>> GameModel::Generation::Map::BinaryTreeMazeGenerator::generate(GameModel::Map::MapOptions mapOptions) {
    if (mapOptions.width == 0 || mapOptions.height == 0) return {};
    std::vector<std::vector<Abstract::MapEntity>> maze(mapOptions.width, std::vector<Abstract::MapEntity>(mapOptions.height, Abstract::MapEntity::WALL));
    
    std::random_device r;
    std::mt19937 e(r());
    std::uniform_int_distribution<int> coin(0, 1);

    for (size_t y = 0; y < maze.front().size(); y++) {
        for (size_t x = 1; x < maze.size(); x++) {
            if (y == 0 || y == maze.front().size() - 1) { maze[x - 1][y] = Abstract::MapEntity::FLOOR; continue; }

            if (coin(e)) {
                maze[x - 1][y] = Abstract::MapEntity::FLOOR;
            } else {
                maze[x][y - 1] = Abstract::MapEntity::FLOOR;
            }
        }
    }

    return maze;
}
