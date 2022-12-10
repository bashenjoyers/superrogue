#pragma once

/**
 * @brief file containing constants for the game
 * 
 */

namespace GameModel {
const int PARAMETER_COUNT = 4;
const int DEFAULT_VISIBLE_RADIUS = 6;
const int DEFAULT_POTION_WORK_TIME = 5;
const int DEFAULT_POTIONS_MAX = 3;
const int POTIONS_MAX_ALCHEMIST = 5;
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
const int DEFENCE_DEFAULT_DAMAGE = 0;
const float INTELLECT_STEP_PUNCH_K = 0.7;
const float CONFUSION_K = 0.1;
const float CONCEALMENT_INTELLECT_K = 0.9;
const float SAVE_LAST_POS_INTELLECT_K = 0.5;
const float CHANGE_WALK_K = 0.1;
const float NOT_COWARD_K = 0.05;
const float ENEMY_SCARED_K = 0.3;
const float SECRETIVE_VISIBILITY_K = 0.5;
const int MAX_MAP_LEN = 1000;   // useless
const int ENEMY_AREA_SIZE = 20;
const float DEFAULT_REPLICATION_PROBABILITY = 0.1;
const float EPS = 1e-9;
}; // namespace GameModel
