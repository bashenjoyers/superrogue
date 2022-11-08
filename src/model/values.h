#pragma once
#include <unordered_map>
#include <vector>
#include "model/game_object/item/stuff/Item.h"
#include "model/game_object/item/stuff/StuffType.h"
#include "model/game_object/item/potions/Potion.h"
#include "model/game_object/item/potions/PotionType.h"
#include "model/const.h"
#include "model/game_object/character/class/person/IPersonClass.h"
#include "model/game_object/character/class/person/Lucky.h"
#include "model/game_object/character/class/enemy/IEnemyClass.h"
#include "model/game_object/character/class/enemy/Ordinary.h"


namespace superrogue::values {
static const std::unordered_map<StuffType, superrogue::game_object::item::Item> items = {  // TODO + 2
    {StuffType::HAUBERK, superrogue::game_object::item::Item("hauberk", "good old hauberk", Characteristics(0, 3, 0, -1, 0), superrogue::game_object::item::ItemType::ARMOR)}
};

static const std::unordered_map<PotionType, superrogue::game_object::item::Potion> potions = {
    {PotionType::DAMAGE_POTION, superrogue::game_object::item::Potion("damage_potion", "damage increase", Characteristics(2, 0, 0, 0, 0), DEFAULT_POTION_WORK_TIME)},
    {PotionType::DAMAGE_LONG_POTION, superrogue::game_object::item::Potion("damage_long_potion", "damage increase (long)", Characteristics(1, 0, 0, 0, 0), DEFAULT_POTION_WORK_TIME * 2)},
    {PotionType::ARMOR_POTION, superrogue::game_object::item::Potion("damage_potion", "armor increase", Characteristics(0, 2, 0, 0, 0), DEFAULT_POTION_WORK_TIME)},
    {PotionType::ARMOR_LONG_POTION, superrogue::game_object::item::Potion("damage_long_potion", "armor increase (long)", Characteristics(0, 1, 0, 0, 0), DEFAULT_POTION_WORK_TIME * 2)},
    {PotionType::HEALTH_POTION, superrogue::game_object::item::Potion("damage_potion", "add 1 hp", Characteristics(0, 0, 1, 0, 0), 1)},
    {PotionType::HEALTH_BIG_POTION, superrogue::game_object::item::Potion("damage_long_potion", "add 2 hp", Characteristics(0, 0, 2, 0, 0), 1)},
    {PotionType::DEXTERITY_POTION, superrogue::game_object::item::Potion("damage_potion", "dexterity increase", Characteristics(0, 0, 0, 2, 0), DEFAULT_POTION_WORK_TIME)},
    {PotionType::DEXTERITY_LONG_POTION, superrogue::game_object::item::Potion("damage_long_potion", "dexterity increase (long)", Characteristics(0, 0, 0, 1, 0), DEFAULT_POTION_WORK_TIME * 2)}
};

static std::vector<superrogue::game_object::character::IEnemyClass> enemy_classes = {   // TODO add
    superrogue::game_object::character::Ordinary("just lucky person")
};

static std::vector<superrogue::game_object::character::IPersonClass> person_classes = { // TODO add
    superrogue::game_object::character::Lucky("just lucky person")
};

static std::vector<std::string> firstnames = {
    "simpleton",
    "man",
    "philosopher",
    "peasant",
    "warrior",
    "mathematician",
    "programmer",
    "philologist",
    "doctor",
    "master",
    "king",
    "Savage",
    "marauder",
    "child",
    "human"
};

static std::vector<std::string> lastnames = {
    "beautiful",
    "great",
    "impudent",
    "smart",
    "crazy",
    "predictable",
    "happy",
    "dexterous",
    "wise",
    "combat",
    "persistent",
    "business",
    "tortured",
    "quick",
    "big"
};
};
