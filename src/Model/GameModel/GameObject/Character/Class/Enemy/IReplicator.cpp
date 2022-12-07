#include "IReplicator.h"
#include "Model/GameModel/abstract.h"
#include "Model/GameModel/values.h"

using std::string;
using std::vector;

namespace GameModel {

    IReplicator::IReplicator(string description, EnemySettings settings)
            : IEnemyClass(description, settings) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dist(0, 1);
        replication_prob = dist(gen);
    }

    Abstract::MapEntity IReplicator::get_map_entity() const noexcept {
        return Abstract::MapEntity::ENEMY_REPLICATOR;
    }

    CharacterAction IReplicator::strategy(vector <Abstract::MapEntityWithPosition> &cells,
                                          const Abstract::Position &pos) noexcept {
        std::optional<Abstract::Position> person_pos = std::nullopt;
        vector<CharacterAction> possible_actions = {CharacterAction::WAIT};
        for (Abstract::MapEntityWithPosition cell: cells) {
            if (cell.map_entity == Abstract::MapEntity::PERSON) {
                person_pos = cell.pos;
                continue;
            }
            if (cell.pos.x == pos.x) {
                if (cell.pos.y == pos.y + 1 && is_vacant(cell.map_entity)) {
                    possible_actions.push_back(CharacterAction::STEP_BACK);
                } else if (cell.pos.y == pos.y - 1 && is_vacant(cell.map_entity)) {
                    possible_actions.push_back(CharacterAction::STEP_FORWARD);
                }
            } else if (cell.pos.y == pos.y) {
                if (cell.pos.x == pos.x + 1 && is_vacant(cell.map_entity)) {
                    possible_actions.push_back(CharacterAction::STEP_RIGHT);
                } else if (cell.pos.x == pos.x - 1 && is_vacant(cell.map_entity)) {
                    possible_actions.push_back(CharacterAction::STEP_LEFT);
                }
            }
        }
        if (!person_pos.has_value()) {
            if (get_settings().intellect > 0.5) {
                int dx = (int) last_character_position.x - pos.x;
                int dy = (int) last_character_position.y - pos.y;
                return default_fight_behavior(dx, dy, possible_actions, false);
            }
            std::uniform_int_distribution<int> position_gen(0, possible_actions.size() -
                                                               1);
            return possible_actions[position_gen(Values::generator)];
        }
        last_character_position = person_pos.value();
        int dx = (int) person_pos.value().x - pos.x;
        int dy = (int) person_pos.value().y - pos.y;
        return default_fight_behavior(dx, dy, possible_actions);
    }

    double IReplicator::get_replication_probability() {
        return replication_prob;
    }
}; // namespace GameModel
