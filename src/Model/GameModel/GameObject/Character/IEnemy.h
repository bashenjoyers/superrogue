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
  // initial health, to know the difference with the current
  int init_health;
protected:
  // enemy ID on the level
  int id; // not changed
  // Enemy class. Gives certain features and strategy when playin
  std::shared_ptr<IEnemyClass> enemy_class; // not changed
public:
// redefines description to class description
  virtual std::string get_description() const noexcept override;
  virtual int getAttackRange() const noexcept override;
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
  
  // returns the step with the strategy of the current character class
  virtual CharacterAction strategy(std::vector<Abstract::MapEntityWithPosition> &cells,
                           const Abstract::Position &pos) noexcept;
  // returns character settings
  virtual EnemySettings get_settings() const noexcept;
  // returns the cell type (how to display the character on the map)
  virtual Abstract::MapEntity get_map_entity() const noexcept override;
  // returns whether the cell is free from the point of view of the enemy
  virtual bool is_vacant(Abstract::MapEntity map_entity) const noexcept;
  // Enemy class. Gives certain features and strategy when playin
  std::shared_ptr<IEnemyClass> get_enemy_class() const noexcept;
  // returns enemy id (for internal use)
  virtual void takeDamage(int damage) override;
  // internal id
  int get_id() const noexcept;
    // internal storage statements
  bool operator==(const IEnemy &other) const noexcept;
  // internal storage statements
  bool operator<(const IEnemy &other) const noexcept;
  virtual ~IEnemy() {}
};
}; // namespace GameModel
