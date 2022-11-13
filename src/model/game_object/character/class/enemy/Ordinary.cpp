#include <vector>
#include "model/game_object/character/class/enemy/Ordinary.h"

using std::string;
using std::vector;
using superrogue::abstract::Position;
using superrogue::abstract::MapEntityWithPosition;
using superrogue::abstract::MapEntity;
using superrogue::game_object::character::CharacterAction;


namespace superrogue::game_object::character {
Ordinary::Ordinary(string description, EnemySettings settings) noexcept : IEnemyClass(description, settings) {}

CharacterAction Ordinary::strategy(vector<MapEntityWithPosition>& cells, Position& pos) noexcept {  // FIXME(copypaste)
    Position* person_pos = nullptr;
    vector<CharacterAction> possible_actions = {CharacterAction::WAIT};
    for (MapEntityWithPosition cell: cells) {
        if (cell.map_entity == MapEntity::PERSON) {
            person_pos = &cell.pos;
            continue;
        }
        if (cell.pos.x == pos.x) {
            if (cell.pos.y + 1 == pos.y && (cell.map_entity == MapEntity::FLOOR || cell.map_entity == MapEntity::ITEM || cell.map_entity == MapEntity::POTION)) {
                possible_actions.push_back(CharacterAction::STEP_RIGHT);
            } else if (cell.pos.y - 1 == pos.y && (cell.map_entity == MapEntity::FLOOR || cell.map_entity == MapEntity::ITEM || cell.map_entity == MapEntity::POTION)) {
                possible_actions.push_back(CharacterAction::STEP_LEFT);
            }
        } else if (cell.pos.y == pos.y) {
            if (cell.pos.x + 1 == pos.x && (cell.map_entity == MapEntity::FLOOR || cell.map_entity == MapEntity::ITEM || cell.map_entity == MapEntity::POTION)) {
                possible_actions.push_back(CharacterAction::STEP_FORWARD);
            } else if (cell.pos.x - 1 == pos.x && (cell.map_entity == MapEntity::FLOOR || cell.map_entity == MapEntity::ITEM || cell.map_entity == MapEntity::POTION)) {
                possible_actions.push_back(CharacterAction::STEP_BACK);
            }
        }
    }
    if (person_pos == nullptr) {
        auto position_gen = std::bind(std::uniform_int_distribution<int>(0, possible_actions.size() - 1), std::mt19937(rand_seed));
        return possible_actions[position_gen()];
    }
    int dx = person_pos->x - pos.x;
    int dy = person_pos->y - pos.y;
    if (dx <= dy) {
        if (dx == 0) {
            if (dy > 0) {
                if (dy <= get_settings().attack_range) {
                    return CharacterAction::PUNCH_RIGHT;
                } else {
                    return CharacterAction::STEP_RIGHT;
                }
            } else {
                if (-dy <= get_settings().attack_range) {
                    return CharacterAction::PUNCH_LEFT;
                } else {
                    return CharacterAction::STEP_LEFT;
                }
            }
        } else {
            if (dy > 0) {
                return CharacterAction::STEP_RIGHT;
            } else {
                return CharacterAction::STEP_LEFT;
            }
        }
    } else {
        if (dy == 0) {
            if (dx > 0) {
                if (dx <= get_settings().attack_range) {
                    return CharacterAction::PUNCH_FORWARD;
                } else {
                    return CharacterAction::STEP_FORWARD;
                }
            } else {
                if (-dx <= get_settings().attack_range) {
                    return CharacterAction::PUNCH_BACK;
                } else {
                    return CharacterAction::STEP_BACK;
                }
            }
        } else {
            if (dx > 0) {
                return CharacterAction::STEP_FORWARD;
            } else {
                return CharacterAction::STEP_BACK;
            }
        }
    }
}
};
