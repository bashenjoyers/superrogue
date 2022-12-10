#include "CharDataConverter.h"
#include "View/RenderData.h"
#include <algorithm>

namespace View {

std::vector<std::vector<char>> CharConverter::convertMap(std::vector<RenderEntity> entities, RenderOptions opts) {
  std::vector<std::vector<char>> ans(opts.width, std::vector<char>(opts.height, ' '));
  for (RenderEntity entity: entities) {
      char renderElem;

      switch (entity.type) {
      case RenderEntityType::FLOOR : {
              renderElem = '.';
          } break;

      case RenderEntityType::WALL : {
              renderElem = '#';
          } break;

      case RenderEntityType::PERSON : {
              renderElem = 'H';
          } break;

      case RenderEntityType::POTION : {
              renderElem = 'P';
          } break;

      case RenderEntityType::DOOR : {
              renderElem = 'D';
          } break;

      case RenderEntityType::ITEM : {
              renderElem = 'S';
          } break;

      case RenderEntityType::ENEMY : {
              renderElem = 'E';
          } break;

      case RenderEntityType::ENEMY_AGRESSIVE : {
              renderElem = 'A';
          } break;

      case RenderEntityType::ENEMY_COWARD : {
              renderElem = 'C';
          } break;

      case RenderEntityType::ENEMY_FLYING : {
              renderElem = 'F';
          } break;

      case RenderEntityType::ENEMY_INDIFFERENT : {
              renderElem = 'I';
          } break;

      case RenderEntityType::ENEMY_ORDINARY : {
              renderElem = 'O';
          } break;

      case RenderEntityType::ENEMY_TRAVELER : {
              renderElem = 'T';
          } break;

      case RenderEntityType::ENEMY_REPLICATOR : {
            renderElem = 'R';
          } break;

          default:
              renderElem = ' ';
      }

      ans[entity.pos.x][entity.pos.y] = renderElem;
  }

  return ans;
}

char CharConverter::convertItem(RenderEquipmentType item) {
  switch (item) {
  case RenderEquipmentType::ARMOR: {
    return 'A';
  } break;

  case RenderEquipmentType::BOOTS: {
    return 'B';
  } break;

  case RenderEquipmentType::HELMET: {
    return 'H';
  } break;

  case RenderEquipmentType::WEAPON_DISTANT: {
    return 'W';
  } break;

  case RenderEquipmentType::WEAPON_MELEE: {
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