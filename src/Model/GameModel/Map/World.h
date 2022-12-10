#pragma once

#include <map>
#include <set>
#include <random>
#include "MapOptions.h"
#include "Model/GameModel/GameObject/Characteristics.h"
#include "Model/GameModel/abstract.h"
#include "Model/GameModel/Inventory/Inventory.h"
#include "Model/GameModel/GameObject/Character/ICharacter.h"
#include "Model/GameModel/GameObject/Character/Person.h"
#include "Model/GameModel/GameObject/Character/Enemy.h"

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
		  std::shared_ptr<ICharacter> person, MapOptions mapOptions);
};

/**
 * @brief map class on which everything happens
 * 
 */
struct World {
  MapOptions map_options;
  std::vector<std::shared_ptr<Enemy>> enemies;
  std::shared_ptr<Person> person;

  std::vector<std::vector<Abstract::MapEntity>> map;
  Abstract::Position door; // cell near the edge of Map
  std::map<Abstract::Position, std::shared_ptr<IItem>> items;
};
}; // namespace GameModel::Map
