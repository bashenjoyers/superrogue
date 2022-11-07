#pragma once
#include "model/game_object/character/ICharacter.h"
#include "model/game_object/character/Enemy.h"
#include "model/game_object/character/Person.h"
#include "model/game_object/character/CharacterAction.h"
#include "model/game_object/character/class/enemy/IEnemyClass.h"
#include "model/abstract.h"

using superrogue::game_object::character::IEnemyClass;
using superrogue::game_object::character::ICharacter;
using superrogue::game_object::character::Person;
using superrogue::game_object::character::Enemy;
using superrogue::game_object::character::CharacterAction;
using superrogue::abstract::Position;


namespace superrogue::map {
// struct CharacterWithPosition {
//     ICharacter character;
//     Position pos;
// };

struct PersonWithPosition {
    Person preson;
    Position pos;
    PersonWithPosition(Person person) {}; // : person(person) {};   // FIXME
};

struct EnemyWithPosition {
    Enemy enemy;
    Position pos;
    vector<Position> area;  // where enemy can be
    EnemyWithPosition(Enemy enemy) : enemy(enemy) {};
};

struct MapOptions {
    int height;
    int width;
};

class Map {
    MapOptions __map_options;
    void generate_map_and_door();
    void set_positions();
    vector<Position> visible_cells(const Position& pos, int radius, bool ignore_walls, const vector<Position>& area);
    bool __step(CharacterAction action);
public:
    vector<EnemyWithPosition> enemies_with_positions;
    PersonWithPosition person_with_position;
    vector<vector<bool>> map;
    Position door;
    Map(vector<Enemy> enemies, Person person, MapOptions map_options);
    bool step(CharacterAction action);
};
};
