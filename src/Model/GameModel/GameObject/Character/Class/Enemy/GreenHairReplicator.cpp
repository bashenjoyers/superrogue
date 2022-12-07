#include "GreenHairReplicator.h"

using std::string;
using std::vector;

namespace GameModel {
    using namespace Abstract;

    GameModel::Hair GreenHairReplicator::get_hair_type() {
        return hair_type;
    }

    IReplicator GreenHairReplicator::clone() {
        return IReplicator::clone();
    }

    GreenHairReplicator::GreenHairReplicator(std::string description, EnemySettings settings) : IReplicator(description,
                                                                                                            settings) {}
}; // namespace GameModel
