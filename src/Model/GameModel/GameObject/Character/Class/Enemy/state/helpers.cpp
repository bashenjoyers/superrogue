#include "Model/GameModel/GameObject/Character/Class/Enemy/state/helpers.h"

using std::vector;
using std::unordered_set;


namespace GameModel {
using Abstract::MapEntityWithPosition;
using Abstract::Position;
using Abstract::MapEntity;


// creatre EnemyEnvironmentInfo for enemy
EnemyEnvironmentInfo get_environment_info(vector<MapEntityWithPosition> &cells, const Position &pos, const unordered_set<MapEntity> smbs) {
  auto info = EnemyEnvironmentInfo();
  bool person_was = false;
  info.own_pos = pos;
  for (MapEntityWithPosition cell : cells) {
    if (smbs.find(cell.map_entity) != smbs.end()) {
      if (cell.map_entity == MapEntity::PERSON) {
        info.smb_pos = cell.pos;
        person_was = true;
      }
      if (!person_was) {
        info.smb_pos = cell.pos;
      }
      continue;
    }
    if (cell.pos.x == pos.x) {
      if (cell.pos.y == pos.y + 1 && is_vacant(cell.map_entity)) {
        info.possible_actions.push_back(CharacterAction::STEP_BACK);
      } else if (cell.pos.y == pos.y - 1 && is_vacant(cell.map_entity)) {
        info.possible_actions.push_back(CharacterAction::STEP_FORWARD);
      }
    } else if (cell.pos.y == pos.y) {
      if (cell.pos.x == pos.x + 1 && is_vacant(cell.map_entity)) {
        info.possible_actions.push_back(CharacterAction::STEP_RIGHT);
      } else if (cell.pos.x == pos.x - 1 && is_vacant(cell.map_entity)) {
        info.possible_actions.push_back(CharacterAction::STEP_LEFT);
      }
    }
  }
  return info;
}

// vacant cell for enemy
bool is_vacant(Abstract::MapEntity map_entity) {
  return map_entity == MapEntity::FLOOR || map_entity == MapEntity::ITEM ||
         map_entity == MapEntity::POTION;
}
}
