#pragma once
#include "Model/Exceptions/exceptions.h"
#include "Model/GameModel/GameObject/Character/CharacterAction.h"
#include "Model/GameModel/GameObject/Character/Class/Enemy/IEnemyClass.h"
#include "Model/GameModel/GameObject/Character/Class/Person/IPersonClass.h"
#include "Model/GameModel/GameObject/Character/Enemy.h"
#include "Model/GameModel/GameObject/Character/ICharacter.h"
#include "Model/GameModel/GameObject/Character/Person.h"
#include "Model/GameModel/GameObject/Characteristics.h"
#include "Model/GameModel/GameObject/Item/IItem.h"
#include "Model/GameModel/Inventory/Inventory.h"
#include "Model/GameModel/abstract.h"
#include "Model/GameModel/values.h"
#include <map>
#include <set>

/**
 * @brief The essence of the map. The game takes place on it, it can process user requests and manage other entities
 * 
 */
namespace GameModel::Map {
/**
 * @brief selection of generators for map
 * 
 */
static std::uniform_real_distribution<float> dodge_gen(0, 1);
static std::uniform_real_distribution<float> drop_gen(0, 1);
static std::uniform_int_distribution<int>
    drop_gen_i(0, Values::items_types.size() + Values::potions_types.size() - 1);

/**
 * @brief interface for anything that has a position
 * 
 */
struct WithPosition {
  Abstract::Position pos;
  virtual ~WithPosition(){};
};

/**
 * @brief Class containing person and position
 * 
 */
struct PersonWithPosition : Person, WithPosition {
  PersonWithPosition(Person& person) : Person(person){};
};

/**
 * @brief Class containing enemy and position
 * 
 */
struct EnemyWithPosition : Enemy, WithPosition {
  std::vector<Abstract::Position> area; // where Enemy can be
  EnemyWithPosition(Enemy& enemy) : Enemy(enemy){};
};

/**
 * @brief options for map generation
 * 
 */
struct MapOptions {
  int height;
  int width;
};

/**
 * @brief entity that encapsulates all the necessary information for view
 * 
 */
struct MapInfo {
  // options for map generation
  MapOptions mapOptions;
  // visible entities with their positions
  std::vector<Abstract::MapEntityWithPosition> map_positions;
  // person name
  std::string name;
  // person characteristics
  Characteristics characteristics;
  // person description
  std::string description;
  // person inventory
  Inventory::Inventory inventory;
  // character's chosen weapon - melee
  bool weapon_melee;
  MapInfo(std::vector<Abstract::MapEntityWithPosition> map_positions,
          PersonWithPosition person, MapOptions mapOptions);
};

/**
 * @brief map class on which everything happens
 * 
 */
class Map {
  MapOptions map_options;
  int level;
  std::vector<EnemyWithPosition> enemies_with_positions;
  PersonWithPosition person_with_position;
  std::shared_ptr<Person> person_ref; // using only after end of level (not IN_PROGRESS)
  std::vector<std::vector<Abstract::MapEntity>> map;
  Abstract::Position door; // cell near the edge of Map
  std::map<Abstract::Position, std::shared_ptr<IItem>> items;
  Abstract::GameStatus game_status = Abstract::GameStatus::NEXT_LVL;

  bool in_map(int x, int y) const noexcept;
  bool is_vacant_cell(int x, int y) const noexcept;
  bool is_door_cell(int x, int y) const noexcept;
  bool is_anybody_cell(int x, int y) const noexcept;
  Abstract::MapEntity get_cell_type(const Abstract::Position& pos) const noexcept;
  std::vector<Abstract::MapEntityWithPosition>
  visible_cells(const Abstract::Position &pos, int radius, bool ignore_walls,
                const std::vector<Abstract::Position> &area) const noexcept;
  std::optional<std::shared_ptr<IItem>> drop_item() const noexcept;
  void change_item();
  bool any_step_anybody(WithPosition &anybody, Abstract::Position pos) noexcept;
  bool step_anybody(CharacterAction action, WithPosition &anybody) noexcept;
  bool action_person(CharacterAction action);
  void action_enemy(CharacterAction action, EnemyWithPosition& enemy);
  void punch_cells_in_order(const std::vector<Abstract::Position>& positions,
                            const Characteristics& characteristics) noexcept;
  bool punch(ICharacter& character, const Characteristics& characteristics) noexcept;
  void generate_map_and_door() noexcept;
  void set_positions() noexcept;

  void convertMapFromBool(const std::vector<std::vector<bool>> &genMap);

public:
  /**
   * @brief Construct a new Map object
   * 
   * @param enemies - set of enemies that are on the map
   * @param person - just person
   * @param map_options - map options
   * @param level - map level
   */
  Map(std::set<Enemy> enemies, std::shared_ptr<Person> person, MapOptions map_options,
      int level);
  /**
   * @brief Get the game status. 
   * 
   * @return Abstract::GameStatus 
   *  IN_PROGRESS - normal state, the card accepts user actions and processes them
   *  NEXT_LVL - the state when the map with this level is completed and you need to go to the next one. Actions stop processing
   *  END - game over (person died), actions are not processed
   */
  Abstract::GameStatus get_game_status() const noexcept;

  /**
   * @brief performs a character action (if it is not possible, it is ignored and nothing else happens). After the character's turn, the actions of other creatures are processed and effects from things occur (for more details, see potions)
   * 
   * @param action - the player's action that he wants to do (it's clear from the name)
   * @return whether the action was performed (true if it is valid and the game is in the status IN_PROGRESS)
   */
  bool step(CharacterAction action);

  /**
   * @brief returns everything needed for the view module
   * 
   * @return MapInfo
   */
  MapInfo get_map_info() const noexcept;
};
}; // namespace GameModel::Map
