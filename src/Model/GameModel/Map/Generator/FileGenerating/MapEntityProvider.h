#pragma once

#include <map>
#include "Model/GameModel/abstract.h"

namespace GameModel::Map {

class MapEntityProvider {
public:
    MapEntityProvider();
    GameModel::Abstract::MapEntity getMapEntityBySymbol(char symbol);
private:
    std::map<char, GameModel::Abstract::MapEntity> entityMapping;
};
}

