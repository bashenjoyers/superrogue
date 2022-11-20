#pragma once
#include "IEnemy.h"
#include "Model/GameModel/GameObject/Character/Class/Enemy/IEnemyClass.h"
#include <iostream>
#include <string>
#include <memory>

namespace GameModel {
class Enemy : public IEnemy {
  int id;

public:
  void step() override;
  void punch() override;
  bool operator==(const Enemy &other) const noexcept;
  bool operator<(const Enemy &other) const noexcept;
  Enemy(int id, std::string name, Characteristics characteristics,
        std::shared_ptr<IEnemyClass> enemy_class);
  Enemy(const Enemy &enemy) = default;
};
}; // namespace GameModel
