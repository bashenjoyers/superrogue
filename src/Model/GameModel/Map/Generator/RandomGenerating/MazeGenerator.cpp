#include "MazeGenerator.h"

GameModel::Map::MazeGenerator::MazeGenerator(MapOptions mapOptions) {
    maze.assign(mapOptions.width, std::vector<bool>(mapOptions.height, false));
}
