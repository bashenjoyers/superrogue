#include "FantasyEnemyFactory.h"
#include "Model/GameModel/GameObject/Character/Class/Enemy/Agressive.h"
#include "Model/GameModel/values.h"
#include "Model/GameModel/GameObject/Character/IConfusionEnemy.h"
#include "Model/GameModel/GameObject/Character/Enemy.h"
#include "Model/GameModel/generation_utils.h"
#include <string>

std::shared_ptr<GameModel::IEnemy> GameModel::Generation::FantasyEnemyFactory::generateAgressive(int guid, const Abstract::Position& pos) {
    std::string firstname = "Angry";
    std::string lastname = "Ogre";

    Characteristics characteristics = generateCharacteristics();
    EnemySettings settings = generateSettings(Abstract::EnemyClass::AGRESSIVE, pos);
    std::shared_ptr<IEnemyClass> enemyClass = Values::get_enemy_class(Abstract::EnemyClass::AGRESSIVE, settings);

    auto enemy = std::make_shared<Enemy>(guid, lastname + " " + firstname, characteristics, enemyClass);
    return std::make_shared<IConfusionEnemy>(enemy);
}

std::shared_ptr<GameModel::IEnemy> GameModel::Generation::FantasyEnemyFactory::generateCoward(int guid, const Abstract::Position& pos) {
    std::string firstname = "Cowardly";
    std::string lastname = "Rat";

    Characteristics characteristics = generateCharacteristics();
    characteristics.dexterity *= 3;

    EnemySettings settings = generateSettings(Abstract::EnemyClass::COWARD, pos);
    std::shared_ptr<IEnemyClass> enemyClass = Values::get_enemy_class(Abstract::EnemyClass::COWARD, settings);

    auto enemy = std::make_shared<Enemy>(guid, lastname + " " + firstname, characteristics, enemyClass);
    return std::make_shared<IConfusionEnemy>(enemy);
}

std::shared_ptr<GameModel::IEnemy> GameModel::Generation::FantasyEnemyFactory::generateFlying(int guid, const Abstract::Position& pos) {
    std::string firstname = "Mighty";
    std::string lastname = "Gargoyle";

    Characteristics characteristics = generateCharacteristics();
    EnemySettings settings = generateSettings(Abstract::EnemyClass::FLYING, pos);
    std::shared_ptr<IEnemyClass> enemyClass = Values::get_enemy_class(Abstract::EnemyClass::FLYING, settings);

    auto enemy = std::make_shared<Enemy>(guid, lastname + " " + firstname, characteristics, enemyClass);
    return std::make_shared<IConfusionEnemy>(enemy);
}

std::shared_ptr<GameModel::IEnemy> GameModel::Generation::FantasyEnemyFactory::generateIndifferent(int guid, const Abstract::Position& pos) {
    std::string firstname = "Lost";
    std::string lastname = "Ghost";

    Characteristics characteristics = generateCharacteristics();
    EnemySettings settings = generateSettings(Abstract::EnemyClass::INDIFFERENT, pos);
    std::shared_ptr<IEnemyClass> enemyClass = Values::get_enemy_class(Abstract::EnemyClass::INDIFFERENT, settings);

    auto enemy = std::make_shared<Enemy>(guid, lastname + " " + firstname, characteristics, enemyClass);
    return std::make_shared<IConfusionEnemy>(enemy);
}

std::shared_ptr<GameModel::IEnemy> GameModel::Generation::FantasyEnemyFactory::generateOrdinary(int guid, const Abstract::Position& pos) {
    std::string firstname = "Skeleton";
    std::string lastname = "";

    Characteristics characteristics = generateCharacteristics();
    EnemySettings settings = generateSettings(Abstract::EnemyClass::ORDINARY, pos);
    std::shared_ptr<IEnemyClass> enemyClass = Values::get_enemy_class(Abstract::EnemyClass::ORDINARY, settings);

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

    auto enemy = std::make_shared<Enemy>(guid, lastname + " " + firstname, characteristics, enemyClass);
    return std::make_shared<IConfusionEnemy>(enemy);
}

std::shared_ptr<GameModel::IEnemy> GameModel::Generation::FantasyEnemyFactory::generateTraveler(int guid, const Abstract::Position& pos) {
    std::string firstname = "Ghoul";
    std::string lastname = "";

    Characteristics characteristics = generateCharacteristics();
    EnemySettings settings = generateSettings(Abstract::EnemyClass::TRAVELER, pos);
    std::shared_ptr<IEnemyClass> enemyClass = Values::get_enemy_class(Abstract::EnemyClass::TRAVELER, settings);

    auto enemy = std::make_shared<Enemy>(guid, lastname + " " + firstname, characteristics, enemyClass);
    return std::make_shared<IConfusionEnemy>(enemy);
}
