#pragma once
#include "ICharacter.h"
#include "Model/GameModel/GameObject/Characteristics.h"
#include "Model/GameModel/GameObject/Character/Class/Enemy/state/EnemyState.h"
#include <iostream>
#include <random>
#include <string>

#include <memory>

namespace GameModel {
/**
 * @brief Enemy interface
 * 
 */
class Enemy : public ICharacter {
  // strategy change to coward
  void scare() noexcept;

  // initial health, to know the difference with the current
  int init_health;
protected:
  // character behavior when hitting it
  virtual void disturb() noexcept;

  // stores and manages states
  EnemyStateHolder state_holder;
public:
// redefines description to class description
  virtual int get_attack_range() const noexcept override;
  /**
   * @brief Construct a new Enemy by standard properties (without a description, it is taken separately) and by enemy class
   * 
   * @param name 
   * @param characteristics 
   * @param enemy_class 
   */
  Enemy(std::string name, std::string description, Characteristics characteristics, EnemyStateHolder state_holder);
  
  // returns the step with the strategy of the current character class
  virtual CharacterAction strategy(std::vector<Abstract::MapEntityWithPosition> &cells,
                           const Abstract::Position &pos) noexcept;
  // returns character settings
  virtual EnemySettings get_settings() const noexcept;
  // returns whether the cell is free from the point of view of the enemy
  virtual bool is_vacant(Abstract::MapEntity map_entity) const noexcept;
  // returns enemy id (for internal use)
  virtual void take_damage(int damage) override;

  virtual std::shared_ptr<Enemy> replicate();
  virtual ~Enemy() {}
};
}; // namespace GameModel
