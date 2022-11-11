#pragma once
#include "model/game_object/character/ICharacter.h"
#include "model/game_object/character/Enemy.h"
#include "model/game_object/character/Person.h"
#include "model/game_object/character/CharacterAction.h"
#include "model/game_object/character/class/enemy/IEnemyClass.h"
#include "model/game_object/character/class/enemy/Ordinary.h"
#include "model/abstract.h"
#include "exceptions/exceptions.h"


namespace superrogue::map {
struct WithPosition {
    superrogue::abstract::Position pos;
};

struct PersonWithPosition : superrogue::game_object::character::Person, WithPosition {
    PersonWithPosition(superrogue::game_object::character::Person person) : superrogue::game_object::character::Person(person) {};
};

struct EnemyWithPosition : superrogue::game_object::character::Enemy, WithPosition {
    std::vector<superrogue::abstract::Position> area;  // where enemy can be
    EnemyWithPosition(superrogue::game_object::character::Enemy enemy) : superrogue::game_object::character::Enemy(enemy) {};
};

struct MapOptions {
    int height;
    int width;
};

class Map {
    MapOptions __map_options;
    std::vector<EnemyWithPosition> enemies_with_positions;
    PersonWithPosition person_with_position;
    std::vector<std::vector<superrogue::abstract::MapEntity>> map;
    superrogue::abstract::Position door;
    
    bool in_map(int x, int y);
    bool is_vacant_cell(int x, int y);
    bool is_anybody_cell(int x, int y);
    std::vector<superrogue::abstract::MapEntityWithPosition> visible_cells(const superrogue::abstract::Position& pos, int radius, bool ignore_walls, const std::vector<superrogue::abstract::Position>& area);
    bool __step_anybody(superrogue::game_object::character::CharacterAction action, WithPosition anybody);
    bool __action_person(superrogue::game_object::character::CharacterAction action);
    void __action_enemy(superrogue::game_object::character::CharacterAction action, EnemyWithPosition enemy);
    bool punch_cells_in_order(std::vector<superrogue::abstract::Position> positions, superrogue::Characteristics characteristics);
    bool punch(superrogue::game_object::character::ICharacter character, superrogue::Characteristics characteristics);
    
    void generate_map_and_door();
    void set_positions();
public:
    Map(std::vector<superrogue::game_object::character::Enemy> enemies, superrogue::game_object::character::Person person, MapOptions map_options);
    bool step(superrogue::game_object::character::CharacterAction action);
};
};
