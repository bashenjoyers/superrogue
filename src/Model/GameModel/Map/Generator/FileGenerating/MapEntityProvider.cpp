#include "MapEntityProvider.h"

GameModel::Map::MapEntityProvider::MapEntityProvider() {
    entityMapping = {
            {'.', Abstract::MapEntity::FLOOR},
            {'d', Abstract::MapEntity::DOOR},
            {'p', Abstract::MapEntity::POTION},
            {'i', Abstract::MapEntity::ITEM},
            {'#', Abstract::MapEntity::WALL},
            {'0', Abstract::MapEntity::PERSON},
            {'A', Abstract::MapEntity::ENEMY_AGRESSIVE},
            {'F', Abstract::MapEntity::ENEMY_FLYING},
            {'I', Abstract::MapEntity::ENEMY_ORDINARY},
            {'O', Abstract::MapEntity::ENEMY_ORDINARY},
            {'T', Abstract::MapEntity::ENEMY_TRAVELER},
            {'E', Abstract::MapEntity::ENEMY}
    };
}

GameModel::Abstract::MapEntity GameModel::Map::MapEntityProvider::getMapEntityBySymbol(char symbol) {
    if (entityMapping.find(symbol) == entityMapping.end())
        return Abstract::MapEntity::WALL;
    return entityMapping[symbol];
}
