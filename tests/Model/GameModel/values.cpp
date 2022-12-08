#include <gtest/gtest.h>
#include "Model/GameModel/values.h"

using GameModel::Values::items_types;
using GameModel::Values::get_item;
using GameModel::Values::potions_types;
using GameModel::Values::get_potion;
using GameModel::Values::enemy_classes;
using GameModel::Values::get_enemy_class;
using GameModel::Values::person_classes;
using GameModel::Values::get_person;
using GameModel::EnemySettings;
using GameModel::PersonSettings;


TEST(MODEL_GAME_MODEL, VALUES__GET_ITEM) {
    for (auto item_type : items_types) {
        auto item = get_item(item_type, 1);
        auto characteristics = item->get_characteristics();
        ASSERT_EQ(characteristics.health, 0);
        ASSERT_EQ(characteristics.luck, 0);
    }
}

TEST(MODEL_GAME_MODEL, VALUES__GET_POTION) {
    for (auto potion_type : potions_types) {
        auto poption = get_potion(potion_type, 1);
        auto characteristics = poption->get_characteristics();
        ASSERT_EQ(characteristics.luck, 0);
        ASSERT_TRUE(characteristics.health == 0 || (characteristics.armor == 0 && characteristics.damage == 0 && characteristics.dexterity == 0));
    }
}

TEST(MODEL_GAME_MODEL, VALUES__GET_ENEMY_CLASS) {
    auto settings = EnemySettings();
    for (auto enemy_class : enemy_classes) {
        auto enemy_class_instance = get_enemy_class(enemy_class, settings);
        auto description = enemy_class_instance->get_description();
        ASSERT_NE(description.size(), 0);
        auto real_settings = enemy_class_instance->get_settings();
        ASSERT_EQ(real_settings.attack_range, settings.attack_range);
        ASSERT_EQ(real_settings.ignore_walls, settings.ignore_walls);
        ASSERT_EQ(real_settings.intellect, settings.intellect);
        ASSERT_EQ(real_settings.visible_radius, settings.visible_radius);
    }
}

TEST(MODEL_GAME_MODEL, VALUES__GET_PERSON_CLASS) {
    auto settings = PersonSettings();
    for (auto person_class : person_classes) {
        auto person_class_instance = get_person(person_class, settings);
        auto description = person_class_instance->get_description();
        ASSERT_NE(description.size(), 0);
        auto real_settings = person_class_instance->get_settings();
        ASSERT_EQ(real_settings.visible_radius, settings.visible_radius);
    }
}
