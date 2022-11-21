#pragma once
#include <random>

/**
 * @brief entity with a set of generators for GameModel
 * 
 */
namespace GameModel::Generation {
static std::uniform_int_distribution<int> enemies_count_gen(ENEMIES_COUNT_MIN,
                                                            ENEMIES_COUNT_MAX);
static std::uniform_real_distribution<float> luck_gen(0, 1);
static std::normal_distribution<float>
    characteristic_gen(1, CHARACTERISTIC_STANDARD_DEVIATION);
static std::uniform_int_distribution<int>
    person_class_i_gen(0, GameModel::Values::person_classes.size() - 1);
static std::uniform_int_distribution<int>
    enemy_class_i_gen(0, GameModel::Values::enemy_classes.size() - 1);
static std::uniform_int_distribution<int>
    firstname_i_gen(0, GameModel::Values::firstnames.size() - 1);
static std::uniform_int_distribution<int>
    lastname_i_gen(0, GameModel::Values::lastnames.size() - 1);
static std::uniform_real_distribution<float> intellect_gen(0, 1);
static std::uniform_int_distribution<int> melee_gen(0, 1);
static std::uniform_int_distribution<int> characteristic_i_gen(0, 3);
}; // namespace GameModel::Generation
