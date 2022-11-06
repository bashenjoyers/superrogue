#include "model/GameManager.h"


namespace superrogue::game_manager {
GameManager::GameManager(MapOptions map_options) : __map_options(map_options) {}

vector<IEvent> GameManager::events() noexcept {
    return {};
} // TODO


GameOptions GameManager::generate_game_options() noexcept {
    GameOptions options = GameOptions();
    options.enemies_count = __generator.enemies_count_gen();
    return options;
}

Characteristics GameManager::generate_characteristics(float characteristic_k = 1) noexcept {
    int points = int(__level * POINTS_IN_LVL * characteristic_k);
    int health_default = int(__level * HEALTH_LVL_K * characteristic_k);
    int damage = int(__generator.characteristic_gen() / 4 * points);
    int armor = int(__generator.characteristic_gen() / 4 * points);
    int health = int(__generator.characteristic_gen() / 4 * points);
    int dexterity = int(__generator.characteristic_gen() / 4 * points);
    int luck = __generator.luck_gen();
    return Characteristics(damage, armor, health_default + health, dexterity, luck);
}

Person GameManager::generate_person() noexcept {
    string firstname = firstnames[__generator.firstname_i_gen()];
    string lastname = lastnames[__generator.lastname_i_gen()];
    Characteristics characteristics = generate_characteristics();
    IPersonClass person_class = person_classes[__generator.person_class_i_gen()];
    return Person(lastname + " " + firstname, characteristics, person_class);
}

vector<Enemy> GameManager::generate_enemies(GameOptions game_options) noexcept {
    vector<Enemy> vec = {};
    for (int i; i < game_options.enemies_count; i++) {
        string firstname = firstnames[__generator.firstname_i_gen()];
        string lastname = lastnames[__generator.lastname_i_gen()];
        Characteristics characteristics = generate_characteristics(WEAKNESS_K);
        IEnemyClass enemy_class = enemy_classes[__generator.enemy_class_i_gen()];
        float intellect = __generator.intellect_gen();
        Enemy enemy = Enemy(lastname + " " + firstname, characteristics, enemy_class, intellect);
        vec.push_back(enemy);
    }
    return vec;
}

Map GameManager::generate_map() noexcept {
    __level++;
    GameOptions game_options = generate_game_options();
    vector<Enemy> enemies = generate_enemies(game_options);
    Person person = generate_person();
    return Map(enemies, person, __map_options);
}
};
