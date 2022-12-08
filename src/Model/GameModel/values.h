#pragma once
#include "Model/GameModel/GameObject/Character/Class/Enemy/Agressive.h"
#include "Model/GameModel/GameObject/Character/Class/Enemy/Flying.h"
#include "Model/GameModel/GameObject/Character/Class/Enemy/Indifferent.h"
#include "Model/GameModel/GameObject/Character/Class/Enemy/Ordinary.h"
#include "Model/GameModel/GameObject/Character/Class/Enemy/Coward.h"
#include "Model/GameModel/GameObject/Character/Class/Enemy/Traveler.h"
#include "Model/GameModel/GameObject/Character/Class/Person/Alchemist.h"
#include "Model/GameModel/GameObject/Character/Class/Person/Farsighted.h"
#include "Model/GameModel/GameObject/Character/Class/Person/Lucky.h"
#include "Model/GameModel/GameObject/Character/Class/Person/Secretive.h"
#include "Model/GameModel/GameObject/Character/Class/Person/Wise.h"
#include "Model/GameModel/GameObject/Item/Potions/Potion.h"
#include "Model/GameModel/GameObject/Item/Potions/PotionType.h"
#include "Model/GameModel/GameObject/Item/Stuff/Item.h"
#include "Model/GameModel/GameObject/Item/Stuff/StuffType.h"
#include "const.h"
#include <unordered_map>
#include <vector>
#include <memory>

/**
 * @brief a file containing all sorts of entities, types of things, etc.
 * 
 */

namespace GameModel::Values {
static const std::vector<StuffType> items_types = {
    StuffType::HELM, StuffType::CAP, StuffType::PANAMA,
    StuffType::HAT, StuffType::HAUBERK, StuffType::TUNIC,
    StuffType::JACKET, StuffType::T_SHIRT, StuffType::SNEAKERS,
    StuffType::SLIPPERS, StuffType::BOOTS, StuffType::SANDALS,
    StuffType::SWORD, StuffType::KATANA, StuffType::KNIFE,
    StuffType::SABER, StuffType::BITA, StuffType::MACE,
    StuffType::SPEAR, StuffType::NUNCHUCKS, StuffType::PISTOL,
    StuffType::GUN, StuffType::RIFLE, StuffType::AUTOMATIC_RIFLE,
    StuffType::BOW, StuffType::CROSSBOW, StuffType::SLING,
    StuffType::DIRKS};

static std::shared_ptr<GameModel::Item> get_item(StuffType stuff_type, int characteristics_k) {
  switch (stuff_type) {
  case StuffType::HELM:
    return std::make_shared<GameModel::Item>("helm", "good old hauberk",
                                             Characteristics(0, 3, 0, -1, 0) * characteristics_k,
                                             GameModel::ItemType::HELMET);
  case StuffType::CAP:
    return std::make_shared<GameModel::Item>("cap", "good old cap",
                                             Characteristics(0, 1, 0, 1, 0) * characteristics_k,
                                             GameModel::ItemType::HELMET);
  case StuffType::PANAMA:
    return std::make_shared<GameModel::Item>("panama", "good old panama",
                                             Characteristics(0, 0, 0, 2, 0) * characteristics_k,
                                             GameModel::ItemType::HELMET);
  case StuffType::HAT:
    return std::make_shared<GameModel::Item>("hat", "good old hat",
                                             Characteristics(0, 2, 0, 0, 0) * characteristics_k,
                                             GameModel::ItemType::HELMET);

  case StuffType::HAUBERK:
    return std::make_shared<GameModel::Item>("hauberk", "good old hauberk",
                                             Characteristics(0, 3, 0, -1, 0) * characteristics_k,
                                             GameModel::ItemType::ARMOR);
  case StuffType::TUNIC:
    return std::make_shared<GameModel::Item>("tunic", "good old tunic",
                                             Characteristics(0, 2, 0, 0, 0) * characteristics_k,
                                             GameModel::ItemType::ARMOR);
  case StuffType::JACKET:
    return std::make_shared<GameModel::Item>("jacket", "good old jacket",
                                             Characteristics(0, 1, 0, 1, 0) * characteristics_k,
                                             GameModel::ItemType::ARMOR);
  case StuffType::T_SHIRT:
    return std::make_shared<GameModel::Item>("t_shirt", "good old t_shirt",
                                             Characteristics(0, 0, 0, 2, 0) * characteristics_k,
                                             GameModel::ItemType::ARMOR);

  case StuffType::SNEAKERS:
    return std::make_shared<GameModel::Item>("sneakers", "good old sneakers",
                                             Characteristics(0, 0, 0, 2, 0) * characteristics_k,
                                             GameModel::ItemType::BOOTS);
  case StuffType::SLIPPERS:
    return std::make_shared<GameModel::Item>("slippers", "good old slippers",
                                             Characteristics(1, 2, 0, -1, 0) * characteristics_k,
                                             GameModel::ItemType::BOOTS);
  case StuffType::BOOTS:
    return std::make_shared<GameModel::Item>("boots", "good old boots",
                                             Characteristics(0, 2, 0, 0, 0) * characteristics_k,
                                             GameModel::ItemType::BOOTS);
  case StuffType::SANDALS:
    return std::make_shared<GameModel::Item>("sandals", "good old sandals",
                                             Characteristics(0, 1, 0, 1, 0) * characteristics_k,
                                             GameModel::ItemType::BOOTS);

  case StuffType::SWORD:
    return std::make_shared<GameModel::Item>("sword", "good old sword",
                                             Characteristics(4, -1, 0, -1, 0) * characteristics_k,
                                             GameModel::ItemType::WEAPON_MELEE);
  case StuffType::KATANA:
    return std::make_shared<GameModel::Item>("katana", "good old katana",
                                             Characteristics(2, 0, 0, 0, 0) * characteristics_k,
                                             GameModel::ItemType::WEAPON_MELEE);
  case StuffType::KNIFE:
    return std::make_shared<GameModel::Item>("knife", "good old knife",
                                             Characteristics(2, -1, 0, 1, 0) * characteristics_k,
                                             GameModel::ItemType::WEAPON_MELEE);
  case StuffType::SABER:
    return std::make_shared<GameModel::Item>("saber", "good old saber",
                                             Characteristics(3, -1, 0, 0, 0) * characteristics_k,
                                             GameModel::ItemType::WEAPON_MELEE);
  case StuffType::BITA:
    return std::make_shared<GameModel::Item>("bita", "good old bita",
                                             Characteristics(1, 0, 0, 1, 0) * characteristics_k,
                                             GameModel::ItemType::WEAPON_MELEE);
  case StuffType::MACE:
    return std::make_shared<GameModel::Item>("mace", "good old mace",
                                             Characteristics(3, 0, 0, -1, 0) * characteristics_k,
                                             GameModel::ItemType::WEAPON_MELEE);
  case StuffType::SPEAR:
    return std::make_shared<GameModel::Item>("spear", "good old spear",
                                             Characteristics(3, 0, 0, -1, 0) * characteristics_k,
                                             GameModel::ItemType::WEAPON_MELEE);
  case StuffType::NUNCHUCKS:
    return std::make_shared<GameModel::Item>("nunchucks", "good old nunchucks",
                                             Characteristics(2, -2, 0, 2, 0) * characteristics_k,
                                             GameModel::ItemType::WEAPON_MELEE);

  case StuffType::PISTOL:
    return std::make_shared<GameModel::Item>("pistol", "good old pistol",
                                             Characteristics(2, 0, 0, 0, 0) * characteristics_k,
                                             GameModel::ItemType::WEAPON_DISTANT);
  case StuffType::GUN:
    return std::make_shared<GameModel::Item>("gun", "good old gun",
                                             Characteristics(3, -1, 0, 0, 0) * characteristics_k,
                                             GameModel::ItemType::WEAPON_DISTANT);
  case StuffType::RIFLE:
    return std::make_shared<GameModel::Item>("rifle", "good old rifle",
                                             Characteristics(3, 0, 0, -1, 0) * characteristics_k,
                                             GameModel::ItemType::WEAPON_DISTANT);
  case StuffType::AUTOMATIC_RIFLE:
    return std::make_shared<GameModel::Item>("automatic_rifle", "good old automatic_rifle",
                                             Characteristics(4, -1, 0, -1, 0) * characteristics_k,
                                             GameModel::ItemType::WEAPON_DISTANT);
  case StuffType::BOW:
    return std::make_shared<GameModel::Item>("bow", "good old bow",
                                             Characteristics(1, 0, 0, 1, 0) * characteristics_k,
                                             GameModel::ItemType::WEAPON_DISTANT);
  case StuffType::CROSSBOW:
    return std::make_shared<GameModel::Item>("crossbow", "good old crossbow",
                                             Characteristics(2, -1, 0, 1, 0) * characteristics_k,
                                             GameModel::ItemType::WEAPON_DISTANT);
  case StuffType::SLING:
    return std::make_shared<GameModel::Item>("sling", "good old sling",
                                             Characteristics(2, 1, 0, -1, 0) * characteristics_k,
                                             GameModel::ItemType::WEAPON_DISTANT);
  case StuffType::DIRKS:
    return std::make_shared<GameModel::Item>("dirks", "good old dirks",
                                             Characteristics(1, -1, 0, 2, 0) * characteristics_k,
                                             GameModel::ItemType::WEAPON_DISTANT);
  default:throw GameObjectException("wrong StuffType");
  }
}

static const std::vector<PotionType> potions_types = {
    PotionType::DAMAGE_POTION, PotionType::DAMAGE_LONG_POTION,
    PotionType::ARMOR_POTION, PotionType::ARMOR_LONG_POTION,
    PotionType::HEALTH_POTION, PotionType::HEALTH_BIG_POTION,
    PotionType::DEXTERITY_POTION, PotionType::DEXTERITY_LONG_POTION};

static std::shared_ptr<GameModel::Potion> get_potion(PotionType potion_type,
                                                     int characteristics_k) {
  switch (potion_type) {
  case PotionType::DAMAGE_POTION:
    return std::make_shared<GameModel::Potion>("damage_potion", "damage increase",
                                               Characteristics(2, 0, 0, 0, 0) * characteristics_k,
                                               DEFAULT_POTION_WORK_TIME);
  case PotionType::DAMAGE_LONG_POTION:
    return std::make_shared<GameModel::Potion>("damage_long_potion", "damage increase (long)",
                                               Characteristics(1, 0, 0, 0, 0) * characteristics_k,
                                               DEFAULT_POTION_WORK_TIME * 2);
  case PotionType::ARMOR_POTION:
    return std::make_shared<GameModel::Potion>("armor_potion", "armor increase",
                                               Characteristics(0, 2, 0, 0, 0) * characteristics_k,
                                               DEFAULT_POTION_WORK_TIME);
  case PotionType::ARMOR_LONG_POTION:
    return std::make_shared<GameModel::Potion>("armor_long_potion", "armor increase (long)",
                                               Characteristics(0, 1, 0, 0, 0) * characteristics_k,
                                               DEFAULT_POTION_WORK_TIME * 2);
  case PotionType::HEALTH_POTION:
    return std::make_shared<GameModel::Potion>("health_potion", "add 1 hp",
                                               Characteristics(0, 0, 1, 0, 0) * characteristics_k,
                                               1);
  case PotionType::HEALTH_BIG_POTION:
    return std::make_shared<GameModel::Potion>("health_potion_big", "add 2 hp",
                                               Characteristics(0, 0, 2, 0, 0) * characteristics_k,
                                               1);
  case PotionType::DEXTERITY_POTION:
    return std::make_shared<GameModel::Potion>("dexterity_potion", "dexterity increase",
                                               Characteristics(0, 0, 0, 2, 0) * characteristics_k,
                                               DEFAULT_POTION_WORK_TIME);
  case PotionType::DEXTERITY_LONG_POTION:
    return std::make_shared<GameModel::Potion>("dexterity_long_potion",
                                               "dexterity increase (long)",
                                               Characteristics(0, 0, 0, 1, 0) * characteristics_k,
                                               DEFAULT_POTION_WORK_TIME * 2);
  default:throw GameObjectException("wrong PotionType");
  }
};

static std::shared_ptr<GameModel::Enemy>
get_enemy(GameModel::Abstract::EnemyClass enemy_class, int id, std::string name, Characteristics characteristics,
          GameModel::EnemySettings settings) {
  switch (enemy_class) {
  case GameModel::Abstract::EnemyClass::AGRESSIVE:
    return std::make_shared<GameModel::Agressive>(name,
                                                  characteristics, id, settings);
  case GameModel::Abstract::EnemyClass::COWARD:
    return std::make_shared<GameModel::Coward>(name,
                                               characteristics,
                                               id,
                                               settings);
  case GameModel::Abstract::EnemyClass::FLYING:
    return std::make_shared<GameModel::Flying>(name,
                                               characteristics, id, settings);
  case GameModel::Abstract::EnemyClass::INDIFFERENT:
    return std::make_shared<GameModel::Indifferent>(name,
                                                    characteristics, id, settings);
  case GameModel::Abstract::EnemyClass::ORDINARY:
    return std::make_shared<GameModel::Ordinary>(name,
                                                 characteristics,
                                                 id,
                                                 settings);
  case GameModel::Abstract::EnemyClass::TRAVELER:
    return std::make_shared<GameModel::Traveler>(name,
                                                 characteristics, id, settings);
  default:throw GameObjectException("wrong PersonClass");
  }
};

static std::vector<GameModel::Abstract::EnemyClass> enemy_classes = {
    GameModel::Abstract::EnemyClass::AGRESSIVE,
    GameModel::Abstract::EnemyClass::COWARD,
    GameModel::Abstract::EnemyClass::FLYING,
    GameModel::Abstract::EnemyClass::INDIFFERENT,
    GameModel::Abstract::EnemyClass::ORDINARY,
    GameModel::Abstract::EnemyClass::TRAVELER};

static std::shared_ptr<GameModel::Person>
get_person(GameModel::Abstract::PersonClass person_class,
           std::string name) {
  switch (person_class) {
  case GameModel::Abstract::PersonClass::ALCHEMIST:return std::make_shared<GameModel::Alchemist>(name);
  case GameModel::Abstract::PersonClass::FARSIGHTED:return std::make_shared<GameModel::Farsighted>(name);
  case GameModel::Abstract::PersonClass::LUCKY:return std::make_shared<GameModel::Lucky>(name);
  case GameModel::Abstract::PersonClass::SECRETIVE:return std::make_shared<GameModel::Secretive>(name);
  case GameModel::Abstract::PersonClass::WISE:return std::make_shared<GameModel::Wise>(name);
  default:throw GameObjectException("wrong PersonClass");
  }
};

static std::vector<GameModel::Abstract::PersonClass> person_classes = {
    GameModel::Abstract::PersonClass::ALCHEMIST,
    GameModel::Abstract::PersonClass::FARSIGHTED,
    GameModel::Abstract::PersonClass::LUCKY,
    GameModel::Abstract::PersonClass::SECRETIVE,
    GameModel::Abstract::PersonClass::WISE};

static std::vector<std::string> firstnames = {
    "simpleton", "man", "philosopher", "peasant", "warrior",
    "mathematician", "programmer", "philologist", "doctor", "master",
    "king", "savage", "marauder", "child", "human"};

static std::vector<std::string> lastnames = {
    "beautiful", "great", "impudent", "smart", "crazy",
    "predictable", "happy", "dexterous", "wise", "combat",
    "persistent", "business", "tortured", "quick", "big"};

static std::unordered_set<GameModel::Abstract::MapEntity> view_blockers = {
    Abstract::MapEntity::PERSON,
    Abstract::MapEntity::ENEMY,
    Abstract::MapEntity::ENEMY_COWARD,
    Abstract::MapEntity::ENEMY_AGRESSIVE,
    Abstract::MapEntity::ENEMY_FLYING,
    Abstract::MapEntity::ENEMY_INDIFFERENT,
    Abstract::MapEntity::ENEMY_ORDINARY,
    Abstract::MapEntity::ENEMY_TRAVELER,
    Abstract::MapEntity::WALL
};

static std::random_device generator;
}; // namespace GameModel::Values
