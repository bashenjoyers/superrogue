#pragma once
#include "const.h"
#include "Model/GameModel/GameObject/Character/Class/Enemy/Agressive.h"
#include "Model/GameModel/GameObject/Character/Class/Enemy/Flying.h"
#include "Model/GameModel/GameObject/Character/Class/Enemy/IEnemyClass.h"
#include "Model/GameModel/GameObject/Character/Class/Enemy/Indifferent.h"
#include "Model/GameModel/GameObject/Character/Class/Enemy/Ordinary.h"
#include "Model/GameModel/GameObject/Character/Class/Enemy/Traveler.h"
#include "Model/GameModel/GameObject/Character/Class/Person/Alchemist.h"
#include "Model/GameModel/GameObject/Character/Class/Person/Farsighted.h"
#include "Model/GameModel/GameObject/Character/Class/Person/IPersonClass.h"
#include "Model/GameModel/GameObject/Character/Class/Person/Lucky.h"
#include "Model/GameModel/GameObject/Character/Class/Person/Secretive.h"
#include "Model/GameModel/GameObject/Character/Class/Person/Wise.h"
#include "Model/GameModel/GameObject/Item/Potions/Potion.h"
#include "Model/GameModel/GameObject/Item/Potions/PotionType.h"
#include "Model/GameModel/GameObject/Item/Stuff/Item.h"
#include "Model/GameModel/GameObject/Item/Stuff/StuffType.h"
#include <unordered_map>
#include <vector>

namespace GameModel::Values {
static const std::vector<StuffType> items_types = {
    StuffType::HELM,     StuffType::CAP,       StuffType::PANAMA,
    StuffType::HAT,      StuffType::HAUBERK,   StuffType::TUNIC,
    StuffType::JACKET,   StuffType::T_SHIRT,   StuffType::SNEAKERS,
    StuffType::SLIPPERS, StuffType::BOOTS,     StuffType::SANDALS,
    StuffType::SWORD,    StuffType::KATANA,    StuffType::KNIFE,
    StuffType::SABER,    StuffType::BITA,      StuffType::MACE,
    StuffType::SPEAR,    StuffType::NUNCHUCKS, StuffType::PISTOL,
    StuffType::GUN,      StuffType::RIFLE,     StuffType::AUTOMATIC_RIFLE,
    StuffType::BOW,      StuffType::CROSSBOW,  StuffType::SLING,
    StuffType::DIRKS};

static GameModel::Item get_item(StuffType stuff_type,
                                                    int characteristics_k) {
  switch (stuff_type) {
  case StuffType::HELM:
    return GameModel::Item(
        "helm", "good old hauberk",
        Characteristics(0, 3, 0, -1, 0) * characteristics_k,
        GameModel::ItemType::HELMET);
  case StuffType::CAP:
    return GameModel::Item(
        "cap", "good old cap",
        Characteristics(0, 1, 0, 1, 0) * characteristics_k,
        GameModel::ItemType::HELMET);
  case StuffType::PANAMA:
    return GameModel::Item(
        "panama", "good old panama",
        Characteristics(0, 0, 0, 2, 0) * characteristics_k,
        GameModel::ItemType::HELMET);
  case StuffType::HAT:
    return GameModel::Item(
        "hat", "good old hat",
        Characteristics(0, 2, 0, 0, 0) * characteristics_k,
        GameModel::ItemType::HELMET);

  case StuffType::HAUBERK:
    return GameModel::Item(
        "hauberk", "good old hauberk",
        Characteristics(0, 3, 0, -1, 0) * characteristics_k,
        GameModel::ItemType::ARMOR);
  case StuffType::TUNIC:
    return GameModel::Item(
        "tunic", "good old tunic",
        Characteristics(0, 2, 0, 0, 0) * characteristics_k,
        GameModel::ItemType::ARMOR);
  case StuffType::JACKET:
    return GameModel::Item(
        "jacket", "good old jacket",
        Characteristics(0, 1, 0, 1, 0) * characteristics_k,
        GameModel::ItemType::ARMOR);
  case StuffType::T_SHIRT:
    return GameModel::Item(
        "t_shirt", "good old t_shirt",
        Characteristics(0, 0, 0, 2, 0) * characteristics_k,
        GameModel::ItemType::ARMOR);

  case StuffType::SNEAKERS:
    return GameModel::Item(
        "sneakers", "good old sneakers",
        Characteristics(0, 0, 0, 2, 0) * characteristics_k,
        GameModel::ItemType::BOOTS);
  case StuffType::SLIPPERS:
    return GameModel::Item(
        "slippers", "good old slippers",
        Characteristics(1, 2, 0, -1, 0) * characteristics_k,
        GameModel::ItemType::BOOTS);
  case StuffType::BOOTS:
    return GameModel::Item(
        "boots", "good old boots",
        Characteristics(0, 2, 0, 0, 0) * characteristics_k,
        GameModel::ItemType::BOOTS);
  case StuffType::SANDALS:
    return GameModel::Item(
        "sandals", "good old sandals",
        Characteristics(0, 1, 0, 1, 0) * characteristics_k,
        GameModel::ItemType::BOOTS);

  case StuffType::SWORD:
    return GameModel::Item(
        "sword", "good old sword",
        Characteristics(4, -1, 0, -1, 0) * characteristics_k,
        GameModel::ItemType::WEAPON_MELEE);
  case StuffType::KATANA:
    return GameModel::Item(
        "katana", "good old katana",
        Characteristics(2, 0, 0, 0, 0) * characteristics_k,
        GameModel::ItemType::WEAPON_MELEE);
  case StuffType::KNIFE:
    return GameModel::Item(
        "knife", "good old knife",
        Characteristics(2, -1, 0, 1, 0) * characteristics_k,
        GameModel::ItemType::WEAPON_MELEE);
  case StuffType::SABER:
    return GameModel::Item(
        "saber", "good old saber",
        Characteristics(3, -1, 0, 0, 0) * characteristics_k,
        GameModel::ItemType::WEAPON_MELEE);
  case StuffType::BITA:
    return GameModel::Item(
        "bita", "good old bita",
        Characteristics(1, 0, 0, 1, 0) * characteristics_k,
        GameModel::ItemType::WEAPON_MELEE);
  case StuffType::MACE:
    return GameModel::Item(
        "mace", "good old mace",
        Characteristics(3, 0, 0, -1, 0) * characteristics_k,
        GameModel::ItemType::WEAPON_MELEE);
  case StuffType::SPEAR:
    return GameModel::Item(
        "spear", "good old spear",
        Characteristics(3, 0, 0, -1, 0) * characteristics_k,
        GameModel::ItemType::WEAPON_MELEE);
  case StuffType::NUNCHUCKS:
    return GameModel::Item(
        "nunchucks", "good old nunchucks",
        Characteristics(2, -2, 0, 2, 0) * characteristics_k,
        GameModel::ItemType::WEAPON_MELEE);

  case StuffType::PISTOL:
    return GameModel::Item(
        "pistol", "good old pistol",
        Characteristics(2, 0, 0, 0, 0) * characteristics_k,
        GameModel::ItemType::WEAPON_DISTANT);
  case StuffType::GUN:
    return GameModel::Item(
        "gun", "good old gun",
        Characteristics(3, -1, 0, 0, 0) * characteristics_k,
        GameModel::ItemType::WEAPON_DISTANT);
  case StuffType::RIFLE:
    return GameModel::Item(
        "rifle", "good old rifle",
        Characteristics(3, 0, 0, -1, 0) * characteristics_k,
        GameModel::ItemType::WEAPON_DISTANT);
  case StuffType::AUTOMATIC_RIFLE:
    return GameModel::Item(
        "automatic_rifle", "good old automatic_rifle",
        Characteristics(4, -1, 0, -1, 0) * characteristics_k,
        GameModel::ItemType::WEAPON_DISTANT);
  case StuffType::BOW:
    return GameModel::Item(
        "bow", "good old bow",
        Characteristics(1, 0, 0, 1, 0) * characteristics_k,
        GameModel::ItemType::WEAPON_DISTANT);
  case StuffType::CROSSBOW:
    return GameModel::Item(
        "crossbow", "good old crossbow",
        Characteristics(2, -1, 0, 1, 0) * characteristics_k,
        GameModel::ItemType::WEAPON_DISTANT);
  case StuffType::SLING:
    return GameModel::Item(
        "sling", "good old sling",
        Characteristics(2, 1, 0, -1, 0) * characteristics_k,
        GameModel::ItemType::WEAPON_DISTANT);
  case StuffType::DIRKS:
    return GameModel::Item(
        "dirks", "good old dirks",
        Characteristics(1, -1, 0, 2, 0) * characteristics_k,
        GameModel::ItemType::WEAPON_DISTANT);
  default:
    throw GameObjectException("wrong StuffType");
  }
}

static const std::vector<PotionType> potions_types = {
    PotionType::DAMAGE_POTION,    PotionType::DAMAGE_LONG_POTION,
    PotionType::ARMOR_POTION,     PotionType::ARMOR_LONG_POTION,
    PotionType::HEALTH_POTION,    PotionType::HEALTH_BIG_POTION,
    PotionType::DEXTERITY_POTION, PotionType::DEXTERITY_LONG_POTION};

static GameModel::Potion get_potion(PotionType potion_type,
                                                        int characteristics_k) {
  switch (potion_type) {
  case PotionType::DAMAGE_POTION:
    return GameModel::Potion(
        "damage_potion", "damage increase",
        Characteristics(2, 0, 0, 0, 0) * characteristics_k,
        DEFAULT_POTION_WORK_TIME);
  case PotionType::DAMAGE_LONG_POTION:
    return GameModel::Potion(
        "damage_long_potion", "damage increase (long)",
        Characteristics(1, 0, 0, 0, 0) * characteristics_k,
        DEFAULT_POTION_WORK_TIME * 2);
  case PotionType::ARMOR_POTION:
    return GameModel::Potion(
        "armor_potion", "armor increase",
        Characteristics(0, 2, 0, 0, 0) * characteristics_k,
        DEFAULT_POTION_WORK_TIME);
  case PotionType::ARMOR_LONG_POTION:
    return GameModel::Potion(
        "armor_long_potion", "armor increase (long)",
        Characteristics(0, 1, 0, 0, 0) * characteristics_k,
        DEFAULT_POTION_WORK_TIME * 2);
  case PotionType::HEALTH_POTION:
    return GameModel::Potion(
        "health_potion", "add 1 hp",
        Characteristics(0, 0, 1, 0, 0) * characteristics_k, 1);
  case PotionType::HEALTH_BIG_POTION:
    return GameModel::Potion(
        "health_potion_big", "add 2 hp",
        Characteristics(0, 0, 2, 0, 0) * characteristics_k, 1);
  case PotionType::DEXTERITY_POTION:
    return GameModel::Potion(
        "dexterity_potion", "dexterity increase",
        Characteristics(0, 0, 0, 2, 0) * characteristics_k,
        DEFAULT_POTION_WORK_TIME);
  case PotionType::DEXTERITY_LONG_POTION:
    return GameModel::Potion(
        "dexterity_long_potion", "dexterity increase (long)",
        Characteristics(0, 0, 0, 1, 0) * characteristics_k,
        DEFAULT_POTION_WORK_TIME * 2);
  default:
    throw GameObjectException("wrong PotionType");
  }
};

static GameModel::IEnemyClass
get_enemy_class(GameModel::Abstract::EnemyClass enemy_class,
                GameModel::EnemySettings settings) {
  switch (enemy_class) {
  case GameModel::Abstract::EnemyClass::AGRESSIVE:
    return GameModel::Agressive(
        "Hates everyone (if he sees at least someone (not necessarily a "
        "Character), he strives to reach him and kill)",
        settings);
  case GameModel::Abstract::EnemyClass::FLYING:
    return GameModel::Flying(
        "Looks down on everyone (can ignore all obstacles (walls))", settings);
  case GameModel::Abstract::EnemyClass::INDIFFERENT:
    return GameModel::Indifferent(
        "He doesn't care about anyone (ignores everyone if he doesn't start "
        "hitting first)",
        settings);
  case GameModel::Abstract::EnemyClass::ORDINARY:
    return GameModel::Ordinary(
        "Ordinary Enemy (without any special features. It has an increased one "
        "of the characteristics)",
        settings);
  case GameModel::Abstract::EnemyClass::TRAVELER:
    return GameModel::Traveler(
        "Can be anywhere he wants (it can be located anywhere on the Map)",
        settings);
  default:
    throw GameObjectException("wrong PersonClass");
  }
};

static std::vector<GameModel::Abstract::EnemyClass> enemy_classes = {
    GameModel::Abstract::EnemyClass::AGRESSIVE,
    GameModel::Abstract::EnemyClass::FLYING,
    GameModel::Abstract::EnemyClass::INDIFFERENT,
    GameModel::Abstract::EnemyClass::ORDINARY,
    GameModel::Abstract::EnemyClass::TRAVELER};

static GameModel::IPersonClass
get_person_class(GameModel::Abstract::PersonClass person_class,
                 GameModel::PersonSettings settings) {
  switch (person_class) {
  case GameModel::Abstract::PersonClass::ALCHEMIST:
    return GameModel::Alchemist(
        "A novice alchemist (can have up to 7 Potions)", settings);
  case GameModel::Abstract::PersonClass::FARSIGHTED:
    return GameModel::Farsighted(
        "Can see far away (the field of View is 2 times larger than the "
        "standard one)",
        settings);
  case GameModel::Abstract::PersonClass::LUCKY:
    return GameModel::Lucky(
        "Just lucky Person (has luck >= 0.9)", settings);
  case GameModel::Abstract::PersonClass::SECRETIVE:
    return GameModel::Secretive(
        "Unrealistically secretive one (the field of View of opponents is 2 "
        "times smaller for the Character)",
        settings);
  case GameModel::Abstract::PersonClass::WISE:
    return GameModel::Wise(
        "The wisest elder (can see the areas where opponents may be located)",
        settings);
  default:
    throw GameObjectException("wrong PersonClass");
  }
};

static std::vector<GameModel::Abstract::PersonClass> person_classes = {
    GameModel::Abstract::PersonClass::ALCHEMIST,
    GameModel::Abstract::PersonClass::FARSIGHTED,
    GameModel::Abstract::PersonClass::LUCKY,
    GameModel::Abstract::PersonClass::SECRETIVE,
    GameModel::Abstract::PersonClass::WISE};

static std::vector<std::string> firstnames = {
    "simpleton",     "man",        "philosopher", "peasant", "warrior",
    "mathematician", "programmer", "philologist", "doctor",  "master",
    "king",          "savage",     "marauder",    "child",   "human"};

static std::vector<std::string> lastnames = {
    "beautiful",   "great",    "impudent",  "smart", "crazy",
    "predictable", "happy",    "dexterous", "wise",  "combat",
    "persistent",  "business", "tortured",  "quick", "big"};

static std::random_device generator;
}; // namespace superrogue::values
