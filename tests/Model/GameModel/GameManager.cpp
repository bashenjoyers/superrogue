#include <gtest/gtest.h>
#include "Model/GameModel/GameManager.h"

using GameModel::GameManager;
using GameModel::Map::MapOptions;
using GameModel::Abstract::GameStatus;
using GameModel::HEALTH_LVL_K;


TEST(MODEL_GAME_MODEL, GAME_MANAGER__CREATE) {
    auto options = MapOptions {
        .height = 100,
        .width = 100,
    };
    auto gm = GameManager(options);
    gm.generateMap();
    auto map_info = gm.getMapInfo();
    ASSERT_EQ(map_info.mapOptions.height, options.height);
    ASSERT_EQ(map_info.mapOptions.width, options.width);

    ASSERT_GE(map_info.characteristics.armor, 1);
    ASSERT_GE(map_info.characteristics.damage, 1);
    ASSERT_GE(map_info.characteristics.dexterity, 0);
    ASSERT_GE(map_info.characteristics.health, HEALTH_LVL_K);
    ASSERT_GE(map_info.characteristics.luck, 0);

    ASSERT_EQ(map_info.inventory.armor, std::nullopt);
    ASSERT_EQ(map_info.inventory.boots, std::nullopt);
    ASSERT_EQ(map_info.inventory.helmet, std::nullopt);
    ASSERT_EQ(map_info.inventory.weapon_distant, std::nullopt);
    ASSERT_EQ(map_info.inventory.weapon_melee, std::nullopt);
    ASSERT_EQ(map_info.inventory.potions.size(), 0);

    ASSERT_NE(map_info.map_positions.size(), 0);

    ASSERT_NE(map_info.description.size(), 0);

    ASSERT_NE(map_info.name.size(), 0);

    ASSERT_TRUE(map_info.weapon_melee);

    ASSERT_FALSE(gm.isOver());
}

TEST(MODEL_GAME_MODEL, GAME_MANAGER__GENERATE_MANY_MAPS) {
    auto options = MapOptions {
        .height = 100,
        .width = 100,
    };
    auto gm = GameManager(options);
    gm.generateMap();
    auto map_info = gm.getMapInfo();
    gm.generateMap();
    auto map_info2 = gm.getMapInfo();

    ASSERT_EQ(map_info.name, map_info.name);
    ASSERT_EQ(map_info.description, map_info.description);

    if (map_info.map_positions.size() == map_info2.map_positions.size()) {
        int sz = map_info.map_positions.size();
        bool same = true;
        for (int i = 0; i < sz; i++) {
            if (!(map_info.map_positions[i].map_entity == map_info2.map_positions[i].map_entity && 
                map_info.map_positions[i].pos == map_info2.map_positions[i].pos)) {
                    same = false;
                    break;
                }
        }
        ASSERT_FALSE(same);
    }
}
