#include "CharDataConverter.h"
#include <algorithm>

namespace View {

// TODO FIX
std::vector<std::vector<char>>
CharConverter::convertMap(std::shared_ptr<GameModel::Map::MapInfo> mapInfo) {
    std::vector<GameModel::Abstract::MapEntityWithPosition> positions = mapInfo->map_positions;
    GameModel::Map::MapOptions mapOptions = mapInfo->mapOptions;

  std::vector<std::vector<char>> ans(mapOptions.width, std::vector<char>(mapOptions.height, ' '));
  for (GameModel::Abstract::MapEntityWithPosition entity: positions) {
      char renderElem;

      switch (entity.map_entity) {
          case GameModel::Abstract::MapEntity::FLOOR : {
              renderElem = '.';
          } break;

          case GameModel::Abstract::MapEntity::WALL : {
              renderElem = '#';
          } break;

          case GameModel::Abstract::MapEntity::PERSON : {
              renderElem = 'H';
          } break;

          case GameModel::Abstract::MapEntity::POTION : {
              renderElem = 'P';
          } break;

          case GameModel::Abstract::MapEntity::DOOR : {
              renderElem = 'D';
          } break;

          case GameModel::Abstract::MapEntity::ITEM : {
              renderElem = 'S';
          } break;

          case GameModel::Abstract::MapEntity::ENEMY : {
              renderElem = 'E';
          } break;

          case GameModel::Abstract::MapEntity::ENEMY_AGRESSIVE : {
              renderElem = 'A';
          } break;

          case GameModel::Abstract::MapEntity::ENEMY_FLYING : {
              renderElem = 'F';
          } break;

          case GameModel::Abstract::MapEntity::ENEMY_INDIFFERENT : {
              renderElem = 'I';
          } break;

          case GameModel::Abstract::MapEntity::ENEMY_ORDINARY : {
              renderElem = 'O';
          } break;

          case GameModel::Abstract::MapEntity::ENEMY_TRAVELER : {
              renderElem = 'T';
          } break;

          default:
              renderElem = ' ';
      }

      ans[entity.pos.x][entity.pos.y] = renderElem;
  }

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