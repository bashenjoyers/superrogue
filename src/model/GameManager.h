#include <vector>
#include <iostream>
#include <random>
#include "model/game_object/character/Person.h"
#include "model/game_object/character/Enemy.h"
#include "model/map/Map.h"
#include "model/values.h"
#include "controller/IEvent.h"

using std::vector;
using std::mt19937;
using superrogue::game_object::character::Person;
using superrogue::game_object::character::Enemy;
using superrogue::controller::event::IEvent;
using superrogue::map::Map;
using superrogue::map::MapOptions;
using superrogue::values::enemy_classes;
using superrogue::values::person_classes;
using superrogue::values::firstnames;
using superrogue::values::lastnames;


namespace superrogue::game_manager {
typedef std::__1::__bind<std::__1::uniform_int_distribution<int>, std::__1::mt19937> uniform_int_gen;
typedef std::__1::__bind<std::__1::uniform_real_distribution<float>, std::__1::mt19937> uniform_float_gen;
typedef std::__1::__bind<std::__1::normal_distribution<float>, std::__1::mt19937> normal_dist;

struct GameOptions {
    int enemies_count;
};

struct Generator {
    mt19937::result_type rand_seed = time(0);
    uniform_int_gen enemies_count_gen = std::bind(std::uniform_int_distribution<int>(ENEMIES_COUNT_MIN, ENEMIES_COUNT_MAX), mt19937(rand_seed));
    uniform_float_gen luck_gen = std::bind(std::uniform_real_distribution<float>(0,1), mt19937(rand_seed));
    normal_dist characteristic_gen = std::bind(std::normal_distribution<float>(1,CHARACTERISTIC_STANDARD_DEVIATION), mt19937(rand_seed));
    uniform_int_gen person_class_i_gen = std::bind(std::uniform_int_distribution<int>(0, enemy_classes.size()), mt19937(rand_seed));
    uniform_int_gen enemy_class_i_gen = std::bind(std::uniform_int_distribution<int>(0, person_classes.size()), mt19937(rand_seed));
    uniform_int_gen firstname_i_gen = std::bind(std::uniform_int_distribution<int>(0, firstnames.size()), mt19937(rand_seed));
    uniform_int_gen lastname_i_gen = std::bind(std::uniform_int_distribution<int>(0, lastnames.size()), mt19937(rand_seed));
    uniform_float_gen intellect_gen = std::bind(std::uniform_real_distribution<float>(0,1), mt19937(rand_seed));
    Generator() = default;
};

class GameManager {
    int __level = 0;
    Generator __generator = Generator();
    MapOptions __map_options;
    Person generate_person() noexcept;
    vector<Enemy> generate_enemies(GameOptions game_options) noexcept;
    Characteristics generate_characteristics(float characteristic_k) noexcept;
    GameOptions generate_game_options() noexcept;
public:
    GameManager(MapOptions map_options);
    vector<IEvent> events() noexcept;
    Map generate_map() noexcept;
};
};
