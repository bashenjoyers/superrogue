#include "model/GameManager.h"
#include "exceptions/exceptions.h"
#include "model/generator.h"
#include "model/values.h"
#include <memory>

using std::max;
using std::set;
using std::string;
using std::vector;
using superrogue::abstract::EnemyClass;
using superrogue::abstract::PersonClass;
using superrogue::controller::event::IEvent;
using superrogue::exception::GameObjectException;
using superrogue::game_object::character::Enemy;
using superrogue::game_object::character::EnemySettings;
using superrogue::game_object::character::IEnemyClass;
using superrogue::game_object::character::IPersonClass;
using superrogue::game_object::character::Lucky;
using superrogue::game_object::character::Ordinary;
using superrogue::game_object::character::Person;
using superrogue::game_object::character::PersonSettings;
using superrogue::inventory::Inventory;
using superrogue::map::Map;
using superrogue::map::MapOptions;
using superrogue::values::enemy_classes;
using superrogue::values::firstnames;
using superrogue::values::get_enemy_class;
using superrogue::values::get_person_class;
using superrogue::values::lastnames;
using superrogue::values::person_classes;

namespace superrogue::game_manager {
GameManager::GameManager(MapOptions map_options) : map_options(map_options) {
  person = generate_person();
}

vector<IEvent> GameManager::events() noexcept { return {}; } // TODO(controller)

GameOptions GameManager::generate_game_options() noexcept {
  GameOptions options = GameOptions();
  options.enemies_count =
      generator::enemies_count_gen(superrogue::values::generator);
  return options;
}

Characteristics GameManager::generate_characteristics(
    float characteristic_k = 1) const noexcept {
  int points = int(level * POINTS_IN_LVL * characteristic_k);
  int health_default = int(level * HEALTH_LVL_K * characteristic_k);
  int damage =
      int(generator::characteristic_gen(superrogue::values::generator) /
          PARAMETER_COUNT * points);
  int armor = int(generator::characteristic_gen(superrogue::values::generator) /
                  PARAMETER_COUNT * points);
  int health =
      int(generator::characteristic_gen(superrogue::values::generator) /
          PARAMETER_COUNT * points);
  int dexterity =
      int(generator::characteristic_gen(superrogue::values::generator) /
          PARAMETER_COUNT * points);
  int luck = generator::luck_gen(superrogue::values::generator);
  return Characteristics(damage, armor, health_default + health, dexterity,
                         luck);
}

Person GameManager::generate_person() noexcept {
  string firstname =
      firstnames[generator::firstname_i_gen(superrogue::values::generator)];
  string lastname =
      lastnames[generator::lastname_i_gen(superrogue::values::generator)];
  PersonClass person_classes_name =
      person_classes[generator::person_class_i_gen(
          superrogue::values::generator)];
  PersonSettings settings = PersonSettings();
  if (person_classes_name == PersonClass::FARSIGHTED) {
    settings.visible_radius = settings.visible_radius * 2;
  }
  Characteristics characteristics = generate_characteristics();
  if (person_classes_name == PersonClass::LUCKY) {
    characteristics.luck = max(characteristics.luck, LUCKY_LUCK);
  }
  int potions_max = (person_classes_name == PersonClass::ALCHEMIST)
                        ? POTIONS_MAX_ALCHEMIST
                        : DEFAULT_POTIONS_MAX;
  Inventory inventory = Inventory(potions_max);
  IPersonClass person_class = get_person_class(person_classes_name, settings);
  return Person(lastname + " " + firstname, characteristics, person_class,
                inventory);
}

set<Enemy> GameManager::generate_enemies(GameOptions game_options) {
  set<Enemy> enemies = {};
  for (int i = 0; i < game_options.enemies_count; i++) {
    string firstname =
        firstnames[generator::firstname_i_gen(superrogue::values::generator)];
    string lastname =
        lastnames[generator::lastname_i_gen(superrogue::values::generator)];
    Characteristics characteristics = generate_characteristics(WEAKNESS_K);
    EnemySettings settings = EnemySettings();
    settings.attack_range =
        generator::melee_gen(superrogue::values::generator) ? 1 : DISTANT_RANGE;
    settings.intellect =
        generator::intellect_gen(superrogue::values::generator);
    EnemyClass enemy_class_name = enemy_classes[generator::enemy_class_i_gen(
        superrogue::values::generator)];
    IEnemyClass enemy_class = get_enemy_class(enemy_class_name, settings);
    if (enemy_class_name == EnemyClass::ORDINARY) {
      switch (generator::characteristic_i_gen(superrogue::values::generator)) {
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
    }
    Enemy enemy =
        Enemy(i, lastname + " " + firstname, characteristics, enemy_class);
    enemies.insert(enemy);
  }
  return enemies;
}

void GameManager::person_level_up(Characteristics characteristics) {
  person.level_up(characteristics);
}

std::shared_ptr<Map*> GameManager::generate_map() noexcept {
  level++;
  GameOptions game_options = generate_game_options();
  set<Enemy> enemies = generate_enemies(game_options);
  if (map == nullptr) {
    map = new Map(enemies, person, map_options, level);
  } else {
    *map = Map(enemies, person, map_options, level);
  }
  return std::make_shared<Map*>(map);
}

GameManager::~GameManager() {
  delete map;
}
}; // namespace superrogue::game_manager
