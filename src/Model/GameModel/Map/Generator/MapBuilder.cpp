#include "MapBuilder.h"
#include "Model/GameModel/Map/Generator/RandomGenerating/BinaryTreeMazeGenerator.h"

namespace GameModel::Map {
MapBuilder::MapBuilder() : generator(std::make_unique<BinaryTreeMazeGenerator>()) {}

void MapBuilder::reset() {
    enemiesCount = 0;
    generator = std::make_unique<BinaryTreeMazeGenerator>();
    opts = MapOptions();
}

void MapBuilder::setEnemiesGenerator(/*TODO*/) {
    
}

void MapBuilder::setEnemiesCount(size_t count) {
    enemiesCount = count;
}

void MapBuilder::setGenerator(std::unique_ptr<MapGenerator> newGenerator) {
    generator = std::move(newGenerator);
}

void MapBuilder::setMapOptions(MapOptions newOpts) {
    opts = newOpts;
}

void MapBuilder::build() {
    map = generator->generate(opts);
    
}
}