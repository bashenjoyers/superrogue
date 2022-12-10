#include <gtest/gtest.h>

#include <memory>
#include "Model/GameModel/Inventory/Inventory.h"
#include "Model/GameModel/values.h"

using GameModel::Inventory::Inventory;
using GameModel::Item;
using GameModel::Potion;
using GameModel::Characteristics;


static auto helmet = std::make_shared<Item>("helmet", "", Characteristics(1, 1, 0, 1, 0), GameModel::ItemType::HELMET);
static auto armor = std::make_shared<Item>("armor", "", Characteristics(1, 1, 0, 1, 0), GameModel::ItemType::ARMOR);
static auto boots = std::make_shared<Item>("boots", "", Characteristics(1, 1, 0, 1, 0), GameModel::ItemType::BOOTS);
static auto weapon_distant = std::make_shared<Item>("weapon_distant", "", Characteristics(1, 1, 0, 1, 0), GameModel::ItemType::WEAPON_DISTANT);
static auto weapon_melee = std::make_shared<Item>("weapon_melee", "", Characteristics(1, 1, 0, 1, 0), GameModel::ItemType::WEAPON_MELEE);
static auto potion = std::make_shared<Potion>("potion", "", Characteristics(1, 1, 0, 1, 0), 1);


TEST(MODEL_GAME_MODEL, INVENTORY__GET_SET_ITEMS) {
    auto inventory = Inventory();
    ASSERT_EQ(inventory.get_armor(), nullptr);
    ASSERT_EQ(inventory.get_boots(), nullptr);
    ASSERT_EQ(inventory.get_helmet(), nullptr);
    ASSERT_EQ(inventory.get_weapon_distant(), nullptr);
    ASSERT_EQ(inventory.get_weapon_melee(), nullptr);
    ASSERT_EQ(inventory.get_potions().size(), 0);
    
    inventory.set_armor(armor);
    inventory.set_boots(boots);
    inventory.set_helmet(helmet);
    inventory.set_weapon_distant(weapon_distant);
    inventory.set_weapon_melee(weapon_melee);

    auto real_armor = inventory.get_armor();
    auto real_boots = inventory.get_boots();
    auto real_helmet = inventory.get_helmet();
    auto real_weapon_distant = inventory.get_weapon_distant();
    auto real_weapon_melee = inventory.get_weapon_melee();

    ASSERT_EQ(real_armor->get_characteristics().armor, armor->get_characteristics().armor);
    ASSERT_EQ(real_armor->get_characteristics().damage, armor->get_characteristics().damage);
    ASSERT_EQ(real_armor->get_characteristics().dexterity, armor->get_characteristics().dexterity);

    ASSERT_EQ(real_boots->get_characteristics().armor, boots->get_characteristics().armor);
    ASSERT_EQ(real_boots->get_characteristics().damage, boots->get_characteristics().damage);
    ASSERT_EQ(real_boots->get_characteristics().dexterity, boots->get_characteristics().dexterity);

    ASSERT_EQ(real_helmet->get_characteristics().armor, helmet->get_characteristics().armor);
    ASSERT_EQ(real_helmet->get_characteristics().damage, helmet->get_characteristics().damage);
    ASSERT_EQ(real_helmet->get_characteristics().dexterity, helmet->get_characteristics().dexterity);

    ASSERT_EQ(real_weapon_distant->get_characteristics().armor, weapon_distant->get_characteristics().armor);
    ASSERT_EQ(real_weapon_distant->get_characteristics().damage, weapon_distant->get_characteristics().damage);
    ASSERT_EQ(real_weapon_distant->get_characteristics().dexterity, weapon_distant->get_characteristics().dexterity);

    ASSERT_EQ(real_weapon_melee->get_characteristics().armor, weapon_melee->get_characteristics().armor);
    ASSERT_EQ(real_weapon_melee->get_characteristics().damage, weapon_melee->get_characteristics().damage);
    ASSERT_EQ(real_weapon_melee->get_characteristics().dexterity, weapon_melee->get_characteristics().dexterity);
}

TEST(MODEL_GAME_MODEL, INVENTORY__WRONG_SET_ITEM) {
    auto inventory = Inventory();
    ASSERT_THROW(inventory.set_armor(weapon_melee), InventoryException);
    ASSERT_THROW(inventory.set_boots(armor), InventoryException);
    ASSERT_THROW(inventory.set_helmet(boots), InventoryException);
    ASSERT_THROW(inventory.set_weapon_distant(helmet), InventoryException);
    ASSERT_THROW(inventory.set_weapon_melee(weapon_distant), InventoryException);
}

TEST(MODEL_GAME_MODEL, INVENTORY__POTIONS) {
    auto inventory = Inventory(3);
    for (int i = 0; i < 5; i++) {
        inventory.add_potion(potion);
    }
    ASSERT_EQ(inventory.get_potions().size(), 3);
    ASSERT_EQ(inventory.use_potion(2)->get_name(), potion->get_name());
    ASSERT_EQ(inventory.get_potions().size(), 2);
    ASSERT_FALSE(inventory.use_potion(2) != nullptr);
    ASSERT_EQ(inventory.get_potions().size(), 2);
    ASSERT_EQ(inventory.use_potion(0)->get_name(), potion->get_name());
    ASSERT_EQ(inventory.get_potions().size(), 1);
    ASSERT_EQ(inventory.use_potion(0)->get_name(), potion->get_name());
    ASSERT_EQ(inventory.get_potions().size(), 0);
    ASSERT_FALSE(inventory.use_potion(-1) != nullptr);
}
