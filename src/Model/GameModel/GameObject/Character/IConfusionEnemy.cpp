#include "IEnemy.h"
#include "Model/GameModel/GameObject/Character/IConfusionEnemy.h"
#include "Model/GameModel/values.h"

using std::string;
using namespace GameModel::Values;

namespace GameModel {
IConfusionEnemy::IConfusionEnemy(std::shared_ptr<IEnemy> ienemy) : ienemy(ienemy) {
  confuse_gen = std::uniform_real_distribution<float>(0, 1);
};

bool IConfusionEnemy::damaged(int value) noexcept {
  float confuse = confuse_gen(Values::generator);
  bool res = ienemy->damaged(value);
  if (confuse < CONFUSION_K) {
    // TODO
  }
  return res;
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

std::shared_ptr<IEnemyClass> IConfusionEnemy::get_enemy_class() const noexcept {
  return ienemy->get_enemy_class();
}

float IConfusionEnemy::get_attack_range() const noexcept {
  return ienemy->get_attack_range();
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
}; // namespace GameModel
