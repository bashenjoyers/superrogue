#pragma once

#include "GameDataConverter.h"
#include "Model/GameModel/GameObject/Item/Stuff/Item.h"
#include "Model/GameModel/Map/Map.h"

#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

namespace View {

/**
 * @brief Class to convert game objects into chars
 * 
 */
class CharConverter {
public:
  /**
   * @brief convert whole map
   * 
   * @param mapInfo -- map state
   * @return std::vector<std::vector<char>> -- map chars representation
   */
  std::vector<std::vector<char>>
  convertMap(std::shared_ptr<GameModel::Map::MapInfo> mapInfo);

  /**
   * @brief convert item type into char
   * 
   * @param item -- item type
   * @return char -- char representation
   */
  char convertItem(GameModel::ItemType item);

  /**
   * @brief convert (get) potion symbol
   * 
   * @return char -- potion char representation
   */
  char convertPotion();

  /**
   * @brief convert (get) void (nothing) symbol
   * 
   * @return char -- char representation
   */
  char convertVoidItem();

private:
  std::unordered_map<std::string, char> gameMapping;
};

} // namespace View