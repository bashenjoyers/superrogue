#pragma once
#include "Model/GameModel/GameObject/Character/IEnemy.h"

namespace GameModel {
class IConfusionEnemy : public IEnemy {
  std::shared_ptr<IEnemy> ienemy;
  std::uniform_real_distribution<float> confuse_gen;

public:
  IConfusionEnemy(std::shared_ptr<IEnemy> ienemy);
  virtual bool damaged(int value) noexcept override;
  
  virtual std::string get_name() const noexcept override;
  virtual std::string get_description() const noexcept override;
  virtual Characteristics get_characteristics() const noexcept override;
  virtual std::shared_ptr<IEnemyClass> get_enemy_class() const noexcept override;
  virtual float get_attack_range() const noexcept override;
  virtual void add_health(int value) noexcept override;
  virtual void step() override;
  virtual void punch() override;
};
}; // namespace GameModel
