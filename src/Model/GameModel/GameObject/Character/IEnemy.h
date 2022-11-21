#pragma once
#include "ICharacter.h"
#include "Model/GameModel/GameObject/Character/Class/Enemy/IEnemyClass.h"
#include "Model/GameModel/GameObject/Characteristics.h"
#include <iostream>
#include <random>
#include <string>

#include <memory>

namespace GameModel {
/**
 * @brief Enemy interface
 * 
 */
class IEnemy : public ICharacter {
  // Enemy class. Gives certain features and strategy when playin
  std::shared_ptr<IEnemyClass> enemy_class;
  // character behavior when hitting it
  void disturb() noexcept;

public:
// redefines description to class description
  std::string get_description() const noexcept override;
  // returns attack range (generated separately, does not depend on class, can be melee or ranged)
  float get_attack_range() const noexcept;
  /**
   * @brief Construct a new IEnemy by standard properties (without a description, it is taken separately) and by enemy class
   * 
   * @param name 
   * @param characteristics 
   * @param enemy_class 
   */
  IEnemy(std::string name, Characteristics characteristics,
         std::shared_ptr<IEnemyClass> enemy_class);
  // returns the class of the character
  std::shared_ptr<IEnemyClass> get_enemy_class() const noexcept;
  bool damaged(int value) noexcept override;
  virtual ~IEnemy() {}
};
}; // namespace GameModel
