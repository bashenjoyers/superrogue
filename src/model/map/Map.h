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
static std::uniform_real_distribution<float> dodge_gen(0, 1);
static std::uniform_real_distribution<float> drop_gen(0, 1);
static std::uniform_int_distribution<int> drop_gen_i(0, superrogue::values::items_types.size() + superrogue::values::potions_types.size() - 1);

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
    MapOptions map_options;
    int level;
    std::set<EnemyWithPosition> enemies_with_positions;
    PersonWithPosition person_with_position;
    std::vector<std::vector<superrogue::abstract::MapEntity>> map;
    superrogue::abstract::Position door;    // cell near the edge of map
    std::map<superrogue::abstract::Position, superrogue::game_object::item::IItem> items;
    superrogue::abstract::GameStatus game_status = superrogue::abstract::GameStatus::NEXT_LVL;
    
    bool in_map(int x, int y) const noexcept;
    bool is_vacant_cell(int x, int y) const noexcept;
    bool is_door_cell(int x, int y) const noexcept;
    bool is_anybody_cell(int x, int y) const noexcept;
    superrogue::abstract::MapEntity get_cell_type(superrogue::abstract::Position pos) const noexcept;
    std::vector<superrogue::abstract::MapEntityWithPosition> visible_cells(const superrogue::abstract::Position& pos, int radius, bool ignore_walls, const std::vector<superrogue::abstract::Position>& area)  const noexcept;
    std::optional<superrogue::game_object::item::IItem> drop_item() const noexcept;
    void change_item();
    bool any_step_anybody(WithPosition anybody, superrogue::abstract::Position pos) noexcept;
    bool step_anybody(superrogue::game_object::character::CharacterAction action, WithPosition anybody) noexcept;
    bool action_person(superrogue::game_object::character::CharacterAction action);
    void action_enemy(superrogue::game_object::character::CharacterAction action, EnemyWithPosition enemy);
    void punch_cells_in_order(std::vector<superrogue::abstract::Position> positions, superrogue::Characteristics characteristics) noexcept;
    bool punch(superrogue::game_object::character::ICharacter character, superrogue::Characteristics characteristics) noexcept;
    void generate_map_and_door() const noexcept;
    void set_positions() const noexcept;
public:
    Map(std::set<superrogue::game_object::character::Enemy> enemies, superrogue::game_object::character::Person person, MapOptions map_options, int level);
    abstract::GameStatus get_game_status() const noexcept;
    bool step(superrogue::game_object::character::CharacterAction action);
    superrogue::map::MapInfo get_map_info() const noexcept;
};
};
