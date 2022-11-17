#pragma once

namespace superrogue {
const int PARAMETER_COUNT = 4;
const int DEFAULT_VISIBLE_RADIUS = 4;
const int DEFAULT_POTION_WORK_TIME = 5;
const int DEFAULT_POTIONS_MAX = 3;
const int POTIONS_MAX_ALCHEMIST = 7;
const int ENEMIES_COUNT_MIN = 5;
const int ENEMIES_COUNT_MAX = 10;
const float DEFAULT_LUCK = 0.5;
const int POINTS_IN_LVL_ITEM = 2;
const int POINTS_IN_LVL_ITEMS =
    int(DEFAULT_LUCK * POINTS_IN_LVL_ITEM * ENEMIES_COUNT_MIN);
const int POINTS_LVL_UP = 5;
const int POINTS_IN_LVL = POINTS_LVL_UP + POINTS_IN_LVL_ITEMS;
const float WEAKNESS_K = 0.7;
const int HEALTH_LVL_K = 5;
const float CHARACTERISTIC_STANDARD_DEVIATION = 0.35;
const int DISTANT_RANGE = 3;
const float DEFAULT_DODGE_CHANCE = 0.01;
const float LUCKY_LUCK = 0.9;
}; // namespace superrogue
