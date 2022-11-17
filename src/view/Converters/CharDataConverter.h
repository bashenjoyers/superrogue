#pragma once

#include "GameDataConverter.h"
#include "../../model/map/Map.h"
#include "../../model/game_object/item/stuff/Item.h"

#include <unordered_map>
#include <string>
#include <vector>
#include <memory>

namespace superrogue::view {

class CharConverter {
public:
    std::vector<std::vector<char>> convertMap(std::shared_ptr<map::MapInfo> mapInfo);
    char convertItem(game_object::item::ItemType item);
    char convertPotion();
    char convertVoidItem();
    
private:
    std::unordered_map<std::string, char> gameMapping;
};

}