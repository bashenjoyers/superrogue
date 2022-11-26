#pragma once

#include <cstddef>

#include "MapGenerator.h"

namespace GameModel::Map {

class MapBuilder {
public:
    MapBuilder();

    void reset();

    void setEnemiesGenerator(/*TODO*/);
    void setEnemiesCount(size_t count);

    void setGenerator(std::unique_ptr<MapGenerator> newGenerator);
    
    void setMapOptions(MapOptions newOpts);

    void build();

private:
    std::unique_ptr<MapGenerator> generator;
    MapOptions opts;
    size_t enemiesCount = 0;

    std::vector<std::vector<Abstract::MapEntity>> map;
};

}