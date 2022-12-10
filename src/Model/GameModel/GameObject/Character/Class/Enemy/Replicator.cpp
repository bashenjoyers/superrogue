//
// Created by bagrorg on 10.12.22.
//

#include "Replicator.h"
#include "Model/GameModel/abstract.h"
#include "Model/GameModel/values.h"

std::shared_ptr<GameModel::Replicator> GameModel::Replicator::clone() {
  return std::make_shared<Replicator>(get_name(), characteristics, get_settings(), replication_prob);
}

GameModel::Abstract::MapEntity GameModel::Replicator::get_map_entity() const noexcept {
  return GameModel::Abstract::MapEntity::REPLICATOR;
}

GameModel::Replicator::Replicator(std::string name,
                                  GameModel::Characteristics characteristics,
                                  GameModel::EnemySettings settings, float prob) :
    Enemy(name,
          "Ordinary Enemy (without any special features. He has an increased one "
          "of the characteristics)",
          characteristics,
          EnemyStateHolder(std::make_shared<WalkEnemyState>(), Abstract::EnemyClass::REPLICATOR, settings)),
    replication_prob(prob) {

}
std::shared_ptr<GameModel::Enemy> GameModel::Replicator::replicate() {
  std::random_device r;
  std::uniform_real_distribution<float> dist(0.f, 1.f);
  if (dist(r) < replication_prob) return this->clone();
  return nullptr;
}

