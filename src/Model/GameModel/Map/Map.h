#pragma once
#include "Model/Exceptions/exceptions.h"
#include "Model/GameModel/abstract.h"
#include "Model/GameModel/GameObject/Character/CharacterAction.h"
#include "Model/GameModel/GameObject/Character/Enemy.h"
#include "Model/GameModel/GameObject/Character/ICharacter.h"
#include "Model/GameModel/GameObject/Character/Person.h"
#include "Model/GameModel/GameObject/Character/Class/Enemy/IEnemyClass.h"
#include "Model/GameModel/GameObject/Character/Class/Enemy/Ordinary.h"
#include "Model/GameModel/GameObject/Character/Class/Person/IPersonClass.h"
#include "Model/GameModel/GameObject/Item/IItem.h"
#include "Model/GameModel/values.h"
#include "Model/GameModel/Inventory/Inventory.h"
#include "Model/GameModel/GameObject/Characteristics.h"
#include <map>
#include <set>

namespace GameModel::Map {
static std::uniform_real_distribution<float> dodge_gen(0, 1);
static std::uniform_real_distribution<float> drop_gen(0, 1);
static std::uniform_int_distribution<int>
    drop_gen_i(0, Values::items_types.size() +
                      Values::potions_types.size() - 1);

struct WithPosition {
  Abstract::Position pos;
  virtual ~WithPosition(){};
};

struct PersonWithPosition : Person,
                            WithPosition {
  PersonWithPosition(Person person)
      : Person(person){};
};

struct EnemyWithPosition : Enemy,
                           WithPosition {
  std::vector<Abstract::Position> area; // where Enemy can be
  EnemyWithPosition(Enemy enemy)
      : Enemy(enemy){};
};

struct MapOptions {
  int height;
  int width;
};

struct MapInfo {
  std::vector<Abstract::MapEntityWithPosition> map_positions;
  std::string name;
  Characteristics characteristics;
  std::string description;
  Inventory::Inventory inventory;
  bool weapon_melee;
  MapInfo(
      std::vector<Abstract::MapEntityWithPosition> map_positions,
      PersonWithPosition person);
};

class Map {
  MapOptions map_options;
  int level;
  std::set<EnemyWithPosition> enemies_with_positions;
  PersonWithPosition person_with_position;
  std::vector<std::vector<Abstract::MapEntity>> map;
  Abstract::Position door; // cell near the edge of Map
  std::map<Abstract::Position, IItem>
      items;
  Abstract::GameStatus game_status =
      Abstract::GameStatus::NEXT_LVL;

  bool in_map(int x, int y) const noexcept;
  bool is_vacant_cell(int x, int y) const noexcept;
  bool is_door_cell(int x, int y) const noexcept;
  bool is_anybody_cell(int x, int y) const noexcept;
  Abstract::MapEntity
  get_cell_type(Abstract::Position pos) const noexcept;
  std::vector<Abstract::MapEntityWithPosition> visible_cells(
      const Abstract::Position &pos, int radius, bool ignore_walls,
      const std::vector<Abstract::Position> &area) const noexcept;
  std::optional<IItem>
  drop_item() const noexcept;
  void change_item();
  bool any_step_anybody(WithPosition anybody,
                        Abstract::Position pos) noexcept;
  bool step_anybody(CharacterAction action,
                    WithPosition anybody) noexcept;
  bool
  action_person(CharacterAction action);
  void action_enemy(CharacterAction action,
                    EnemyWithPosition enemy);
  void
  punch_cells_in_order(std::vector<Abstract::Position> positions,
                        Characteristics characteristics) noexcept;
  bool punch(ICharacter character,
             Characteristics characteristics) noexcept;
  void generate_map_and_door() const noexcept;
  void set_positions() const noexcept;

public:
  Map(std::set<Enemy> enemies,
      Person person, MapOptions map_options,
      int level);
  Abstract::GameStatus get_game_status() const noexcept;
  bool step(CharacterAction action);
  MapInfo get_map_info() const noexcept;
};
}; // namespace 
