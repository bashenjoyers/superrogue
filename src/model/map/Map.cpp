#include "model/map/Map.h"


namespace superrogue::map {
Map::Map(vector<Enemy> enemies, Person person, MapOptions map_options) : 
    enemies(enemies), person(person), __map_options(map_options) {
    // TODO
}
};
