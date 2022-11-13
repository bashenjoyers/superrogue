#pragma once
#include <random>


namespace superrogue::game_manager::generator {
static std::uniform_int_distribution<int> enemies_count_gen(ENEMIES_COUNT_MIN, ENEMIES_COUNT_MAX);
static std::uniform_real_distribution<float> luck_gen(0, 1);
static std::normal_distribution<float> characteristic_gen(1,CHARACTERISTIC_STANDARD_DEVIATION);
static std::uniform_int_distribution<int> person_class_i_gen(0, superrogue::values::person_classes.size() - 1);
static std::uniform_int_distribution<int> enemy_class_i_gen(0, superrogue::values::enemy_classes.size() - 1);
static std::uniform_int_distribution<int> firstname_i_gen(0, superrogue::values::firstnames.size() - 1);
static std::uniform_int_distribution<int> lastname_i_gen(0, superrogue::values::lastnames.size() - 1);
static std::uniform_real_distribution<float> intellect_gen(0, 1);
static std::uniform_int_distribution<int> melee_gen(0, 1);
static std::uniform_int_distribution<int> characteristic_i_gen(0, 3);
};
