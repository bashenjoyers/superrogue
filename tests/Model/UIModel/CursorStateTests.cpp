#include <gtest/gtest.h>
#include "Model/UIModel/CursorState.h"

TEST(CURSOR_STATE, INITIAL_VALUE) {
    UIModel::CursorState cursorState = UIModel::CursorState();
    ASSERT_EQ(cursorState.getPotionsCursor(), 0);
    ASSERT_EQ(cursorState.getEquipmentCursor(), GameModel::ItemType::HELMET);
}

TEST(CURSOR_STATE, INCREMENT_EQUIPMENT_TEST) {
    UIModel::CursorState cursorState = UIModel::CursorState();
    cursorState.incrementEquipmentCursor();
    ASSERT_EQ(cursorState.getEquipmentCursor(), GameModel::ItemType::ARMOR);
}

TEST(CURSOR_STATE, DECREMENT_EQUIPMENT_TEST) {
    UIModel::CursorState cursorState = UIModel::CursorState();
    cursorState.incrementEquipmentCursor();
    cursorState.decrementEquipmentCursor();
    ASSERT_EQ(cursorState.getEquipmentCursor(), GameModel::ItemType::HELMET);
}

TEST(CURSOR_STATE, INCREMENT_POTIONS_TEST) {
    UIModel::CursorState cursorState = UIModel::CursorState();
    cursorState.incrementPotionsCursor();
    ASSERT_EQ(cursorState.getPotionsCursor(), 1);
}

TEST(CURSOR_STATE, DECREMENT_POTIONS_TEST) {
    UIModel::CursorState cursorState = UIModel::CursorState();
    cursorState.incrementPotionsCursor();
    cursorState.decrementPotionsCursor();
    ASSERT_EQ(cursorState.getPotionsCursor(), 0);
}