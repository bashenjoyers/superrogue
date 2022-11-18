#pragma once

#include "GameDataConverter.h"
#include "Model/GameModel/Map/Map.h"
#include "Model/GameModel/GameObject/Item/Stuff/Item.h"

#include <unordered_map>
#include <string>
#include <vector>
#include <memory>

namespace View {

class CharConverter {
public:
    std::vector<std::vector<char>> convertMap(std::shared_ptr<GameModel::Map::MapInfo> mapInfo);
    char convertItem(GameModel::ItemType item);
    char convertPotion();
    char convertVoidItem();
    
private:
    std::unordered_map<std::string, char> gameMapping;
};

}