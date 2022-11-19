#include "BinaryTreeMazeGenerator.h"

#include <random>

GameModel::Map::BinaryTreeMazeGenerator::BinaryTreeMazeGenerator(GameModel::Map::MapOptions mapOptions) :
        MazeGenerator(mapOptions) {}

std::vector<std::vector<bool>> GameModel::Map::BinaryTreeMazeGenerator::generate() {
    std::random_device r;
    std::mt19937 e(47);
    std::uniform_int_distribution<int> coin(0, 1);

    for (size_t y = 0; y < maze.front().size(); y++) {
        for (size_t x = 1; x < maze.size(); x++) {
            if (y == 0 || y == maze.front().size() - 1) { maze[x - 1][y] = true; continue; }

            if (coin(e)) {
                maze[x - 1][y] = true;
            } else {
                maze[x][y - 1] = true;
            }
        }
    }

    return maze;
}
