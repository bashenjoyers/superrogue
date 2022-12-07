#pragma once

#include "IEnemyClass.h"
#include "IReplicator.h"

namespace GameModel {
/**
 * @brief Enemy class, which is created according to the description and settings
 *
 * randomly replicates on nearest cell and has red hair
 *
 */
class RedHairReplicator : public IReplicator {
  Hair hair_type = Hair::RED;
public:
  RedHairReplicator(std::string description, EnemySettings settings = EnemySettings());
  GameModel::Hair get_hair_type() override;

  std::shared_ptr<IReplicator> clone() const override;
  Abstract::MapEntity get_map_entity() const noexcept override;
};
}; // namespace GameModel
