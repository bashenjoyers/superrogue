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
typedef std::__bind<std::uniform_int_distribution<int>, std::mt19937> uniform_int_gen;
typedef std::__bind<std::uniform_real_distribution<float>, std::mt19937> uniform_float_gen;
typedef std::__bind<std::normal_distribution<float>, std::mt19937> normal_dist;

struct GameOptions {
    int enemies_count;
};

struct Generator {
    std::mt19937::result_type rand_seed = time(0);
    uniform_int_gen enemies_count_gen = std::bind(std::uniform_int_distribution<int>(ENEMIES_COUNT_MIN, ENEMIES_COUNT_MAX), std::mt19937(rand_seed));
    uniform_float_gen luck_gen = std::bind(std::uniform_real_distribution<float>(0,1), std::mt19937(rand_seed));
    normal_dist characteristic_gen = std::bind(std::normal_distribution<float>(1,CHARACTERISTIC_STANDARD_DEVIATION), std::mt19937(rand_seed));
    uniform_int_gen person_class_i_gen = std::bind(std::uniform_int_distribution<int>(0, superrogue::values::person_classes.size() - 1), std::mt19937(rand_seed));
    uniform_int_gen enemy_class_i_gen = std::bind(std::uniform_int_distribution<int>(0, superrogue::values::enemy_classes.size() - 1), std::mt19937(rand_seed));
    uniform_int_gen firstname_i_gen = std::bind(std::uniform_int_distribution<int>(0, superrogue::values::firstnames.size() - 1), std::mt19937(rand_seed));
    uniform_int_gen lastname_i_gen = std::bind(std::uniform_int_distribution<int>(0, superrogue::values::lastnames.size() - 1), std::mt19937(rand_seed));
    uniform_float_gen intellect_gen = std::bind(std::uniform_real_distribution<float>(0,1), std::mt19937(rand_seed));
    uniform_int_gen melee_gen = std::bind(std::uniform_int_distribution<int>(0,1), std::mt19937(rand_seed));
    uniform_int_gen characteristic_i_gen = std::bind(std::uniform_int_distribution<int>(0, 3), std::mt19937(rand_seed));
    Generator() = default;
};

class GameManager {
    int __level = 0;
    superrogue::game_object::character::Person person;
    Generator __generator = Generator();
    superrogue::map::MapOptions __map_options;
    superrogue::game_object::character::Person generate_person() noexcept;
    std::set<superrogue::game_object::character::Enemy> generate_enemies(GameOptions game_options);
    Characteristics generate_characteristics(float characteristic_k) noexcept;
    GameOptions generate_game_options() noexcept;
public:
    GameManager(superrogue::map::MapOptions map_options);
    std::vector<superrogue::controller::event::IEvent> events() noexcept;
    superrogue::map::Map generate_map() noexcept;
};
};
