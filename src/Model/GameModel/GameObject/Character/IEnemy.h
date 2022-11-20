#pragma once
#include "ICharacter.h"
#include "Model/GameModel/GameObject/Character/Class/Enemy/IEnemyClass.h"
#include "Model/GameModel/GameObject/Characteristics.h"
#include <iostream>
#include <random>
#include <string>

#include <memory>

namespace GameModel {
class IEnemy : public ICharacter {
  std::shared_ptr<IEnemyClass> enemy_class;
  void disturb() noexcept;

public:
  std::string get_description() const noexcept override;
  float get_attack_range() const noexcept;
  IEnemy(std::string name, Characteristics characteristics,
         std::shared_ptr<IEnemyClass> enemy_class);
  std::shared_ptr<IEnemyClass> get_enemy_class() const noexcept;
  bool damaged(int value) noexcept override;
  virtual ~IEnemy() {}
};
}; // namespace GameModel
