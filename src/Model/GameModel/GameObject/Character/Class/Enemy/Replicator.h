#pragma once

#include "Model/GameModel/GameObject/Character/Enemy.h"

namespace GameModel {
class Replicator : public Enemy {
  float replication_prob;

public:
  // returns how to display it on the map (can hide its class if smart enough (character characteristic))
  Abstract::MapEntity get_map_entity() const noexcept override;
  Replicator(std::string name,
             Characteristics characteristics, EnemySettings settings = EnemySettings(), float prob = DEFAULT_REPLICATION_PROBABILITY
  );

  virtual std::shared_ptr<Replicator> clone();
  std::shared_ptr<Enemy> replicate() override;
};
}
