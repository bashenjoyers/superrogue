#include "model/map/Map.h"


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

vector<Position> Map::visible_cells(const Position& pos, int radius, bool ignore_walls, const vector<Position>& area) {
    // TODO (return cells visible from position)
}

bool Map::step(CharacterAction action) {
    if (!__step(action)) {
        return false;
    }
    for (EnemyWithPosition enemy_with_position : enemies_with_positions) {
        auto enemy_class = enemy_with_position.enemy.get_enemy_class();
        int radius = enemy_class.visible_radius;
        bool ignore_walls = enemy_class.ignore_walls;
        vector<Position> cells = visible_cells(enemy_with_position.pos, radius, false, enemy_with_position.area);
        CharacterAction enemy_action = enemy_class.strategy(cells, enemy_with_position.pos, person_with_position.pos);
        if (!__step(enemy_action)) {    // FIXME(for enemy)
            throw GameObjectException("enemy cheated!");
        }
    }
    return true;
}

bool Map::__step(CharacterAction action) {  // not only for person
    bool correct = true;
    switch (action)
    {
    case CharacterAction::STEP_FORWARD:
        if (person_with_position.pos.x + 1 < __map_options.width) {
            person_with_position.preson.step();
            person_with_position.pos.x += 1;
        } else {
            correct = false;
        }
        break;
    case CharacterAction::STEP_RIGHT:
        if (person_with_position.pos.y + 1 < __map_options.height) {
            person_with_position.preson.step();
            person_with_position.pos.y += 1;
        } else {
            correct = false;
        }
    case CharacterAction::STEP_BACK:
        if (person_with_position.pos.x - 1 >= 0) {
            person_with_position.preson.step();
            person_with_position.pos.x -= 1;
        } else {
            correct = false;
        }
        break;
    case CharacterAction::STEP_LEFT:
        if (person_with_position.pos.y - 1 >= 0) {
            person_with_position.preson.step();
            person_with_position.pos.y -= 1;
        } else {
            correct = false;
        }
        break;
    // TODO
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
        break;
    }
    return correct;
}
};
