#pragma once

/**
 * @brief helper structures and enums for GameModel and game in general
 * 
 */

namespace GameModel::Abstract {
enum class MapEntity {
  PERSON,
  ENEMY, // only if the Class of the Enemy is not known (he is smart enough to
         // hide it)
  ENEMY_AGRESSIVE,
  ENEMY_FLYING,
  ENEMY_INDIFFERENT,
  ENEMY_ORDINARY,
  ENEMY_TRAVELER,
  WALL,
  SHADOW,
  FLOOR,
  ITEM,
  POTION,
  DOOR
};

enum class GameStatus { IN_PROGRESS, NEXT_LVL, END };

enum class PersonClass { ALCHEMIST, FARSIGHTED, LUCKY, SECRETIVE, WISE };

enum class EnemyClass { AGRESSIVE, FLYING, INDIFFERENT, ORDINARY, TRAVELER };

struct Position {
  size_t x, y;

  friend bool operator==(const Position &it, const Position &other) {
    return it.x == other.x && it.y == other.y;
  }
  friend bool operator<(const Position &it, const Position &other) {
    if (it.x == other.x) {
      return it.y < other.y;
    }
    return it.x < other.x;
  }
  Position(size_t x, size_t y) : x(x), y(y){};
  Position() = default;
};

struct MapEntityWithPosition {
  Position pos;
  MapEntity map_entity;
};
}; // namespace GameModel::Abstract
