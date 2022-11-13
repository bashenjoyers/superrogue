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
static const std::vector<StuffType> items_types = {StuffType::HELM, StuffType::CAP, StuffType::PANAMA, StuffType::HAT, StuffType::HAUBERK, StuffType::TUNIC, StuffType::JACKET, 
    StuffType::T_SHIRT, StuffType::SNEAKERS, StuffType::SLIPPERS, StuffType::BOOTS, StuffType::SANDALS, StuffType::SWORD, StuffType::KATANA, StuffType::KNIFE, StuffType::SABER, 
    StuffType::BITA, StuffType::MACE, StuffType::SPEAR, StuffType::NUNCHUCKS, StuffType::PISTOL, StuffType::GUN, StuffType::RIFLE, StuffType::AUTOMATIC_RIFLE, StuffType::BOW, 
    StuffType::CROSSBOW, StuffType::SLING, StuffType::DIRKS};

static superrogue::game_object::item::Item get_item(StuffType stuff_type, int characteristics_k) {  // FIXME(add discription)
    switch (stuff_type)
    {
    case StuffType::HELM:
        return superrogue::game_object::item::Item("helm", "good old hauberk", Characteristics(0, 3, 0, -1, 0) * characteristics_k, superrogue::game_object::item::ItemType::HELMET);
    case StuffType::CAP:
        return superrogue::game_object::item::Item("cap", "", Characteristics(0, 1, 0, 1, 0) * characteristics_k, superrogue::game_object::item::ItemType::HELMET);
    case StuffType::PANAMA:
        return superrogue::game_object::item::Item("panama", "", Characteristics(0, 0, 0, 2, 0) * characteristics_k, superrogue::game_object::item::ItemType::HELMET);
    case StuffType::HAT:
        return superrogue::game_object::item::Item("hat", "", Characteristics(0, 2, 0, 0, 0) * characteristics_k, superrogue::game_object::item::ItemType::HELMET);
    
    case StuffType::HAUBERK:
        return superrogue::game_object::item::Item("hauberk", "", Characteristics(0, 3, 0, -1, 0) * characteristics_k, superrogue::game_object::item::ItemType::ARMOR);
    case StuffType::TUNIC:
        return superrogue::game_object::item::Item("tunic", "", Characteristics(0, 2, 0, 0, 0) * characteristics_k, superrogue::game_object::item::ItemType::ARMOR);
    case StuffType::JACKET:
        return superrogue::game_object::item::Item("jacket", "", Characteristics(0, 1, 0, 1, 0) * characteristics_k, superrogue::game_object::item::ItemType::ARMOR);
    case StuffType::T_SHIRT:
        return superrogue::game_object::item::Item("t_shirt", "", Characteristics(0, 0, 0, 2, 0) * characteristics_k, superrogue::game_object::item::ItemType::ARMOR);
    
    case StuffType::SNEAKERS:
        return superrogue::game_object::item::Item("sneakers", "", Characteristics(0, 0, 0, 2, 0) * characteristics_k, superrogue::game_object::item::ItemType::BOOTS);
    case StuffType::SLIPPERS:
        return superrogue::game_object::item::Item("slippers", "", Characteristics(1, 2, 0, -1, 0) * characteristics_k, superrogue::game_object::item::ItemType::BOOTS);
    case StuffType::BOOTS:
        return superrogue::game_object::item::Item("boots", "", Characteristics(0, 2, 0, 0, 0) * characteristics_k, superrogue::game_object::item::ItemType::BOOTS);
    case StuffType::SANDALS:
        return superrogue::game_object::item::Item("sandals", "", Characteristics(0, 1, 0, 1, 0) * characteristics_k, superrogue::game_object::item::ItemType::BOOTS);
    
    case StuffType::SWORD:
        return superrogue::game_object::item::Item("sword", "", Characteristics(4, -1, 0, -1, 0) * characteristics_k, superrogue::game_object::item::ItemType::WEAPON_MELEE);
    case StuffType::KATANA:
        return superrogue::game_object::item::Item("katana", "", Characteristics(2, 0, 0, 0, 0) * characteristics_k, superrogue::game_object::item::ItemType::WEAPON_MELEE);
    case StuffType::KNIFE:
        return superrogue::game_object::item::Item("knife", "", Characteristics(2, -1, 0, 1, 0) * characteristics_k, superrogue::game_object::item::ItemType::WEAPON_MELEE);
    case StuffType::SABER:
        return superrogue::game_object::item::Item("saber", "", Characteristics(3, -1, 0, 0, 0) * characteristics_k, superrogue::game_object::item::ItemType::WEAPON_MELEE);
    case StuffType::BITA:
        return superrogue::game_object::item::Item("bita", "", Characteristics(1, 0, 0, 1, 0) * characteristics_k, superrogue::game_object::item::ItemType::WEAPON_MELEE);
    case StuffType::MACE:
        return superrogue::game_object::item::Item("mace", "", Characteristics(3, 0, 0, -1, 0) * characteristics_k, superrogue::game_object::item::ItemType::WEAPON_MELEE);
    case StuffType::SPEAR:
        return superrogue::game_object::item::Item("spear", "", Characteristics(3, 0, 0, -1, 0) * characteristics_k, superrogue::game_object::item::ItemType::WEAPON_MELEE);
    case StuffType::NUNCHUCKS:
        return superrogue::game_object::item::Item("nunchucks", "", Characteristics(2, -2, 0, 2, 0) * characteristics_k, superrogue::game_object::item::ItemType::WEAPON_MELEE);
    
    case StuffType::PISTOL:
        return superrogue::game_object::item::Item("pistol", "", Characteristics(2, 0, 0, 0, 0) * characteristics_k, superrogue::game_object::item::ItemType::WEAPON_DISTANT);
    case StuffType::GUN:
        return superrogue::game_object::item::Item("gun", "", Characteristics(3, -1, 0, 0, 0) * characteristics_k, superrogue::game_object::item::ItemType::WEAPON_DISTANT);
    case StuffType::RIFLE:
        return superrogue::game_object::item::Item("rifle", "", Characteristics(3, 0, 0, -1, 0) * characteristics_k, superrogue::game_object::item::ItemType::WEAPON_DISTANT);
    case StuffType::AUTOMATIC_RIFLE:
        return superrogue::game_object::item::Item("automatic_rifle", "", Characteristics(4, -1, 0, -1, 0) * characteristics_k, superrogue::game_object::item::ItemType::WEAPON_DISTANT);
    case StuffType::BOW:
        return superrogue::game_object::item::Item("bow", "", Characteristics(1, 0, 0, 1, 0) * characteristics_k, superrogue::game_object::item::ItemType::WEAPON_DISTANT);
    case StuffType::CROSSBOW:
        return superrogue::game_object::item::Item("crossbow", "", Characteristics(2, -1, 0, 1, 0) * characteristics_k, superrogue::game_object::item::ItemType::WEAPON_DISTANT);
    case StuffType::SLING:
        return superrogue::game_object::item::Item("sling", "", Characteristics(2, 1, 0, -1, 0) * characteristics_k, superrogue::game_object::item::ItemType::WEAPON_DISTANT);
    case StuffType::DIRKS:
        return superrogue::game_object::item::Item("dirks", "", Characteristics(1, -1, 0, 2, 0) * characteristics_k, superrogue::game_object::item::ItemType::WEAPON_DISTANT);
    default:
        throw exception::GameObjectException("wrong StuffType");
    }
}

static const std::vector<PotionType> potions_types = {PotionType::DAMAGE_POTION, PotionType::DAMAGE_LONG_POTION, PotionType::ARMOR_POTION, PotionType::ARMOR_LONG_POTION, 
    PotionType::HEALTH_POTION, PotionType::HEALTH_BIG_POTION, PotionType::DEXTERITY_POTION, PotionType::DEXTERITY_LONG_POTION};

static superrogue::game_object::item::Potion get_potion(PotionType potion_type, int characteristics_k) {
    switch (potion_type)
    {
    case PotionType::DAMAGE_POTION:
        return superrogue::game_object::item::Potion("damage_potion", "damage increase", Characteristics(2, 0, 0, 0, 0) * characteristics_k, DEFAULT_POTION_WORK_TIME);
    case PotionType::DAMAGE_LONG_POTION:
        return superrogue::game_object::item::Potion("damage_long_potion", "damage increase (long)", Characteristics(1, 0, 0, 0, 0) * characteristics_k, DEFAULT_POTION_WORK_TIME * 2);
    case PotionType::ARMOR_POTION:
        return superrogue::game_object::item::Potion("armor_potion", "armor increase", Characteristics(0, 2, 0, 0, 0) * characteristics_k, DEFAULT_POTION_WORK_TIME);
    case PotionType::ARMOR_LONG_POTION:
        return superrogue::game_object::item::Potion("armor_long_potion", "armor increase (long)", Characteristics(0, 1, 0, 0, 0) * characteristics_k, DEFAULT_POTION_WORK_TIME * 2);
    case PotionType::HEALTH_POTION:
        return superrogue::game_object::item::Potion("health_potion", "add 1 hp", Characteristics(0, 0, 1, 0, 0) * characteristics_k, 1);
    case PotionType::HEALTH_BIG_POTION:
        return superrogue::game_object::item::Potion("health_potion_big", "add 2 hp", Characteristics(0, 0, 2, 0, 0) * characteristics_k, 1);
    case PotionType::DEXTERITY_POTION:
        return superrogue::game_object::item::Potion("dexterity_potion", "dexterity increase", Characteristics(0, 0, 0, 2, 0) * characteristics_k, DEFAULT_POTION_WORK_TIME);
    case PotionType::DEXTERITY_LONG_POTION:
        return superrogue::game_object::item::Potion("dexterity_long_potion", "dexterity increase (long)", Characteristics(0, 0, 0, 1, 0) * characteristics_k, DEFAULT_POTION_WORK_TIME * 2);
    default:
        throw exception::GameObjectException("wrong PotionType");
    }
};

static superrogue::game_object::character::IEnemyClass get_enemy_class(superrogue::abstract::EnemyClass enemy_class, superrogue::game_object::character::EnemySettings settings) {
    switch (enemy_class)
    {
    case superrogue::abstract::EnemyClass::AGRESSIVE:
        return superrogue::game_object::character::Agressive("Hates everyone (if he sees at least someone (not necessarily a character), he strives to reach him and kill)", settings);
    case superrogue::abstract::EnemyClass::FLYING:
        return superrogue::game_object::character::Flying("Looks down on everyone (can ignore all obstacles (walls))", settings);
    case superrogue::abstract::EnemyClass::INDIFFERENT:
        return superrogue::game_object::character::Indifferent("He doesn't care about anyone (ignores everyone if he doesn't start hitting first)", settings);
    case superrogue::abstract::EnemyClass::ORDINARY:
        return superrogue::game_object::character::Ordinary("Ordinary enemy (without any special features. It has an increased one of the characteristics)", settings);
    case superrogue::abstract::EnemyClass::TRAVELER:
        return superrogue::game_object::character::Traveler("Can be anywhere he wants (it can be located anywhere on the map)", settings);
    default:
        throw exception::GameObjectException("wrong PersonClass");
    }
};

static std::vector<superrogue::abstract::EnemyClass> enemy_classes = {
    superrogue::abstract::EnemyClass::AGRESSIVE,
    superrogue::abstract::EnemyClass::FLYING,
    superrogue::abstract::EnemyClass::INDIFFERENT,
    superrogue::abstract::EnemyClass::ORDINARY,
    superrogue::abstract::EnemyClass::TRAVELER
};

static superrogue::game_object::character::IPersonClass get_person_class(superrogue::abstract::PersonClass person_class, superrogue::game_object::character::PersonSettings settings) {
    switch (person_class)
    {
    case superrogue::abstract::PersonClass::ALCHEMIST:
        return superrogue::game_object::character::Alchemist("A novice alchemist (can have up to 7 potions)", settings);
    case superrogue::abstract::PersonClass::FARSIGHTED:
        return superrogue::game_object::character::Farsighted("Can see far away (the field of view is 2 times larger than the standard one)", settings);
    case superrogue::abstract::PersonClass::LUCKY:
        return superrogue::game_object::character::Lucky("Just lucky person (has luck >= 0.9)", settings);
    case superrogue::abstract::PersonClass::SECRETIVE:
        return superrogue::game_object::character::Secretive("Unrealistically secretive one (the field of view of opponents is 2 times smaller for the character)", settings);
    case superrogue::abstract::PersonClass::WISE:
        return superrogue::game_object::character::Wise("The wisest elder (can see the areas where opponents may be located)", settings);
    default:
        throw exception::GameObjectException("wrong PersonClass");
    }
};

static std::vector<superrogue::abstract::PersonClass> person_classes = {
    superrogue::abstract::PersonClass::ALCHEMIST,
    superrogue::abstract::PersonClass::FARSIGHTED,
    superrogue::abstract::PersonClass::LUCKY,
    superrogue::abstract::PersonClass::SECRETIVE,
    superrogue::abstract::PersonClass::WISE
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

static std::random_device generator;
};
