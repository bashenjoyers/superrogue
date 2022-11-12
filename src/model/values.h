#pragma once
#include <unordered_map>
#include <vector>
#include "model/game_object/item/stuff/Item.h"
#include "model/game_object/item/stuff/StuffType.h"
#include "model/game_object/item/potions/Potion.h"
#include "model/game_object/item/potions/PotionType.h"
#include "model/const.h"
#include "model/game_object/character/class/person/IPersonClass.h"
#include "model/game_object/character/class/person/Alchemist.h"
#include "model/game_object/character/class/person/Farsighted.h"
#include "model/game_object/character/class/person/Lucky.h"
#include "model/game_object/character/class/person/Secretive.h"
#include "model/game_object/character/class/person/Wise.h"
#include "model/game_object/character/class/enemy/IEnemyClass.h"
#include "model/game_object/character/class/enemy/Agressive.h"
#include "model/game_object/character/class/enemy/Flying.h"
#include "model/game_object/character/class/enemy/Indifferent.h"
#include "model/game_object/character/class/enemy/Ordinary.h"
#include "model/game_object/character/class/enemy/Traveler.h"


namespace superrogue::values {
static const std::unordered_map<StuffType, superrogue::game_object::item::Item> items = {   // TODO(set Characteristics)
    {StuffType::HELM, superrogue::game_object::item::Item("helm", "good old hauberk", Characteristics(0, 3, 0, -1, 0), superrogue::game_object::item::ItemType::HELMET)},
    {StuffType::CAP, superrogue::game_object::item::Item("cap", "", Characteristics(0, 3, 0, -1, 0), superrogue::game_object::item::ItemType::HELMET)},
    {StuffType::PANAMA, superrogue::game_object::item::Item("panama", "", Characteristics(0, 3, 0, -1, 0), superrogue::game_object::item::ItemType::HELMET)},
    {StuffType::HAT, superrogue::game_object::item::Item("hat", "", Characteristics(0, 3, 0, -1, 0), superrogue::game_object::item::ItemType::HELMET)},
    
    {StuffType::HAUBERK, superrogue::game_object::item::Item("hauberk", "", Characteristics(0, 3, 0, -1, 0), superrogue::game_object::item::ItemType::ARMOR)},
    {StuffType::TUNIC, superrogue::game_object::item::Item("tunic", "", Characteristics(0, 3, 0, -1, 0), superrogue::game_object::item::ItemType::ARMOR)},
    {StuffType::JACKET, superrogue::game_object::item::Item("jacket", "", Characteristics(0, 3, 0, -1, 0), superrogue::game_object::item::ItemType::ARMOR)},
    {StuffType::T_SHIRT, superrogue::game_object::item::Item("t_shirt", "", Characteristics(0, 3, 0, -1, 0), superrogue::game_object::item::ItemType::ARMOR)},
    
    {StuffType::SNEAKERS, superrogue::game_object::item::Item("sneakers", "", Characteristics(0, 3, 0, -1, 0), superrogue::game_object::item::ItemType::BOOTS)},
    {StuffType::SLIPPERS, superrogue::game_object::item::Item("slippers", "", Characteristics(0, 3, 0, -1, 0), superrogue::game_object::item::ItemType::BOOTS)},
    {StuffType::BOOTS, superrogue::game_object::item::Item("boots", "", Characteristics(0, 3, 0, -1, 0), superrogue::game_object::item::ItemType::BOOTS)},
    {StuffType::SANDALS, superrogue::game_object::item::Item("sandals", "", Characteristics(0, 3, 0, -1, 0), superrogue::game_object::item::ItemType::BOOTS)},
    
    {StuffType::SWORD, superrogue::game_object::item::Item("sword", "", Characteristics(0, 3, 0, -1, 0), superrogue::game_object::item::ItemType::WEAPON_MELEE)},
    {StuffType::KATANA, superrogue::game_object::item::Item("katana", "", Characteristics(0, 3, 0, -1, 0), superrogue::game_object::item::ItemType::WEAPON_MELEE)},
    {StuffType::KNIFE, superrogue::game_object::item::Item("knife", "", Characteristics(0, 3, 0, -1, 0), superrogue::game_object::item::ItemType::WEAPON_MELEE)},
    {StuffType::SABER, superrogue::game_object::item::Item("saber", "", Characteristics(0, 3, 0, -1, 0), superrogue::game_object::item::ItemType::WEAPON_MELEE)},
    {StuffType::BITA, superrogue::game_object::item::Item("bita", "", Characteristics(0, 3, 0, -1, 0), superrogue::game_object::item::ItemType::WEAPON_MELEE)},
    {StuffType::MACE, superrogue::game_object::item::Item("mace", "", Characteristics(0, 3, 0, -1, 0), superrogue::game_object::item::ItemType::WEAPON_MELEE)},
    {StuffType::SPEAR, superrogue::game_object::item::Item("spear", "", Characteristics(0, 3, 0, -1, 0), superrogue::game_object::item::ItemType::WEAPON_MELEE)},
    {StuffType::NUNCHUCKS, superrogue::game_object::item::Item("nunchucks", "", Characteristics(0, 3, 0, -1, 0), superrogue::game_object::item::ItemType::WEAPON_MELEE)},
    
    {StuffType::PISTOL, superrogue::game_object::item::Item("pistol", "", Characteristics(0, 3, 0, -1, 0), superrogue::game_object::item::ItemType::WEAPON_DISTANT)},
    {StuffType::GUN, superrogue::game_object::item::Item("gun", "", Characteristics(0, 3, 0, -1, 0), superrogue::game_object::item::ItemType::WEAPON_DISTANT)},
    {StuffType::RIFLE, superrogue::game_object::item::Item("rifle", "", Characteristics(0, 3, 0, -1, 0), superrogue::game_object::item::ItemType::WEAPON_DISTANT)},
    {StuffType::AUTOMATIC_RIFLE, superrogue::game_object::item::Item("automatic_rifle", "", Characteristics(0, 3, 0, -1, 0), superrogue::game_object::item::ItemType::WEAPON_DISTANT)},
    {StuffType::BOW, superrogue::game_object::item::Item("bow", "", Characteristics(0, 3, 0, -1, 0), superrogue::game_object::item::ItemType::WEAPON_DISTANT)},
    {StuffType::CROSSBOW, superrogue::game_object::item::Item("crossbow", "", Characteristics(0, 3, 0, -1, 0), superrogue::game_object::item::ItemType::WEAPON_DISTANT)},
    {StuffType::SLING, superrogue::game_object::item::Item("sling", "", Characteristics(0, 3, 0, -1, 0), superrogue::game_object::item::ItemType::WEAPON_DISTANT)},
    {StuffType::DIRKS, superrogue::game_object::item::Item("dirks", "", Characteristics(0, 3, 0, -1, 0), superrogue::game_object::item::ItemType::WEAPON_DISTANT)}
};

static const std::vector<StuffType> items_types = {StuffType::HELM, StuffType::CAP, StuffType::PANAMA, StuffType::HAT, StuffType::HAUBERK, StuffType::TUNIC, StuffType::JACKET, 
    StuffType::T_SHIRT, StuffType::SNEAKERS, StuffType::SLIPPERS, StuffType::BOOTS, StuffType::SANDALS, StuffType::SWORD, StuffType::KATANA, StuffType::KNIFE, StuffType::SABER, 
    StuffType::BITA, StuffType::MACE, StuffType::SPEAR, StuffType::NUNCHUCKS, StuffType::PISTOL, StuffType::GUN, StuffType::RIFLE, StuffType::AUTOMATIC_RIFLE, StuffType::BOW, 
    StuffType::CROSSBOW, StuffType::SLING, StuffType::DIRKS};

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

static const std::vector<PotionType> potions_types = {PotionType::DAMAGE_POTION, PotionType::DAMAGE_LONG_POTION, PotionType::ARMOR_POTION, PotionType::ARMOR_LONG_POTION, 
    PotionType::HEALTH_POTION, PotionType::HEALTH_BIG_POTION, PotionType::DEXTERITY_POTION, PotionType::DEXTERITY_LONG_POTION};

static std::vector<superrogue::game_object::character::IEnemyClass> enemy_classes = {
    superrogue::game_object::character::Agressive("Hates everyone (if he sees at least someone (not necessarily a character), he strives to reach him and kill)"),
    superrogue::game_object::character::Flying("Looks down on everyone (can ignore all obstacles (walls))"),
    superrogue::game_object::character::Indifferent("He doesn't care about anyone (ignores everyone if he doesn't start hitting first)"),
    superrogue::game_object::character::Ordinary("Ordinary enemy (without any special features. It has an increased one of the characteristics)"),
    superrogue::game_object::character::Traveler("Can be anywhere he wants (it can be located anywhere on the map)")
};

static std::vector<superrogue::game_object::character::IPersonClass> person_classes = {
    superrogue::game_object::character::Alchemist("A novice alchemist (can have up to 7 potions)"),
    superrogue::game_object::character::Farsighted("Can see far away (the field of view is 2 times larger than the standard one)"),
    superrogue::game_object::character::Lucky("Just lucky person (has luck >= 0.9)"),
    superrogue::game_object::character::Secretive("Unrealistically secretive one (the field of view of opponents is 2 times smaller for the character)"),
    superrogue::game_object::character::Wise("The wisest elder (can see the areas where opponents may be located)")
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
    "savage",
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
