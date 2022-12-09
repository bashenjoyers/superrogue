#include "Enemy.h"
#include "Model/GameModel/GameObject/Character/IConfusionEnemy.h"
#include "Model/GameModel/values.h"

using std::string;
using std::vector;
using GameModel::Abstract::MapEntityWithPosition;
using GameModel::Abstract::Position;
using namespace GameModel::Values;

namespace GameModel {
IConfusionEnemy::IConfusionEnemy(std::shared_ptr<Enemy> enemy) : Enemy(*enemy), internalEnemy(enemy) {
  confuse_gen = std::uniform_real_distribution<float>(0, 1);
  this->set_position(enemy->get_position());
};

CharacterAction IConfusionEnemy::strategy(vector<MapEntityWithPosition> &cells, const Position &pos) noexcept {
  vector<CharacterAction> possible_actions = {};
  switch (confused_state)
  {
  case ConfusedState::DISCARBED:
    confused_state = ConfusedState::STAND;
    for (MapEntityWithPosition cell : cells) {
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
    if (possible_actions.size() == 0) {
      return CharacterAction::WAIT;
    }
    break;
  case ConfusedState::STAND:
    confused_state = ConfusedState::NO;
    return CharacterAction::WAIT;
  case ConfusedState::NO:
    return internalEnemy->strategy(cells, pos);
  }
  // case ConfusedState::DISCARBED:
  std::uniform_int_distribution<int> position_gen(0, possible_actions.size() - 1);
  return possible_actions[position_gen(Values::generator)];
}

std::string IConfusionEnemy::get_name() const noexcept {
  return internalEnemy->get_name();
}

std::string IConfusionEnemy::get_description() const noexcept {
  return internalEnemy->get_description();
}

Characteristics IConfusionEnemy::get_characteristics() const noexcept {
  return internalEnemy->get_characteristics();
}

void IConfusionEnemy::add_health(int value) noexcept {
  return internalEnemy->add_health(value);
}

void IConfusionEnemy::step() {
  return internalEnemy->step();
}

void IConfusionEnemy::punch(){
  return internalEnemy->punch();
}

EnemySettings IConfusionEnemy::get_settings() const noexcept {
  return internalEnemy->get_settings();
}

Abstract::MapEntity IConfusionEnemy::get_map_entity() const noexcept {
  return internalEnemy->get_map_entity();
}

bool IConfusionEnemy::is_vacant(Abstract::MapEntity map_entity) const noexcept {
  return internalEnemy->is_vacant(map_entity);
}

void IConfusionEnemy::take_damage(int damage) {
  internalEnemy->take_damage(damage);
  if (internalEnemy->is_dead())
	return;

  float confuse = confuse_gen(Values::generator);
  if (confuse < CONFUSION_K) {
	confused_state = ConfusedState::DISCARBED;
  }
}

bool IConfusionEnemy::is_dead() {
  return internalEnemy->is_dead();
}

int IConfusionEnemy::get_attack_range() const noexcept {
  return internalEnemy->get_attack_range();
}
std::shared_ptr<Enemy> IConfusionEnemy::replicate() {
  return internalEnemy->replicate();
}

}; // namespace GameModel
