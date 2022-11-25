#include "GameManager.h"
#include "Model/Exceptions/exceptions.h"
#include "Model/GameModel/GameObject/Character/Enemy.h"
#include "Model/GameModel/GameObject/Character/IConfusionEnemy.h"
#include "Model/GameModel/GameObject/Character/Person.h"
#include "Model/GameModel/Inventory/Inventory.h"
#include "abstract.h"
#include "generator.h"
#include "values.h"
#include <memory>

using std::max;
using std::set;
using std::string;
using std::vector;


namespace GameModel {

using namespace Values;
using namespace Abstract;

GameManager::GameManager(Map::MapOptions map_options)
    : map_options(map_options) {
  person = generate_person();
}

GameOptions GameManager::generate_game_options() noexcept {
  GameOptions options = GameOptions();
  options.enemies_count =
      GameModel::Generation::enemies_count_gen(Values::generator);
  return options;
}

Characteristics GameManager::generate_characteristics(
    float characteristic_k = 1) const noexcept {
  int points = int(level * POINTS_IN_LVL * characteristic_k);
  int health_default = int(level * HEALTH_LVL_K * characteristic_k);
  int damage =
      int(GameModel::Generation::characteristic_gen(Values::generator) /
          PARAMETER_COUNT * points) + 1;
  int armor = int(GameModel::Generation::characteristic_gen(Values::generator) /
                  PARAMETER_COUNT * points) + 1;
  int health =
      int(GameModel::Generation::characteristic_gen(Values::generator) /
          PARAMETER_COUNT * points);
  int dexterity =
      int(GameModel::Generation::characteristic_gen(Values::generator) /
          PARAMETER_COUNT * points);
  float luck = GameModel::Generation::luck_gen(Values::generator);
  return Characteristics(damage, armor, health_default + health, dexterity,
                         luck);
}

std::shared_ptr<Person> GameManager::generate_person() noexcept {
  string firstname =
      firstnames[GameModel::Generation::firstname_i_gen(Values::generator)];
  string lastname =
      lastnames[GameModel::Generation::lastname_i_gen(Values::generator)];
  PersonClass person_classes_name =
      person_classes[GameModel::Generation::person_class_i_gen(
          Values::generator)];
  PersonSettings settings = PersonSettings();
  if (person_classes_name == PersonClass::FARSIGHTED) {
    settings.visible_radius = settings.visible_radius * 2;
  }
  Characteristics characteristics = generate_characteristics();
  level--; // internal need;
  if (person_classes_name == PersonClass::LUCKY) {
    characteristics.luck = max(characteristics.luck, LUCKY_LUCK);
  }
  int potions_max = (person_classes_name == PersonClass::ALCHEMIST)
                        ? POTIONS_MAX_ALCHEMIST
                        : DEFAULT_POTIONS_MAX;
  Inventory::Inventory inventory = Inventory::Inventory(potions_max);
  std::shared_ptr<IPersonClass> person_class = get_person_class(person_classes_name, settings);
  return std::make_shared<Person>(lastname + " " + firstname, characteristics, person_class,
                inventory);
}

set<std::shared_ptr<IEnemy>> GameManager::generate_enemies(GameOptions game_options) {
  set<std::shared_ptr<IEnemy>> enemies = {};
  for (int i = 0; i < game_options.enemies_count; i++) {
    string firstname =
        firstnames[GameModel::Generation::firstname_i_gen(Values::generator)];
    string lastname =
        lastnames[GameModel::Generation::lastname_i_gen(Values::generator)];
    Characteristics characteristics = generate_characteristics(WEAKNESS_K);
    EnemySettings settings = EnemySettings();
    settings.attack_range =
        GameModel::Generation::melee_gen(Values::generator) ? 1 : DISTANT_RANGE;
    settings.intellect =
        GameModel::Generation::intellect_gen(Values::generator);
    EnemyClass enemy_class_name = enemy_classes[GameModel::Generation::enemy_class_i_gen(Values::generator)];
    std::shared_ptr<IEnemyClass> enemy_class = get_enemy_class(enemy_class_name, settings);
    if (enemy_class_name == EnemyClass::ORDINARY) {
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
    } else if (enemy_class_name == EnemyClass::COWARD) {
      characteristics.dexterity *= 3;
    }
    auto enemy = std::make_shared<Enemy>(i, lastname + " " + firstname, characteristics, enemy_class);
    auto confused_enemy = std::make_shared<IConfusionEnemy>(enemy);
    enemies.insert(confused_enemy);
  }
  return enemies;
}

void GameManager::person_level_up(Characteristics characteristics) {
  person->level_up(characteristics);
}

std::shared_ptr<Map::Map> GameManager::generate_map() noexcept {
  level++;
  if (level != 1) {
    person_level_up(Characteristics(2, 2, 0, 1)); // user can choose it later
  }
  GameOptions game_options = generate_game_options();
  set<std::shared_ptr<IEnemy>> enemies = generate_enemies(game_options);
  if (map_ref == nullptr) {
    map_ref = std::make_shared<Map::Map>(enemies, person, map_options, level);
  } else {
    *map_ref = Map::Map(enemies, person, map_options, level);
  }
  return map_ref;
}
}; // namespace GameModel
