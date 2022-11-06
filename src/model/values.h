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

using std::unordered_map;
using std::vector;
using superrogue::game_object::item::Item;
using superrogue::game_object::item::ItemType;
using superrogue::game_object::item::Potion;
using superrogue::game_object::character::IEnemyClass;
using superrogue::game_object::character::Ordinary;
using superrogue::game_object::character::IPersonClass;
using superrogue::game_object::character::Lucky;

namespace superrogue::values {
static const unordered_map<StuffType, Item> items = {  // TODO + 2
    {StuffType::HAUBERK, Item("hauberk", "good old hauberk", Characteristics(0, 3, 0, -1, 0), ItemType::ARMOR)}
};

static const unordered_map<PotionType, Potion> potions = {
    {PotionType::DAMAGE_POTION, Potion("damage_potion", "damage increase", Characteristics(2, 0, 0, 0, 0), DEFAULT_POTION_WORK_TIME)},
    {PotionType::DAMAGE_LONG_POTION, Potion("damage_long_potion", "damage increase (long)", Characteristics(1, 0, 0, 0, 0), DEFAULT_POTION_WORK_TIME * 2)},
    {PotionType::ARMOR_POTION, Potion("damage_potion", "armor increase", Characteristics(0, 2, 0, 0, 0), DEFAULT_POTION_WORK_TIME)},
    {PotionType::ARMOR_LONG_POTION, Potion("damage_long_potion", "armor increase (long)", Characteristics(0, 1, 0, 0, 0), DEFAULT_POTION_WORK_TIME * 2)},
    {PotionType::HEALTH_POTION, Potion("damage_potion", "add 1 hp", Characteristics(0, 0, 1, 0, 0), 1)},
    {PotionType::HEALTH_BIG_POTION, Potion("damage_long_potion", "add 2 hp", Characteristics(0, 0, 2, 0, 0), 1)},
    {PotionType::DEXTERITY_POTION, Potion("damage_potion", "dexterity increase", Characteristics(0, 0, 0, 2, 0), DEFAULT_POTION_WORK_TIME)},
    {PotionType::DEXTERITY_LONG_POTION, Potion("damage_long_potion", "dexterity increase (long)", Characteristics(0, 0, 0, 1, 0), DEFAULT_POTION_WORK_TIME * 2)}
};

static vector<IEnemyClass> enemy_classes = {   // TODO add
    Ordinary("just lucky person")
};

static vector<IPersonClass> person_classes = { // TODO add
    Lucky("just lucky person")
};

static vector<string> firstnames = {
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

static vector<string> lastnames = {
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
