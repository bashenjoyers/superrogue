#include "model/game_object/character/class/enemy/Agressive.h"
#include "model/values.h"

using std::string;
using std::vector;
using superrogue::abstract::Position;
using superrogue::abstract::MapEntityWithPosition;
using superrogue::game_object::character::CharacterAction;
using superrogue::abstract::MapEntity;


namespace superrogue::game_object::character {
Agressive::Agressive(string description, EnemySettings settings) : IEnemyClass(description, settings) {}

MapEntity Agressive::get_map_entity() const noexcept {
    if (get_settings().intellect < 0.9)
        return MapEntity::ENEMY_AGRESSIVE;
    return MapEntity::ENEMY;
}

CharacterAction Agressive::strategy(vector<MapEntityWithPosition>& cells, Position& pos) noexcept {
    bool person_was = false;
    Position* anybody_pos = nullptr;
    vector<CharacterAction> possible_actions = {CharacterAction::WAIT};
    for (MapEntityWithPosition cell: cells) {
        if (!person_was && cell.map_entity == MapEntity::PERSON || cell.map_entity == MapEntity::ENEMY || 
            cell.map_entity == MapEntity::ENEMY_AGRESSIVE || cell.map_entity == MapEntity::ENEMY_FLYING || 
            cell.map_entity == MapEntity::ENEMY_INDIFFERENT || cell.map_entity == MapEntity::ENEMY_ORDINARY || 
            cell.map_entity == MapEntity::ENEMY_TRAVELER) {
            if (cell.map_entity == MapEntity::PERSON)
                person_was = true;
            anybody_pos = &cell.pos;
            continue;
        }
        if (cell.pos.x == pos.x) {
            if (cell.pos.y + 1 == pos.y && is_vacant(cell.map_entity)) {
                possible_actions.push_back(CharacterAction::STEP_RIGHT);
            } else if (cell.pos.y - 1 == pos.y && is_vacant(cell.map_entity)) {
                possible_actions.push_back(CharacterAction::STEP_LEFT);
            }
        } else if (cell.pos.y == pos.y) {
            if (cell.pos.x + 1 == pos.x && is_vacant(cell.map_entity)) {
                possible_actions.push_back(CharacterAction::STEP_FORWARD);
            } else if (cell.pos.x - 1 == pos.x && is_vacant(cell.map_entity)) {
                possible_actions.push_back(CharacterAction::STEP_BACK);
            }
        }
    }
    if (anybody_pos == nullptr) {
        if (get_settings().intellect > 0.5) {
            int dx = last_character_position.x - pos.x;
            int dy = last_character_position.y - pos.y;
            return default_fight_behavior(dx, dy, possible_actions, false);
        }
        std::uniform_int_distribution<int> position_gen(0, possible_actions.size() - 1);
        return possible_actions[position_gen(superrogue::values::generator)];
    }
    last_character_position = *anybody_pos;
    int dx = anybody_pos->x - pos.x;
    int dy = anybody_pos->y - pos.y;
    return default_fight_behavior(dx, dy, possible_actions);
}
};
