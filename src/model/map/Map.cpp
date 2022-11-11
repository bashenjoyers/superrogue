#include "model/map/Map.h"

using std::vector;
using superrogue::game_object::character::IEnemyClass;
using superrogue::game_object::character::Person;
using superrogue::game_object::character::Enemy;
using superrogue::game_object::character::CharacterAction;
using superrogue::abstract::Position;
using superrogue::abstract::MapEntityWithPosition;
using superrogue::exception::StepException;
using superrogue::abstract::MapEntity;
using superrogue::game_object::character::ICharacter;


namespace superrogue::map {
Map::Map(vector<Enemy> enemies, Person person, MapOptions map_options) : 
    person_with_position(PersonWithPosition(person)), __map_options(map_options) {
    enemies_with_positions = {};
    for (Enemy enemy : enemies) {
        enemies_with_positions.push_back(EnemyWithPosition(enemy));
    }
    generate_map_and_door();     // create map and door
    set_positions();    // set person and enemies positions, enemies areas
}

void Map::set_positions() {
    // TODO
}

void Map::generate_map_and_door() {
    // TODO
}

vector<MapEntityWithPosition> Map::visible_cells(const Position& pos, int radius, bool ignore_walls, const vector<Position>& area) {
    // TODO (return cells visible from position)
}

bool Map::in_map(int x, int y) {
    return x >= 0 && y >= 0 && x < __map_options.width && y < __map_options.height;
}

bool Map::is_vacant_cell(int x, int y) {
    MapEntity map_entity = map[x][y];
    return map_entity == MapEntity::FLOOR ||  map_entity == MapEntity::ITEM;
}

bool Map::is_anybody_cell(int x, int y) {
    MapEntity map_entity = map[x][y];
    return map_entity == MapEntity::PERSON ||  map_entity == MapEntity::ENEMY;
}

bool Map::step(CharacterAction action) {
    if (!__action_person(action)) {
        return false;
    }
    for (EnemyWithPosition enemy_with_position : enemies_with_positions) {
        IEnemyClass enemy_class = enemy_with_position.get_enemy_class();
        int radius = enemy_class.get_settings().visible_radius;
        bool ignore_walls = enemy_class.get_settings().ignore_walls;
        vector<MapEntityWithPosition> cells = visible_cells(enemy_with_position.pos, radius, ignore_walls, enemy_with_position.area);
        CharacterAction enemy_action = enemy_class.strategy(cells, enemy_with_position.pos);
        __action_enemy(enemy_action, enemy_with_position);
    }
    return true;
}

bool Map::punch_cells_in_order(vector<Position> positions, Characteristics characteristics) {
    for (Position pos : positions) {
        if (!in_map(pos.x, pos.y)) 
            break;
        if (is_anybody_cell(pos.x, pos.y)) {
            if (person_with_position.pos == pos) {
                return punch(person_with_position, characteristics);
            }
            else {
                for (EnemyWithPosition enemy_with_position2 : enemies_with_positions) {
                    if (enemy_with_position2.pos == pos) {
                        return punch(enemy_with_position2, characteristics);
                    }   
                }
            }
        }
        else if (is_vacant_cell(pos.x, pos.y)) {
            continue;
        }
        else {
            break;
        }
    }
    return false;
}

bool Map::punch(ICharacter character, Characteristics characteristics) {
    // TODO   
}

bool Map::__step_anybody(CharacterAction action, WithPosition anybody) {
    bool step_was = false;
    switch (action)
    {
    case CharacterAction::STEP_FORWARD:
        if (anybody.pos.x + 1 < __map_options.width && is_vacant_cell(anybody.pos.x + 1, anybody.pos.y)) {
            anybody.pos.x += 1;
            step_was = true;
        }
        break;
    case CharacterAction::STEP_RIGHT:
        if (anybody.pos.y + 1 < __map_options.height && is_vacant_cell(anybody.pos.x, anybody.pos.y + 1)) {
            anybody.pos.y += 1;
            step_was = true;
        }
    case CharacterAction::STEP_BACK:
        if (anybody.pos.x - 1 >= 0 && is_vacant_cell(anybody.pos.x - 1, anybody.pos.y)) {
            anybody.pos.x -= 1;
            step_was = true;
        }
        break;
    case CharacterAction::STEP_LEFT:
        if (anybody.pos.y - 1 >= 0 && is_vacant_cell(anybody.pos.x, anybody.pos.y - 1)) {
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
    int range = person_with_position.is_weapon_melee() ? 1 : DISTANT_RANGE;
    Position pos = person_with_position.pos;
    vector<Position> positions = {};
    switch (action)
    {
    case CharacterAction::PUNCH_FORWARD:
        for (int i = 1; i <= range; i++) {
            positions.push_back(Position(pos.x + i, pos.y));
        }
        punch_cells_in_order(positions, person_with_position.characteristics);
        correct = true;
        break;
    case CharacterAction::PUNCH_RIGHT:
    for (int i = 1; i <= range; i++) {
            positions.push_back(Position(pos.x, pos.y + i));
        }
        punch_cells_in_order(positions, person_with_position.characteristics);
        correct = true;
        break;
    case CharacterAction::PUNCH_BACK:
    for (int i = 1; i <= range; i++) {
            positions.push_back(Position(pos.x - i, pos.y));
        }
        punch_cells_in_order(positions, person_with_position.characteristics);
        correct = true;
        break;
    case CharacterAction::PUNCH_LEFT:
    for (int i = 1; i <= range; i++) {
            positions.push_back(Position(pos.x, pos.y - i));
        }
        punch_cells_in_order(positions, person_with_position.characteristics);
        correct = true;
        break;
    case CharacterAction::POTION:
        person_with_position.potion(0);     // FIXME(get potion_i)
        correct = true;
        break;
    case CharacterAction::CHANGE_ITEM:
        person_with_position.take_item();   // FIXME
        correct = true;
        break;
    case CharacterAction::WAIT:
        correct = true;
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

void Map::__action_enemy(CharacterAction action, EnemyWithPosition enemy_with_position) {   // FIXME(copypaste)
    bool correct = false;
    int range = enemy_with_position.get_attack_range();
    Position pos = enemy_with_position.pos;
    vector<Position> positions = {};
    switch (action)
    {
    case CharacterAction::PUNCH_FORWARD:
        for (int i = 1; i <= range; i++) {
            positions.push_back(Position(pos.x + i, pos.y));
        }
        punch_cells_in_order(positions, enemy_with_position.characteristics);
        correct = true;
        break;
    case CharacterAction::PUNCH_RIGHT:
        for (int i = 1; i <= range; i++) {
            positions.push_back(Position(pos.x, pos.y + i));
        }
        punch_cells_in_order(positions, enemy_with_position.characteristics);
        correct = true;
        break;
    case CharacterAction::PUNCH_BACK:
        for (int i = 1; i <= range; i++) {
            positions.push_back(Position(pos.x - i, pos.y));
        }
        punch_cells_in_order(positions, enemy_with_position.characteristics);
        correct = true;
        break;
    case CharacterAction::PUNCH_LEFT:
        for (int i = 1; i <= range; i++) {
            positions.push_back(Position(pos.x, pos.y - i));
        }
        punch_cells_in_order(positions, enemy_with_position.characteristics);
        correct = true;
        break;
    case CharacterAction::POTION:
        break;
    case CharacterAction::CHANGE_ITEM:
        break;
    case CharacterAction::WAIT:
        correct = true; 
        break;
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
