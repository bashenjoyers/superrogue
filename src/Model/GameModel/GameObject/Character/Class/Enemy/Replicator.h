#pragma once

#include "Model/GameModel/GameObject/Character/Enemy.h"

namespace GameModel {
class Replicator : public Enemy {
  // the last visible position of the character, used if he is this character is smart enough (character characteristic)
  Abstract::Position last_character_position;
  float replication_prob;

public:
  // returns how to display it on the map (can hide its class if smart enough (character characteristic))
  Abstract::MapEntity get_map_entity() const noexcept override;
  Replicator(std::string name,
             Characteristics characteristics,
             int id, EnemySettings settings = EnemySettings(), float prob = DEFAULT_REPLICATION_PROBABILITY
  );

  double get_replication_probability();

  virtual std::shared_ptr<Replicator> clone();
};
}
