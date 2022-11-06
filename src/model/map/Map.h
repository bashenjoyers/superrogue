#pragma once
#include "model/game_object/character/Enemy.h"
#include "model/game_object/character/Person.h"

using superrogue::game_object::character::Person;
using superrogue::game_object::character::Enemy;


namespace superrogue::map {
struct MapOptions {
    int height;
    int width;
};

class Map {
    MapOptions __map_options;
public:
    vector<Enemy> enemies;
    Person person;
    Map(vector<Enemy> enemies, Person person, MapOptions map_options);
};
};
