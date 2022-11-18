#include "CharDataConverter.h"
#include <algorithm>

namespace View {

// TODO FIX
std::vector<std::vector<char>>
CharConverter::convertMap(std::shared_ptr<GameModel::Map::MapInfo> mapInfo) {
  srand(time(NULL));
  size_t x = 3; // Map->Map.size();
  size_t y = 4; // Map->Map[0].size();

  std::vector<std::vector<char>> ans(x, std::vector<char>(y, '.'));
  std::transform(ans.begin(), ans.end(), ans.begin(), [](auto row) {
    std::transform(row.begin(), row.end(), row.begin(),
                   [](char e) { return (char)rand(); });

    return row;
  });
  return ans;
}

char CharConverter::convertItem(GameModel::ItemType item) {
  using GameModel::ItemType;
  switch (item) {
  case ItemType::ARMOR: {
    return 'A';
  } break;

  case ItemType::BOOTS: {
    return 'B';
  } break;

  case ItemType::HELMET: {
    return 'H';
  } break;

  case ItemType::WEAPON_DISTANT: {
    return 'W';
  } break;

  case ItemType::WEAPON_MELEE: {
    return 'M';
  } break;

  default: {
    throw std::runtime_error("Unknown Item type"); // TODO
  } break;
  }
}

char CharConverter::convertPotion() { return 'p'; }

char CharConverter::convertVoidItem() { return '$'; }

} // namespace View