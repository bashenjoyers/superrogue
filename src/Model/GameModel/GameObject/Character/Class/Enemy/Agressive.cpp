#include "Agressive.h"
#include "Model/GameModel/values.h"

using std::string;
using std::vector;

namespace GameModel {
using namespace Abstract;

Agressive::Agressive(string description, EnemySettings settings)
    : IEnemyClass(description, settings) {}

MapEntity Agressive::get_map_entity() const noexcept {
  if (get_settings().intellect < 0.9)
    return MapEntity::ENEMY_AGRESSIVE;
  return MapEntity::ENEMY;
}

CharacterAction Agressive::strategy(vector<MapEntityWithPosition> &cells,
                                    const Position &pos) noexcept {
  bool person_was = false;
  std::optional<Position> anybody_pos = std::nullopt;
  vector<CharacterAction> possible_actions = {CharacterAction::WAIT};
  for (MapEntityWithPosition cell : cells) {
    if (!person_was && cell.map_entity == MapEntity::PERSON ||
        cell.map_entity == MapEntity::ENEMY ||
        cell.map_entity == MapEntity::ENEMY_AGRESSIVE ||
        cell.map_entity == MapEntity::ENEMY_FLYING ||
        cell.map_entity == MapEntity::ENEMY_INDIFFERENT ||
        cell.map_entity == MapEntity::ENEMY_ORDINARY ||
        cell.map_entity == MapEntity::ENEMY_TRAVELER) {
      if (cell.map_entity == MapEntity::PERSON)
        person_was = true;
      anybody_pos = cell.pos;
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
  if (!anybody_pos.has_value()) {
    if (get_settings().intellect > 0.5) {
      int dx = (int)last_character_position.x - pos.x;
      int dy = (int)last_character_position.y - pos.y;
      return default_fight_behavior(dx, dy, possible_actions, false);
    }
    std::uniform_int_distribution<int> position_gen(0, possible_actions.size() -
                                                           1);
    return possible_actions[position_gen(Values::generator)];
  }
  last_character_position = anybody_pos.value();
  int dx = (int)anybody_pos.value().x - pos.x;
  int dy = (int)anybody_pos.value().y - pos.y;
  return default_fight_behavior(dx, dy, possible_actions);
}
}; // namespace GameModel
