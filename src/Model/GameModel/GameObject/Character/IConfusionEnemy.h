#pragma once
#include "Model/GameModel/GameObject/Character/IEnemy.h"

namespace GameModel {
enum class ConfusedState {
  NO,
  DISCARBED,
  STAND
};

class IConfusionEnemy : public IEnemy {
  std::shared_ptr<IEnemy> ienemy;
  std::uniform_real_distribution<float> confuse_gen;
  ConfusedState confused_state = ConfusedState::NO;
public:
  IConfusionEnemy(std::shared_ptr<IEnemy> ienemy);
  
  virtual std::string get_name() const noexcept override;
  virtual std::string get_description() const noexcept override;
  virtual Characteristics get_characteristics() const noexcept override;
  virtual void add_health(int value) noexcept override;
  virtual void step() override;
  virtual void punch() override;
  virtual CharacterAction strategy(std::vector<Abstract::MapEntityWithPosition> &cells,
                           const Abstract::Position &pos) noexcept override;
  virtual EnemySettings get_settings() const noexcept override;
  virtual Abstract::MapEntity get_map_entity() const noexcept override;
  virtual bool is_vacant(Abstract::MapEntity map_entity) const noexcept override;

  void takeDamage(int damage) override;
  bool isDead() override;
  int getAttackRange() const noexcept override;
};
}; // namespace GameModel
