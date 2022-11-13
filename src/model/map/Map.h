#pragma once
#include <set>
#include <map>
#include "model/game_object/character/ICharacter.h"
#include "model/game_object/character/Enemy.h"
#include "model/game_object/character/Person.h"
#include "model/game_object/character/CharacterAction.h"
#include "model/game_object/character/class/enemy/IEnemyClass.h"
#include "model/game_object/character/class/enemy/Ordinary.h"
#include "model/game_object/character/class/person/IPersonClass.h"
#include "model/abstract.h"
#include "exceptions/exceptions.h"
#include "model/values.h"


namespace superrogue::map {
typedef std::__bind<std::uniform_int_distribution<int>, std::mt19937> uniform_int_gen;
typedef std::__bind<std::uniform_real_distribution<float>, std::mt19937> uniform_float_gen;
static std::mt19937::result_type rand_seed = time(0);
static uniform_float_gen dodge_gen = std::bind(std::uniform_real_distribution<float>(0,1), std::mt19937(rand_seed));
static uniform_float_gen drop_gen = std::bind(std::uniform_real_distribution<float>(0,1), std::mt19937(rand_seed));
static uniform_int_gen drop_gen_i = std::bind(std::uniform_int_distribution<int>(0, superrogue::values::items_types.size() + superrogue::values::potions_types.size() - 1), std::mt19937(rand_seed));

struct WithPosition {
    superrogue::abstract::Position pos;
    virtual ~WithPosition() {};
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
    MapOptions(int height, int width) : height(height), width(width) {};
};

struct MapInfo {
    std::vector<superrogue::abstract::MapEntityWithPosition> map_positions;
    std::string name;
    superrogue::Characteristics characteristics;
    std::string description;
    superrogue::inventory::Inventory inventory;
    bool weapon_melee;
    MapInfo(std::vector<superrogue::abstract::MapEntityWithPosition> map_positions, superrogue::map::PersonWithPosition person);
};

class Map {
    MapOptions __map_options;
    int level;
    std::set<EnemyWithPosition> enemies_with_positions;
    PersonWithPosition person_with_position;
    std::vector<std::vector<superrogue::abstract::MapEntity>> map;
    superrogue::abstract::Position door;    // cell near the edge of map
    std::map<superrogue::abstract::Position, superrogue::game_object::item::IItem> items;
    superrogue::abstract::GameStatus game_status = superrogue::abstract::GameStatus::NEXT_LVL;
    
    bool in_map(int x, int y);
    bool is_vacant_cell(int x, int y);
    bool is_door_cell(int x, int y);
    bool is_anybody_cell(int x, int y);
    superrogue::abstract::MapEntity get_cell_type(superrogue::abstract::Position pos);
    std::vector<superrogue::abstract::MapEntityWithPosition> visible_cells(const superrogue::abstract::Position& pos, int radius, bool ignore_walls, const std::vector<superrogue::abstract::Position>& area);
    std::optional<superrogue::game_object::item::IItem> drop_item();
    void change_item();
    bool __any_step_anybody(WithPosition anybody, superrogue::abstract::Position pos);
    bool __step_anybody(superrogue::game_object::character::CharacterAction action, WithPosition anybody);
    bool __action_person(superrogue::game_object::character::CharacterAction action);
    void __action_enemy(superrogue::game_object::character::CharacterAction action, EnemyWithPosition enemy);
    void punch_cells_in_order(std::vector<superrogue::abstract::Position> positions, superrogue::Characteristics characteristics);
    bool punch(superrogue::game_object::character::ICharacter character, superrogue::Characteristics characteristics);
    
    void generate_map_and_door();
    void set_positions();
public:
    Map(std::set<superrogue::game_object::character::Enemy> enemies, superrogue::game_object::character::Person person, MapOptions map_options, int level);
    abstract::GameStatus get_game_status();
    bool step(superrogue::game_object::character::CharacterAction action);
    superrogue::map::MapInfo get_map_info();
};
};
