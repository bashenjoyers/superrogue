#pragma once
#include "IEnemy.h"
#include "Model/GameModel/GameObject/Character/Class/Enemy/IEnemyClass.h"
#include <iostream>
#include <string>
#include <memory>

namespace GameModel {
// Enemy class contains all parameters about him and actions
class Enemy : public IEnemy {
public:
  // called when the character steps
  void step() override;
  // called when the character punch smb
  void punch() override;
  /**
   * @brief Construct a new Enemy according to the standard characteristics of the object
   */
  Enemy(int id, const std::string &name, Characteristics characteristics,
        std::shared_ptr<IEnemyClass> enemy_class);
  Enemy(const Enemy &enemy) = default;
};
}; // namespace GameModel
