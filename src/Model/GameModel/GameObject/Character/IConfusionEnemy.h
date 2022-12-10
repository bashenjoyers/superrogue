#pragma once
#include "Model/GameModel/GameObject/Character/Enemy.h"

namespace GameModel {
/**
 * @brief state of confusion
 * NO - normal state, no different from normal behavior
 * DISCARBED - is thrown back (on its turn it moves to a free cell or stands still if there are no such cells)
 * STAND - stands instead of his move (stunned)
 */
enum class ConfusedState {
  NO,
  DISCARBED,
  STAND
};

class IConfusionEnemy : public Enemy {
  std::shared_ptr<Enemy> internalEnemy;
  std::uniform_real_distribution<float> confuse_gen;
  ConfusedState confused_state = ConfusedState::NO;
public:
  // adds functionality to the enemy, creates the current class
  IConfusionEnemy(std::shared_ptr<Enemy> enemy);
  // updates the strategy taking into account the confusion (observes what was in annotated instance)
  virtual CharacterAction strategy(std::vector<Abstract::MapEntityWithPosition> &cells,
                           const Abstract::Position &pos) noexcept override;

  /**
   * @brief further functions that are forwarded to the passed class (what is it written above in it)
   *
   */
  virtual std::string get_name() const noexcept override;
  virtual std::string get_description() const noexcept override;
  virtual Characteristics get_characteristics() const noexcept override;
  virtual void add_health(int value) noexcept override;
  virtual void step() override;
  virtual void punch() override;
  virtual EnemySettings get_settings() const noexcept override;
  virtual Abstract::MapEntity get_map_entity() const noexcept override;
  virtual bool is_vacant(Abstract::MapEntity map_entity) const noexcept override;

  void take_damage(int damage) override;
  bool is_dead() override;
  int get_attack_range() const noexcept override;
  std::shared_ptr<Enemy> replicate() override;
};
}; // namespace GameModel
