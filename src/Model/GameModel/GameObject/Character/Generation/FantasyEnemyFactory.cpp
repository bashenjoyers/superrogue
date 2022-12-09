#include "FantasyEnemyFactory.h"
#include "Model/GameModel/GameObject/Character/Class/Enemy/Agressive.h"
#include "Model/GameModel/values.h"
#include "Model/GameModel/GameObject/Character/IConfusionEnemy.h"
#include "Model/GameModel/GameObject/Character/Enemy.h"
#include "Model/GameModel/generation_utils.h"
#include <string>

std::shared_ptr<GameModel::Enemy> GameModel::Generation::FantasyEnemyFactory::generateAgressive(int guid) {
    std::string firstname = "Angry";
    std::string lastname = "Ogre";

    Characteristics characteristics = generateCharacteristics();
    EnemySettings settings = generateSettings();

    auto enemy = Values::get_enemy(Abstract::EnemyClass::AGRESSIVE, guid, firstname + " " + lastname, characteristics, settings);
    return std::make_shared<IConfusionEnemy>(enemy);
}

std::shared_ptr<GameModel::Enemy> GameModel::Generation::FantasyEnemyFactory::generateCoward(int guid) {
    std::string firstname = "Cowardly";
    std::string lastname = "Rat";

    Characteristics characteristics = generateCharacteristics();
    characteristics.dexterity *= 3;

    EnemySettings settings = generateSettings();

    auto enemy = Values::get_enemy(Abstract::EnemyClass::COWARD, guid, firstname + " " + lastname, characteristics, settings);
    return std::make_shared<IConfusionEnemy>(enemy);
}

std::shared_ptr<GameModel::Enemy> GameModel::Generation::FantasyEnemyFactory::generateFlying(int guid) {
    std::string firstname = "Mighty";
    std::string lastname = "Gargoyle";

    Characteristics characteristics = generateCharacteristics();
    EnemySettings settings = generateSettings();

    auto enemy = Values::get_enemy(Abstract::EnemyClass::FLYING, guid, firstname + " " + lastname, characteristics, settings);
    return std::make_shared<IConfusionEnemy>(enemy);
}

std::shared_ptr<GameModel::Enemy> GameModel::Generation::FantasyEnemyFactory::generateIndifferent(int guid) {
    std::string firstname = "Lost";
    std::string lastname = "Ghost";

    Characteristics characteristics = generateCharacteristics();
    EnemySettings settings = generateSettings();

  auto enemy = Values::get_enemy(Abstract::EnemyClass::INDIFFERENT, guid, firstname + " " + lastname, characteristics, settings);
    return std::make_shared<IConfusionEnemy>(enemy);
}

std::shared_ptr<GameModel::Enemy> GameModel::Generation::FantasyEnemyFactory::generateOrdinary(int guid) {
    std::string firstname = "Skeleton";
    std::string lastname = "";

    Characteristics characteristics = generateCharacteristics();
    EnemySettings settings = generateSettings();

    switch (GameModel::Generation::characteristic_i_gen(Values::generator)) {
        case 0:
            characteristics.armor *= 2;
            break;
        case 1:
            characteristics.damage *= 2;
            break;
        case 2:
            characteristics.dexterity *= 2;
            break;
        case 3:
            characteristics.health *= 2;
            break;
        default:
            throw GameObjectException("wrong characteristic_i_gen");
    }

    auto enemy = Values::get_enemy(Abstract::EnemyClass::ORDINARY, guid, firstname + " " + lastname, characteristics, settings);
    return std::make_shared<IConfusionEnemy>(enemy);
}

std::shared_ptr<GameModel::Enemy> GameModel::Generation::FantasyEnemyFactory::generateTraveler(int guid) {
    std::string firstname = "Ghoul";
    std::string lastname = "";

    Characteristics characteristics = generateCharacteristics();
    EnemySettings settings = generateSettings();

    auto enemy = Values::get_enemy(Abstract::EnemyClass::TRAVELER, guid, firstname + " " + lastname, characteristics, settings);
    return std::make_shared<IConfusionEnemy>(enemy);
}

std::shared_ptr<GameModel::Enemy> GameModel::Generation::FantasyEnemyFactory::generateReplicator(int guid) {
  std::string firstname = "Slug";
  std::string lastname = "";

  Characteristics characteristics = generateCharacteristics();
  EnemySettings settings = generateSettings();

  auto enemy = Values::get_enemy(Abstract::EnemyClass::REPLICATOR, guid, firstname + " " + lastname, characteristics, settings);
  return std::make_shared<IConfusionEnemy>(enemy);
}
