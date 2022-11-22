#include <gtest/gtest.h>
#include "Model/GameModel/GameObject/Item/Stuff/Item.h"

TEST(ITEM_TESTS, GET_ITEM_TYPE_IF_ARMOR) {
    GameModel::Characteristics characteristics = GameModel::Characteristics(1, 1, 1, 1, 1);
    GameModel::Item item = GameModel::Item("name", "description", characteristics, GameModel::ItemType::ARMOR);

    ASSERT_EQ(item.get_item_type(), GameModel::ItemType::ARMOR);
}

TEST(ITEM_TESTS, GET_ITEM_TYPE_IF_HELMET) {
    GameModel::Characteristics characteristics = GameModel::Characteristics(1, 1, 1, 1, 1);
    GameModel::Item item = GameModel::Item("name", "description", characteristics, GameModel::ItemType::HELMET);

    ASSERT_EQ(item.get_item_type(), GameModel::ItemType::HELMET);
}