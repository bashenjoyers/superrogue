#pragma once
#include "Model/GameModel/GameObject/Character/Class/Enemy/state/EnemyEnvironmentInfo.h"
#include "Model/GameModel/abstract.h"
#include "Model/GameModel/const.h"
#include <unordered_set>


namespace GameModel {
struct Area {
  int x1 = 0, y1 = 0, x2 = MAX_MAP_LEN, y2 = MAX_MAP_LEN; // borders included
};
/**
 * @brief enemy character settings
 * 
 */
struct EnemySettings {
  // just visibility radius
  int visible_radius = DEFAULT_VISIBLE_RADIUS;
  // can a character of this class walk through walls
  bool ignore_walls = false;
  // internal parameter for the class, affects the behavior and visibility on the map
  float intellect = 1; // [0..1]
  // attack range (can be melee or ranged like character)
  int attack_range = 1;
  // area in which enemy can be
  Area area = Area();
};
// the environment of the enemy, influencing his behavior
EnemyEnvironmentInfo get_environment_info(std::vector<Abstract::MapEntityWithPosition> &cells, const Abstract::Position &pos, const std::unordered_set<Abstract::MapEntity> smbs);
// returns whether this cell is empty for the character of the current class
bool is_vacant(Abstract::MapEntity map_entity);
}
