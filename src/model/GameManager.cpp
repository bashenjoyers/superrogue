#include "model/GameManager.h"
#include "exceptions/exceptions.h"

using std::string;
using std::vector;
using std::set;
using std::max;
using superrogue::game_object::character::Person;
using superrogue::game_object::character::Enemy;
using superrogue::game_object::character::IEnemyClass;
using superrogue::game_object::character::IPersonClass;
using superrogue::game_object::character::Lucky;
using superrogue::game_object::character::Ordinary;
using superrogue::controller::event::IEvent;
using superrogue::map::Map;
using superrogue::map::MapOptions;
using superrogue::values::enemy_classes;
using superrogue::values::person_classes;
using superrogue::values::get_enemy_class;
using superrogue::values::get_person_class;
using superrogue::values::firstnames;
using superrogue::values::lastnames;
using superrogue::exception::GameObjectException;
using superrogue::game_object::character::EnemySettings;
using superrogue::game_object::character::PersonSettings;


namespace superrogue::game_manager {
GameManager::GameManager(MapOptions map_options) : __map_options(map_options) {
    person = generate_person();
}

vector<IEvent> GameManager::events() noexcept {
    return {};
} // TODO(controller)


GameOptions GameManager::generate_game_options() noexcept {
    GameOptions options = GameOptions();
    options.enemies_count = __generator.enemies_count_gen();
    return options;
}

Characteristics GameManager::generate_characteristics(float characteristic_k = 1) noexcept {
    int points = int(__level * POINTS_IN_LVL * characteristic_k);
    int health_default = int(__level * HEALTH_LVL_K * characteristic_k);
    int damage = int(__generator.characteristic_gen() / PARAMETER_COUNT * points);
    int armor = int(__generator.characteristic_gen() / PARAMETER_COUNT * points);
    int health = int(__generator.characteristic_gen() / PARAMETER_COUNT * points);
    int dexterity = int(__generator.characteristic_gen() / PARAMETER_COUNT * points);
    int luck = __generator.luck_gen();
    return Characteristics(damage, armor, health_default + health, dexterity, luck);
}

Person GameManager::generate_person() noexcept {
    string firstname = firstnames[__generator.firstname_i_gen()];
    string lastname = lastnames[__generator.lastname_i_gen()];
    Characteristics characteristics = generate_characteristics();
    PersonSettings settings = PersonSettings();
    IPersonClass person_class = get_person_class(person_classes[__generator.person_class_i_gen()], settings);
    if (typeid(person_class) == typeid(Lucky)) {
        characteristics.luck = max(characteristics.luck, LUCKY_LUCK);
    }
    return Person(lastname + " " + firstname, characteristics, person_class);
}

set<Enemy> GameManager::generate_enemies(GameOptions game_options) {
    set<Enemy> enemies = {};
    for (int i = 0; i < game_options.enemies_count; i++) {
        string firstname = firstnames[__generator.firstname_i_gen()];
        string lastname = lastnames[__generator.lastname_i_gen()];
        Characteristics characteristics = generate_characteristics(WEAKNESS_K);
        EnemySettings settings = EnemySettings();
        settings.attack_range = __generator.melee_gen() ? 1 : 3;
        settings.intellect = __generator.intellect_gen();
        IEnemyClass enemy_class = get_enemy_class(enemy_classes[__generator.enemy_class_i_gen()], settings);
        if (typeid(enemy_class) == typeid(Ordinary)) {
            switch (__generator.characteristic_i_gen())
            {
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
                break;
            }
        }
        Enemy enemy = Enemy(i, lastname + " " + firstname, characteristics, enemy_class);
        enemies.insert(enemy);
    }
    return enemies;
}

Map GameManager::generate_map() noexcept {  // TODO(add user level up)
    __level++;
    GameOptions game_options = generate_game_options();
    set<Enemy> enemies = generate_enemies(game_options);
    return Map(enemies, person, __map_options);
}
};
