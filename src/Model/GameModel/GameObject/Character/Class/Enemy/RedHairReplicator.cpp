#include "RedHairReplicator.h"

using std::string;
using std::vector;

namespace GameModel {

std::shared_ptr<IReplicator> RedHairReplicator::clone() const {
  return std::make_shared<RedHairReplicator>(get_description(), get_settings());
}

GameModel::Hair GameModel::RedHairReplicator::get_hair_type() {
  return hair_type;
}

RedHairReplicator::RedHairReplicator(std::string description, EnemySettings settings) : IReplicator(description,
																									settings) {}
Abstract::MapEntity RedHairReplicator::get_map_entity() const noexcept {
  return Abstract::MapEntity::ENEMY_REPLICATOR_RED;
}
}; // namespace GameModel
