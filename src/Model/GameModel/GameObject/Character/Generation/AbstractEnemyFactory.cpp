#include "AbstractEnemyFactory.h"
#include "Model/GameModel/const.h"
#include "Model/GameModel/generator.h"
#include "Model/GameModel/values.h"

GameModel::Characteristics GameModel::Generation::AbstractEnemyFactory::generateCharacteristics() {
    int points = int(level * POINTS_IN_LVL * WEAKNESS_K);
    int health_default = int(level * HEALTH_LVL_K * WEAKNESS_K);
    int damage = int(GameModel::Generation::characteristic_gen(Values::generator) / PARAMETER_COUNT * points) + 1;
    int armor = int(GameModel::Generation::characteristic_gen(Values::generator) / PARAMETER_COUNT * points) + 1;
    int health = int(GameModel::Generation::characteristic_gen(Values::generator) / PARAMETER_COUNT * points);
    int dexterity = int(GameModel::Generation::characteristic_gen(Values::generator) / PARAMETER_COUNT * points);
    float luck = GameModel::Generation::luck_gen(Values::generator);
    return Characteristics(damage, armor, health_default + health, dexterity, luck);
}

GameModel::EnemySettings GameModel::Generation::AbstractEnemyFactory::generateSettings() {
    EnemySettings settings = EnemySettings();
    settings.attack_range = GameModel::Generation::melee_gen(Values::generator) ? 1 : DISTANT_RANGE;
    settings.intellect = GameModel::Generation::intellect_gen(Values::generator);
    return settings;
}
