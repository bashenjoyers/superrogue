//
// Created by bagrorg on 10.12.22.
//

#include "Replicator.h"
#include "Model/GameModel/abstract.h"

std::shared_ptr<GameModel::Replicator> GameModel::Replicator::clone() {
  return std::shared_ptr<Replicator>();
}

GameModel::Abstract::MapEntity GameModel::Replicator::get_map_entity() const noexcept {
  return GameModel::Abstract::MapEntity::REPLICATOR;
}

GameModel::Replicator::Replicator(std::string name,
                                  GameModel::Characteristics characteristics,
                                  int id,
                                  GameModel::EnemySettings settings, float prob) :
    Enemy(name,
          "Ordinary Enemy (without any special features. He has an increased one "
          "of the characteristics)",
          characteristics,
          id,
          EnemyStateHolder(std::make_shared<WalkEnemyState>(), Abstract::EnemyClass::REPLICATOR, settings)),
    replication_prob(prob) {

}

double GameModel::Replicator::get_replication_probability() {
  return replication_prob;
}
