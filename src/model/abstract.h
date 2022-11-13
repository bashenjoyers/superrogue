#pragma once


namespace superrogue::abstract {
enum class MapEntity {
    PERSON, 
    ENEMY,  // only if the class of the enemy is not known (he is smart enough to hide it)
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

enum class GameStatus {
    IN_PROGRESS,
    NEXT_LVL,
    END
};

enum class PersonClass {
    ALCHEMIST,
    FARSIGHTED,
    LUCKY,
    SECRETIVE,
    WISE
};

enum class EnemyClass {
    AGRESSIVE,
    FLYING,
    INDIFFERENT,
    ORDINARY,
    TRAVELER
};

struct Position {
    int x, y;

    friend bool operator==(const Position& it, const Position& other) {
        return it.x == other.x && it.y == other.y;
    }
    friend bool operator<(const Position& it, const Position& other) {
        if (it.x == other.x) {
            return it.y < other.y;
        }
        return it.x < other.x;
    }
    Position(int x, int y) : x(x), y(y) {};
    Position() = default;
};

struct MapEntityWithPosition {
    Position pos;
    MapEntity map_entity;
};
};
