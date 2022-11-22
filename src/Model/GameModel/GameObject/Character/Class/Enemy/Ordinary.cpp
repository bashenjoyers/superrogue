#include "Ordinary.h"
#include "Model/GameModel/values.h"
#include <vector>

using std::string;
using std::vector;

namespace GameModel {
using namespace Abstract;

Ordinary::Ordinary(string description, EnemySettings settings)
    : IEnemyClass(description, settings) {}

MapEntity Ordinary::get_map_entity() const noexcept {
  if (get_settings().intellect < 0.9)
    return MapEntity::ENEMY_ORDINARY;
  return MapEntity::ENEMY;
}

CharacterAction Ordinary::strategy(vector<MapEntityWithPosition> &cells,
                                   Position &pos) noexcept {
  Position *person_pos = nullptr;
  vector<CharacterAction> possible_actions = {CharacterAction::WAIT};
  for (MapEntityWithPosition cell : cells) {
    if (cell.map_entity == MapEntity::PERSON) {
      person_pos = &cell.pos;
      continue;
    }
    if (cell.pos.x == pos.x) {
      if (cell.pos.y == pos.y + 1 && is_vacant(cell.map_entity)) {
        possible_actions.push_back(CharacterAction::STEP_BACK);
      } else if (cell.pos.y == pos.y - 1 && is_vacant(cell.map_entity)) {
        possible_actions.push_back(CharacterAction::STEP_FORWARD);
      }
    } else if (cell.pos.y == pos.y) {
      if (cell.pos.x == pos.x + 1 && is_vacant(cell.map_entity)) {
        possible_actions.push_back(CharacterAction::STEP_RIGHT);
      } else if (cell.pos.x == pos.x - 1 && is_vacant(cell.map_entity)) {
        possible_actions.push_back(CharacterAction::STEP_LEFT);
      }
    }
  }
  if (person_pos == nullptr) {
    if (get_settings().intellect > 0.5) {
      int dx = (int)last_character_position.x - pos.x;
      int dy = (int)last_character_position.y - pos.y;
      return default_fight_behavior(dx, dy, possible_actions, false);
    }
    std::uniform_int_distribution<int> position_gen(0, possible_actions.size() -
                                                           1);
    return possible_actions[position_gen(Values::generator)];
  }
  last_character_position = *person_pos;
  int dx = (int)person_pos->x - pos.x;
  int dy = (int)person_pos->y - pos.y;
  return default_fight_behavior(dx, dy, possible_actions);
}
}; // namespace GameModel
