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
  // character behavior when hitting it
  void disturb() noexcept;
protected:
  // enemy ID on the level
  int id; // not changed
  // Enemy class. Gives certain features and strategy when playin
  std::shared_ptr<IEnemyClass> enemy_class; // not changed
public:
// redefines description to class description
  virtual std::string get_description() const noexcept override;
  // returns attack range (generated separately, does not depend on class, can be melee or ranged)
  virtual float get_attack_range() const noexcept;
  /**
   * @brief Construct a new IEnemy by standard properties (without a description, it is taken separately) and by enemy class
   * 
   * @param name 
   * @param characteristics 
   * @param enemy_class 
   */
  IEnemy(std::string name, Characteristics characteristics,
         std::shared_ptr<IEnemyClass> enemy_class, int id);
  // returns the class of the character
  IEnemy() {};
  
  virtual CharacterAction strategy(std::vector<Abstract::MapEntityWithPosition> &cells,
                           const Abstract::Position &pos) noexcept;
  virtual EnemySettings get_settings() const noexcept;
  virtual Abstract::MapEntity get_map_entity() const noexcept override;
  virtual bool is_vacant(Abstract::MapEntity map_entity) const noexcept;
  // Enemy class. Gives certain features and strategy when playin
  std::shared_ptr<IEnemyClass> get_enemy_class() const noexcept;
  int get_id() const noexcept;
  virtual bool damaged(int value) noexcept override;
    // internal storage statements
  bool operator==(const IEnemy &other) const noexcept;
  bool operator<(const IEnemy &other) const noexcept;
  virtual ~IEnemy() {}
};
}; // namespace GameModel
