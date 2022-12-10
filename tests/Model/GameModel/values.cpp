#include <gtest/gtest.h>
#include "Model/GameModel/values.h"

using GameModel::Values::items_types;
using GameModel::Values::get_item;
using GameModel::Values::potions_types;
using GameModel::Values::get_potion;
using GameModel::Values::enemy_classes;
using GameModel::Values::person_classes;
using GameModel::Values::get_enemy;
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

TEST(MODEL_GAME_MODEL, VALUES__GET_PERSON) {
  auto settings = PersonSettings();
  for (auto person_class : person_classes) {
    auto person = get_person(person_class, "Lebron");
    auto description = person->get_description();
    ASSERT_NE(description.size(), 0);
    auto real_settings = person->get_settings();

    if (person_class != GameModel::Abstract::PersonClass::FARSIGHTED) ASSERT_EQ(real_settings.visible_radius, settings.visible_radius);
    else ASSERT_EQ(real_settings.visible_radius, settings.visible_radius * 2);
  }
}

TEST(MODEL_GAME_MODEL, VALUES__GET_ENEMY) {
  auto settings = EnemySettings();
  auto chars = GameModel::Characteristics(2, 2, 0, 1);
  for (auto enemy_class : enemy_classes) {
    auto enemy = get_enemy(enemy_class, "Lebron", chars, settings);
    ASSERT_NE(enemy, nullptr);
    auto description = enemy->get_description();
    ASSERT_NE(description.size(), 0);
    auto real_settings = enemy->get_settings();
    ASSERT_EQ(real_settings.visible_radius, settings.visible_radius);
    ASSERT_EQ(real_settings.attack_range, settings.attack_range);
    ASSERT_EQ(real_settings.ignore_walls, settings.ignore_walls);
    ASSERT_EQ(real_settings.intellect, settings.intellect);

    ASSERT_EQ(chars.health, enemy->get_characteristics().health);
    ASSERT_EQ(chars.luck, enemy->get_characteristics().luck);
    ASSERT_EQ(chars.armor, enemy->get_characteristics().armor);
    ASSERT_EQ(chars.damage, enemy->get_characteristics().damage);
    ASSERT_EQ(chars.dexterity, enemy->get_characteristics().dexterity);
  }
}
