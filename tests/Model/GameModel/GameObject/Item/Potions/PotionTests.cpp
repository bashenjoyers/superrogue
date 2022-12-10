#include <gtest/gtest.h>
#include "Model/GameModel/GameObject/Item/Potions/Potion.h"

TEST(POTION_TESTS, TEST_STEP) {
    GameModel::Characteristics characteristics = GameModel::Characteristics(1, 1, 1, 1, 1);
    GameModel::Potion potion = GameModel::Potion("name", "description", characteristics, 3);
    potion.step();
    ASSERT_EQ(potion.is_work(), true);
}

TEST(POTION_TESTS, TEST_IS_WORK) {
    GameModel::Characteristics characteristics = GameModel::Characteristics(1, 1, 1, 1, 1);
    GameModel::Potion potion = GameModel::Potion("name", "description", characteristics, 2);
    potion.step();
    potion.step();
    ASSERT_EQ(potion.is_work(), false);
}