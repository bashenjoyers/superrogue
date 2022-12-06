#include "IEnemy.h"
#include "Model/GameModel/GameObject/Character/IConfusionEnemy.h"
#include "Model/GameModel/values.h"

using std::string;
using std::vector;
using GameModel::Abstract::MapEntityWithPosition;
using GameModel::Abstract::Position;
using namespace GameModel::Values;

namespace GameModel {
IConfusionEnemy::IConfusionEnemy(std::shared_ptr<IEnemy> ienemy) : ienemy(ienemy) {
  enemy_class = ienemy->get_enemy_class();
  id = ienemy->get_id();
  confuse_gen = std::uniform_real_distribution<float>(0, 1);
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
    return ienemy->strategy(cells, pos);
  }
  // case ConfusedState::DISCARBED:
  std::uniform_int_distribution<int> position_gen(0, possible_actions.size() - 1);
  return possible_actions[position_gen(Values::generator)];
}

std::string IConfusionEnemy::get_name() const noexcept {
  return ienemy->get_name();
}

std::string IConfusionEnemy::get_description() const noexcept {
  return ienemy->get_description();
}

Characteristics IConfusionEnemy::get_characteristics() const noexcept {
  return ienemy->get_characteristics();
}

void IConfusionEnemy::add_health(int value) noexcept {
  return ienemy->add_health(value);
}

void IConfusionEnemy::step() {
  return ienemy->step();
}

void IConfusionEnemy::punch(){
  return ienemy->punch();
}

EnemySettings IConfusionEnemy::get_settings() const noexcept {
  return ienemy->get_settings();
}

Abstract::MapEntity IConfusionEnemy::get_map_entity() const noexcept {
  return ienemy->get_map_entity();
}

bool IConfusionEnemy::is_vacant(Abstract::MapEntity map_entity) const noexcept {
  return ienemy->is_vacant(map_entity);
}

void IConfusionEnemy::takeDamage(int damage) {
  ienemy->takeDamage(damage);
  if (ienemy->isDead())
	return;

  float confuse = confuse_gen(Values::generator);
  if (confuse < CONFUSION_K) {
	confused_state = ConfusedState::DISCARBED;
  }
}

bool IConfusionEnemy::isDead() {
  return ienemy->isDead();
}

int IConfusionEnemy::getAttackRange() const noexcept {
  return ienemy->getAttackRange();
}

}; // namespace GameModel
