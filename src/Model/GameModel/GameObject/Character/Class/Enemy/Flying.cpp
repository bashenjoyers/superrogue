#include "Flying.h"
#include "Model/GameModel/values.h"

using std::string;
using std::vector;

namespace GameModel {
using namespace Abstract;

Flying::Flying(string description, EnemySettings settings)
    : IEnemyClass(description, settings) {}

MapEntity Flying::get_map_entity() const noexcept {
  if (get_settings().intellect < 0.9)
    return MapEntity::ENEMY_FLYING;
  return MapEntity::ENEMY;
}

CharacterAction Flying::strategy(vector<MapEntityWithPosition> &cells,
                                 const Position &pos) noexcept { // TODO
  std::optional<Position> person_pos = std::nullopt;
  vector<CharacterAction> possible_actions = {CharacterAction::WAIT};
  for (MapEntityWithPosition cell : cells) {
    if (cell.map_entity == MapEntity::PERSON) {
      person_pos = cell.pos;
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
  if (!person_pos.has_value()) {
    if (get_settings().intellect > 0.5) {
      int dx = (int)last_character_position.x - pos.x;
      int dy = (int)last_character_position.y - pos.y;
      return default_fight_behavior(dx, dy, possible_actions, false);
    }
    std::uniform_int_distribution<int> position_gen(0, possible_actions.size() -
                                                           1);
    return possible_actions[position_gen(Values::generator)];
  }
  last_character_position = person_pos.value();
  int dx = (int)person_pos.value().x - pos.x;
  int dy = (int)person_pos.value().y - pos.y;
  return default_fight_behavior(dx, dy, possible_actions);
}
}; // namespace GameModel
