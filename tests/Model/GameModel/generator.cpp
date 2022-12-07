#include <gtest/gtest.h>
#include "Model/GameModel/values.h"
#include "Model/GameModel/const.h"
#include "Model/GameModel/generation_utils.h"

using GameModel::Generation::enemies_count_gen;
using GameModel::Values::generator;
using GameModel::Values::generator;
using GameModel::Values::generator;
using GameModel::ENEMIES_COUNT_MAX;
using GameModel::ENEMIES_COUNT_MIN;


TEST(MODEL_GAME_MODEL, GENERATOR__ENEMIES_COUNT_GEN) {
    for (int i = 0; i < 20; i++) {
        auto count = enemies_count_gen(generator);
        ASSERT_LE(count, ENEMIES_COUNT_MAX);
        ASSERT_GE(count, ENEMIES_COUNT_MIN);
    }
}
