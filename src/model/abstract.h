#pragma once


namespace superrogue::abstract {
enum class MapEntity {
    PERSON, 
    ENEMY,
    WALL, 
    SHADOW, 
    FLOOR,
    ITEM,
};

struct Position {
    int x, y;

    bool operator==(const Position& other) {
        return x == other.x && y == other.y;
    }
    Position(int x, int y) : x(x), y(y) {};
    Position() = default;
};

struct MapEntityWithPosition {
    Position pos;
    MapEntity map_entity;
};
};
