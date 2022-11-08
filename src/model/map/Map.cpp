#include "model/map/Map.h"

using std::vector;
using superrogue::game_object::character::IEnemyClass;
using superrogue::game_object::character::Person;
using superrogue::game_object::character::Enemy;
using superrogue::game_object::character::CharacterAction;
using superrogue::abstract::Position;
using superrogue::exception::StepException;


namespace superrogue::map {
Map::Map(vector<Enemy> enemies, Person person, MapOptions map_options) : 
    person_with_position(PersonWithPosition(person)), __map_options(map_options) {
    enemies_with_positions = {};
    for (Enemy enemy : enemies) {
        enemies_with_positions.push_back(EnemyWithPosition(enemy));
    }
    generate_map_and_door();     // create map and door
    set_positions();    // set person and enemies positions, enemies areas
    // TODO
}

void Map::set_positions() {
    // TODO
}

void Map::generate_map_and_door() {
    // TODO
}

vector<Position> Map::visible_cells(const Position& pos, int radius, bool ignore_walls, const vector<Position>& area) {
    // TODO (return cells visible from position)
}

bool Map::step(CharacterAction action) {
    if (!__action_person(action)) {
        return false;
    }
    for (EnemyWithPosition enemy_with_position : enemies_with_positions) {
        IEnemyClass enemy_class = enemy_with_position.get_enemy_class();
        int radius = enemy_class.visible_radius;
        bool ignore_walls = enemy_class.ignore_walls;
        vector<Position> cells = visible_cells(enemy_with_position.pos, radius, false, enemy_with_position.area);
        CharacterAction enemy_action = enemy_class.strategy(cells, enemy_with_position.pos, person_with_position.pos);
        __action_enemy(enemy_action, enemy_with_position);
    }
    return true;
}

bool Map::__step_anybody(CharacterAction action, WithPosition anybody) {
    bool step_was = false;
    switch (action)
    {
    case CharacterAction::STEP_FORWARD:
        if (anybody.pos.x + 1 < __map_options.width) {
            anybody.pos.x += 1;
            step_was = true;
        }
        break;
    case CharacterAction::STEP_RIGHT:
        if (anybody.pos.y + 1 < __map_options.height) {
            anybody.pos.y += 1;
            step_was = true;
        }
    case CharacterAction::STEP_BACK:
        if (anybody.pos.x - 1 >= 0) {
            anybody.pos.x -= 1;
            step_was = true;
        }
        break;
    case CharacterAction::STEP_LEFT:
        if (anybody.pos.y - 1 >= 0) {
            anybody.pos.y -= 1;
            step_was = true;
        }
        break;
    default:
        break;
    }
    return step_was;
}

bool Map::__action_person(CharacterAction action) {
    bool correct = false;
    switch (action)
    {
    case CharacterAction::PUNCH_FORWARD:
        break;
    case CharacterAction::PUNCH_RIGHT:
        break;
    case CharacterAction::PUNCH_BACK:
        break;
    case CharacterAction::PUNCH_LEFT:
        break;
    case CharacterAction::POTION:
        break;
    default:
        if (__step_anybody(action, person_with_position)) {
            person_with_position.step();
            correct = true;
        }
        break;
    }
    return correct;
}

void Map::__action_enemy(CharacterAction action, EnemyWithPosition enemy_with_position) {
    bool correct = false;
    switch (action)
    {
    case CharacterAction::PUNCH_FORWARD:
        break;
    case CharacterAction::PUNCH_RIGHT:
        break;
    case CharacterAction::PUNCH_BACK:
        break;
    case CharacterAction::PUNCH_LEFT:
        break;
    case CharacterAction::POTION:
        correct = true;
    default:
        if (__step_anybody(action, enemy_with_position)) {
            enemy_with_position.step();
            correct = true;
        }
        break;
    }
    if (!correct) {
        throw StepException("enemy: failed " + to_string(action));
    }
}
};
