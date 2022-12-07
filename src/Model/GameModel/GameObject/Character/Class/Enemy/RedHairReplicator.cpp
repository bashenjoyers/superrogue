#include "RedHairReplicator.h"

using std::string;
using std::vector;

namespace GameModel {

    IReplicator RedHairReplicator::clone() {
        return IReplicator::clone();
    }

    GameModel::Hair GameModel::RedHairReplicator::get_hair_type() {
        return hair_type;
    }

    RedHairReplicator::RedHairReplicator(std::string description, EnemySettings settings) : IReplicator(description,
                                                                                                        settings) {}
}; // namespace GameModel
