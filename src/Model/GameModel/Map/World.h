#pragma once

#include <map>
#include <set>
#include <random>
#include "MapOptions.h"
#include "Model/GameModel/GameObject/Characteristics.h"
#include "Model/GameModel/abstract.h"
#include "Model/GameModel/Inventory/Inventory.h"
#include "Model/GameModel/GameObject/Character/ICharacter.h"

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
  Inventory::InventoryInfo inventory;
  // character's chosen weapon - melee
  bool weapon_melee;
  MapInfo(std::vector<Abstract::MapEntityWithPosition> map_positions,
		  CharacterWithPosition person, MapOptions mapOptions);
};

/**
 * @brief map class on which everything happens
 * 
 */
struct World {
  MapOptions map_options;
  std::vector<CharacterWithPosition> enemies_with_positions;
  CharacterWithPosition person_with_position;
  std::vector<std::vector<Abstract::MapEntity>> map;
  Abstract::Position door; // cell near the edge of Map
  std::map<Abstract::Position, std::shared_ptr<IItem>> items;

//  bool in_map(int x, int y) const noexcept;
//  bool is_vacant_cell(int x, int y) const noexcept;
//  bool is_door_cell(int x, int y) const noexcept;
//  bool is_anybody_cell(int x, int y) const noexcept;
//  Abstract::MapEntity get_cell_type(const Abstract::Position &pos) const noexcept;
//  std::vector<Abstract::MapEntityWithPosition>
//  visible_cells(const Abstract::Position &pos, int radius, bool ignore_walls,
//				const std::vector<Abstract::Position> &area) const noexcept;
//  void change_item();
//  bool any_step_anybody(CharacterWithPosition &anybody, Abstract::Position pos) noexcept;
//  bool any_punch_step_anybody(CharacterWithPosition &anybody, Abstract::Position pos) noexcept;
//  bool step_anybody(CharacterAction action, CharacterWithPosition &anybody) noexcept;
//  bool action_person(CharacterAction action);
//  void action_enemy(CharacterAction action, CharacterWithPosition &enemy);
//  void punch_cells_in_order(const std::vector<Abstract::Position> &positions,
//							const Characteristics &characteristics) noexcept;
//  bool punch(CharacterWithPosition &character_with_position, const Characteristics &characteristics) noexcept;
//  bool punch_step(const CharacterWithPosition &character1_with_position,
//				  const CharacterWithPosition &character2_with_position) noexcept;
//  void remove_enemy(const CharacterWithPosition &character_with_position) noexcept; // make it easier

//public:
//  /**
//   * @brief Construct a new Map object
//   *
//   * @param enemies - set of enemies that are on the map
//   * @param person - just person
//   * @param map_options - map options
//   * @param level - map level
//   */
//  World(std::shared_ptr<Generation::ItemGenerator> itemGenerator,
//		std::shared_ptr<Generation::Map::MapGenerator> mapGenerator,
//		std::shared_ptr<Generation::AbstractEnemyFactory> enemyFactory,
//		std::shared_ptr<Person> person,
//		MapOptions map_options,
//		int level);
//
//  World(const World &other) = default;
//
//  /**
//   * @brief Get the game status.
//   *
//   * @return Abstract::GameStatus
//   *  IN_PROGRESS - normal state, the card accepts user actions and processes them
//   *  NEXT_LVL - the state when the map with this level is completed and you need to go to the next one. Actions stop processing
//   *  END - game over (person died), actions are not processed
//   */
//  Abstract::GameStatus get_game_status() const noexcept;
//
//  /**
//   * @brief performs a character action (if it is not possible, it is ignored and nothing else happens). After the character's turn, the actions of other creatures are processed and effects from things occur (for more details, see potions)
//   *
//   * @param action - the player's action that he wants to do (it's clear from the name)
//   * @return whether the action was performed (true if it is valid and the game is in the status IN_PROGRESS)
//   */
//  bool step(CharacterAction action);
//
//  /**
//   * @brief returns everything needed for the view module
//   *
//   * @return MapInfo
//   */
//  MapInfo get_map_info() const noexcept;
};
}; // namespace GameModel::Map
