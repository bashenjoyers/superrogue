#include <vector>
#include <set>
#include <iostream>
#include <random>
#include "model/game_object/character/Person.h"
#include "model/game_object/character/Enemy.h"
#include "model/map/Map.h"
#include "model/values.h"
#include "controller/IEvent.h"

namespace superrogue::game_manager {
struct GameOptions {
    int enemies_count;
};

class GameManager {
    int level = 0;
    superrogue::game_object::character::Person person;
    superrogue::map::MapOptions map_options;
    superrogue::game_object::character::Person generate_person() noexcept;
    std::set<superrogue::game_object::character::Enemy> generate_enemies(GameOptions game_options);
    Characteristics generate_characteristics(float characteristic_k) const noexcept;
    GameOptions generate_game_options() noexcept;
public:
    GameManager(superrogue::map::MapOptions map_options);
    std::vector<superrogue::controller::event::IEvent> events() noexcept;
    superrogue::map::Map generate_map() noexcept;
};
};
