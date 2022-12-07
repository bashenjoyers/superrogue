#include "GreenHairReplicator.h"

using std::string;
using std::vector;

namespace GameModel {
using namespace Abstract;

GameModel::Hair GreenHairReplicator::get_hair_type() {
  return hair_type;
}

std::shared_ptr<IReplicator> GreenHairReplicator::clone() const {
  return std::make_shared<GreenHairReplicator>(get_description(), get_settings());
}

GreenHairReplicator::GreenHairReplicator(std::string description, EnemySettings settings) : IReplicator(description,
																										settings) {}
MapEntity GreenHairReplicator::get_map_entity() const noexcept {
  return MapEntity::ENEMY_REPLICATOR_GREEN;
}
}; // namespace GameModel
