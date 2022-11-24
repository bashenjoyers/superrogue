#include "Map.h"
#include "Model/GameModel/values.h"
#include "Model/GameModel/Map/Generator/RandomGenerating/BinaryTreeMazeGenerator.h"
#include <memory>

using std::max;
using std::optional;
using std::set;
using std::shared_ptr;
using std::vector;

namespace GameModel::Map {
using namespace Abstract;

MapInfo::MapInfo(vector<MapEntityWithPosition> map_positions,
                 PersonWithPosition person, MapOptions mapOptions)
    : map_positions(map_positions), mapOptions(mapOptions) {
  name = person.get_name();
  characteristics = person.get_full_characteristics();
  description = person.get_description();
  inventory = person.inventory;
  weapon_melee = person.is_weapon_melee();
}

Map::Map(set<Enemy> enemies, std::shared_ptr<Person> person, MapOptions map_options, int level)
    : person_with_position(PersonWithPosition(*person)),
      map_options(map_options), level(level) {
  person_ref = person;
  enemies_with_positions = {};
  for (Enemy enemy : enemies) {
    enemies_with_positions.push_back(EnemyWithPosition(enemy));
  }
  generate_map_and_door(); // create Map and door
  set_positions();         // set Person and enemies positions, enemies areas
  game_status = GameStatus::IN_PROGRESS;
}

GameStatus Map::get_game_status() const noexcept { return game_status; }

void Map::set_positions() noexcept {
  std::uniform_int_distribution<int> x_gen(0, map_options.width-1);
  std::uniform_int_distribution<int> y_gen(0, map_options.height-1);
  while (true) {
      int x = x_gen(Values::generator);
      int y = y_gen(Values::generator);
      if (map[x][y] == MapEntity::FLOOR) {
        person_with_position.pos = Position(x, y);
        map[x][y] = MapEntity::PERSON;
        break;
      }
    }
  
  std::vector<EnemyWithPosition> enemies_with_positions_new = {};
  for (auto enemy : enemies_with_positions) {
    while (true) {
      int x = x_gen(Values::generator);
      int y = y_gen(Values::generator);
      if (map[x][y] == MapEntity::FLOOR) {
        enemy.pos = Position(x, y);
        enemies_with_positions_new.push_back(enemy);
        map[x][y] = enemy.get_enemy_class()->get_map_entity();
        break;
      }
    }
  }
  swap(enemies_with_positions, enemies_with_positions_new);
}

void Map::generate_map_and_door() noexcept {
  BinaryTreeMazeGenerator gen;
  convertMapFromBool(gen.generate(map_options));
  map[map_options.width-1][map_options.height-1] = MapEntity::DOOR;

  // remove later
  std::uniform_int_distribution<int> x_gen(0, map_options.width-1);
  std::uniform_int_distribution<int> y_gen(0, map_options.height-1);
  for (int i = 0; i < 5; i++) {
    while (true) {
      int x = x_gen(Values::generator);
      int y = y_gen(Values::generator);
      if (map[x][y] == MapEntity::FLOOR) {
        auto item = drop_item();
        if (item != std::nullopt) {
          items.insert({Position(x,y), item.value()});
          auto iitem = item.value();
          map[x][y] = (dynamic_cast<Potion*>(&*iitem) != nullptr) ? MapEntity::POTION : MapEntity::ITEM;
        }
        break;
      }
    }
  }
}

vector<MapEntityWithPosition>
Map::visible_cells(const Position &pos, int radius, bool ignore_walls = false,
                   const vector<Position> &area = {}) const noexcept {
  // if area is empty - no limits for it
  // TODO (return cells visible from position)
//  if (area.size() == 0) {
//
//  } else {
//  }
//  return {};

  vector<MapEntityWithPosition> ans;
  for (size_t y = 0; y < map.front().size(); y++) {
      for (size_t x = 0; x < map.size(); x++) {
          ans.push_back(MapEntityWithPosition{ .pos = Position(x, y), .map_entity = map[x][y] });
      }
  }

  return ans;
}

bool Map::in_map(int x, int y) const noexcept {
  return x >= 0 && y >= 0 && x < map_options.width && y < map_options.height;
}

bool Map::is_vacant_cell(int x, int y) const noexcept {
  MapEntity map_entity = map[x][y];
  return map_entity == MapEntity::FLOOR || map_entity == MapEntity::ITEM ||
         map_entity == MapEntity::POTION || map_entity == MapEntity::DOOR;
}

bool Map::is_door_cell(int x, int y) const noexcept {
  MapEntity map_entity = map[x][y];
  return map_entity == MapEntity::DOOR;
}

bool Map::is_anybody_cell(int x, int y) const noexcept {
  MapEntity map_entity = map[x][y];
  return map_entity == MapEntity::PERSON || map_entity == MapEntity::ENEMY ||
         map_entity == MapEntity::ENEMY_AGRESSIVE ||
         map_entity == MapEntity::ENEMY_COWARD ||
         map_entity == MapEntity::ENEMY_FLYING ||
         map_entity == MapEntity::ENEMY_INDIFFERENT ||
         map_entity == MapEntity::ENEMY_ORDINARY ||
         map_entity == MapEntity::ENEMY_TRAVELER;
}

MapEntity Map::get_cell_type(const Position& pos) const noexcept {
  auto it_item = items.find(pos);
  if (it_item == items.end()) {
    return MapEntity::FLOOR;
  }
  auto iitem = it_item->second;
  if (dynamic_cast<Potion*>(&*iitem) != nullptr)
    return MapEntity::POTION;
  return MapEntity::ITEM;
}

bool Map::step(CharacterAction action) {
  if (get_game_status() != GameStatus::IN_PROGRESS) {
    return false;
  }
  if (action == CharacterAction::CHANGE_ITEM) {
    change_item();
    return true;
  }
  if (!action_person(action)) {
    return false;
  }
  for (int i = 0; i < enemies_with_positions.size(); i++) {
    auto enemy_class = enemies_with_positions[i].get_enemy_class();
    int radius = enemy_class->get_settings().visible_radius;
    bool ignore_walls = enemy_class->get_settings().ignore_walls;
    vector<MapEntityWithPosition> cells =
        visible_cells(enemies_with_positions[i].pos, radius, ignore_walls,
                      enemies_with_positions[i].area);
    CharacterAction enemy_action =
        enemy_class->strategy(cells, enemies_with_positions[i].pos);
    action_enemy(enemy_action, enemies_with_positions[i]);
  }
  return true;
}

MapInfo Map::get_map_info() const noexcept {
  int radius =
      person_with_position.get_person_class()->get_settings().visible_radius;
  vector<MapEntityWithPosition> map_positions =
      visible_cells(person_with_position.pos, radius);
  return MapInfo(map_positions, person_with_position, map_options);
}

optional<std::shared_ptr<IItem>> Map::drop_item() const noexcept {
  float luck = person_with_position.get_full_characteristics().luck;
  if (drop_gen(Values::generator) < luck) {
    int i = drop_gen_i(Values::generator);
    if (i >= Values::items_types.size()) {
      i -= Values::items_types.size();
      return Values::get_potion(Values::potions_types.at(i), level);
    }
    return Values::get_item(Values::items_types.at(i), level);
  }
  return std::nullopt;
};

void Map::punch_cells_in_order(const vector<Position>& positions,
                               const Characteristics& characteristics) noexcept {
  for (Position pos : positions) {
    if (!in_map(pos.x, pos.y))
      break;
    if (is_anybody_cell(pos.x, pos.y)) {
      if (person_with_position.pos == pos) {
        if (punch(person_with_position, characteristics)) { // Person died
          map[person_with_position.pos.x][person_with_position.pos.y] = get_cell_type(person_with_position.pos);
          game_status = GameStatus::END;
          *person_ref = (Person)person_with_position;
          return;
        }
      } else {
        EnemyWithPosition *erased_enemy = nullptr;
        for (int i = 0; i < enemies_with_positions.size(); i++) {
          if (enemies_with_positions[i].pos == pos) {
            if (punch(enemies_with_positions[i], characteristics)) {
              erased_enemy = &enemies_with_positions[i];
              break;
            }
          }
        }
        if (erased_enemy != nullptr) {
          optional<shared_ptr<IItem>> item = drop_item();
          if (item == std::nullopt) {
            map[erased_enemy->pos.x][erased_enemy->pos.y] =
                get_cell_type(erased_enemy->pos);
          } else {
            items.insert({erased_enemy->pos, item.value()});
            auto iitem = item.value();
            map[erased_enemy->pos.x][erased_enemy->pos.y] =
                (dynamic_cast<Potion*>(&*iitem) != nullptr) ? MapEntity::POTION : MapEntity::ITEM;
          }
          enemies_with_positions.erase(std::remove(enemies_with_positions.begin(), enemies_with_positions.end(), *erased_enemy), enemies_with_positions.end());
        }
        return;
      }
    } else if (is_vacant_cell(pos.x, pos.y)) {
      continue;
    } else {
      break;
    }
  }
}

bool Map::punch(ICharacter& character,
                 const Characteristics& characteristics) noexcept {
  Characteristics character_characteristics;
  if ((dynamic_cast<PersonWithPosition*>(&character) != nullptr)) {
    character_characteristics = dynamic_cast<PersonWithPosition *>(&character)
                                    ->get_full_characteristics();
  } else {
    character_characteristics = character.get_characteristics();
  }
  float dodge_chance = DEFAULT_DODGE_CHANCE;
  if (character_characteristics.dexterity > characteristics.dexterity) {
    dodge_chance = max(1 - (float)characteristics.dexterity / character_characteristics.dexterity, dodge_chance);
  }
  if (dodge_gen(Values::generator) <= dodge_chance) {
    return false;
  }
  int damage = std::max(characteristics.damage - character_characteristics.armor, DEFENCE_DEFAULT_DAMAGE * level);
  return character.damaged(damage);
}

bool Map::punch_step(ICharacter& character1, ICharacter& character2) noexcept {
  auto person1 = dynamic_cast<PersonWithPosition*>(&character1);  //
  auto person2 = dynamic_cast<PersonWithPosition*>(&character2);  // only for get characteristics and check is it person
  Characteristics character1_characteristics, character2_characteristics;
  if (person1 != nullptr) {
    character1_characteristics = person1->get_full_characteristics();
  } else {
    character1_characteristics = character1.get_characteristics();
  }
  if (person2 != nullptr) {
    character2_characteristics = person2->get_full_characteristics();
  } else {
    character2_characteristics = character2.get_characteristics();
  }
  character1.punch();
  float dodge_chance = 0;
  if (character2_characteristics.dexterity > character1_characteristics.dexterity) {
    dodge_chance = max(1 - (float)character1_characteristics.dexterity / character2_characteristics.dexterity, dodge_chance);
  }
  if (dodge_gen(Values::generator) > dodge_chance) {
    if (character2.damaged(character1_characteristics.damage)) { // smb died
      if (person2 != nullptr) { // Person died
        map[person2->pos.x][person2->pos.y] = get_cell_type(person2->pos);
        game_status = GameStatus::END;
        *person_ref = (Person)person_with_position;
      } else {  // not drop anything
        EnemyWithPosition* enemy = dynamic_cast<EnemyWithPosition*>(&character2);
        map[enemy->pos.x][enemy->pos.y] = get_cell_type(enemy->pos);
        enemies_with_positions.erase(std::remove(enemies_with_positions.begin(), enemies_with_positions.end(), *enemy), enemies_with_positions.end());
      }
      return true;
    }
  }
  character2.punch();
  dodge_chance = 0;
  if (character1_characteristics.dexterity > character2_characteristics.dexterity) {
    dodge_chance = max(1 - (float)character2_characteristics.dexterity / character1_characteristics.dexterity, dodge_chance);
  }
  if (dodge_gen(Values::generator) > dodge_chance) {
    if (character1.damaged(character2_characteristics.damage)) { // smb died
      if (person1 != nullptr) { // Person died
        map[person1->pos.x][person1->pos.y] = get_cell_type(person1->pos);
        game_status = GameStatus::END;
        *person_ref = (Person)person_with_position;
      } else {  // not drop anything
        EnemyWithPosition* enemy = dynamic_cast<EnemyWithPosition*>(&character1);
        map[enemy->pos.x][enemy->pos.y] = get_cell_type(enemy->pos);
        enemies_with_positions.erase(std::remove(enemies_with_positions.begin(), enemies_with_positions.end(), *enemy), enemies_with_positions.end());
      }
    }
  }
  return false;
}

bool Map::any_step_anybody(WithPosition &anybody, Position pos) noexcept {
  if (is_door_cell(pos.x, pos.y)) {
    if ((dynamic_cast<PersonWithPosition*>(&anybody) != nullptr)) {
      map[anybody.pos.x][anybody.pos.y] = get_cell_type(anybody.pos);
      map[pos.x][pos.y] = MapEntity::PERSON;
      anybody.pos = pos;
      game_status = GameStatus::NEXT_LVL;
      *person_ref = (Person)person_with_position;
      return true;
    }
  } else {
    map[anybody.pos.x][anybody.pos.y] = get_cell_type(anybody.pos); // FIXME(update later: mb WALL)
    if (dynamic_cast<PersonWithPosition*>(&anybody) != nullptr) {
      map[pos.x][pos.y] = MapEntity::PERSON;
    } else {
      map[pos.x][pos.y] = dynamic_cast<EnemyWithPosition *>(&anybody)
                              ->get_enemy_class()->get_map_entity();
    }
    anybody.pos = pos;
    return true;
  }
  return false;
}

bool Map::any_punch_step_anybody(WithPosition &anybody, Position pos) noexcept {
  int character1_i = -1, character2_i = -1;
  for (int i = 0; i < enemies_with_positions.size() && !(character1_i != -1 && character2_i != -1); i++) {
    if (enemies_with_positions[i].pos == anybody.pos) {
      character1_i = i;
    }
    if (enemies_with_positions[i].pos == pos) {
      character2_i = i;
    }
  }
  if (character1_i == -1) {
    return punch_step(person_with_position, enemies_with_positions[character2_i]);
  } else if (character2_i == -1) {
    return punch_step(enemies_with_positions[character1_i], person_with_position);
  } else {
    return punch_step(enemies_with_positions[character1_i], enemies_with_positions[character2_i]);
  }
}

bool Map::step_anybody(CharacterAction action, WithPosition &anybody) noexcept {
  bool step_was = false;
  switch (action) {
  case CharacterAction::STEP_RIGHT:
    if (anybody.pos.x + 1 < map_options.width) {
      if (is_vacant_cell(anybody.pos.x + 1, anybody.pos.y)) {
        step_was = any_step_anybody(anybody, Position(anybody.pos.x + 1, anybody.pos.y));
      } else if (is_anybody_cell(anybody.pos.x + 1, anybody.pos.y)) {
        if (any_punch_step_anybody(anybody, Position(anybody.pos.x + 1, anybody.pos.y))) {
          any_step_anybody(anybody, Position(anybody.pos.x + 1, anybody.pos.y));
        }
        step_was = true;
      }
    }
    break;
  case CharacterAction::STEP_BACK:
    if (anybody.pos.y + 1 < map_options.height) {
      if (is_vacant_cell(anybody.pos.x, anybody.pos.y + 1)) {
        step_was = any_step_anybody(anybody, Position(anybody.pos.x, anybody.pos.y + 1));
      } else if (is_anybody_cell(anybody.pos.x, anybody.pos.y + 1)) {
        if (any_punch_step_anybody(anybody, Position(anybody.pos.x, anybody.pos.y + 1))) {
          any_step_anybody(anybody, Position(anybody.pos.x, anybody.pos.y + 1));
        }
        step_was = true;
      }
    }
    break;  
  case CharacterAction::STEP_LEFT:
    if (anybody.pos.x >= 1) {
      if (is_vacant_cell(anybody.pos.x - 1, anybody.pos.y)) {
        step_was = any_step_anybody(anybody, Position(anybody.pos.x - 1, anybody.pos.y));
      } else if (is_anybody_cell(anybody.pos.x - 1, anybody.pos.y)) {
        if (any_punch_step_anybody(anybody, Position(anybody.pos.x - 1, anybody.pos.y))) {
          any_step_anybody(anybody, Position(anybody.pos.x - 1, anybody.pos.y));
        } 
        step_was = true;
      }
    }
    break;
  case CharacterAction::STEP_FORWARD:
    if (anybody.pos.y >= 1) {
      if (is_vacant_cell(anybody.pos.x, anybody.pos.y - 1)) {
        step_was = any_step_anybody(anybody, Position(anybody.pos.x, anybody.pos.y - 1));
      } else if (is_anybody_cell(anybody.pos.x, anybody.pos.y - 1)) {
        if (any_punch_step_anybody(anybody, Position(anybody.pos.x, anybody.pos.y - 1))) {
          any_step_anybody(anybody, Position(anybody.pos.x, anybody.pos.y - 1));
        }
        step_was = true;
      }
    }
    break;
  default:
    break;
  }
  return step_was;
}

void Map::change_item() {
  person_with_position.take_item();
  auto it_item = items.find(person_with_position.pos);
  if (it_item != items.end()) {
    auto iitem = it_item->second;
    items.erase(it_item);
    if (dynamic_cast<Potion*>(&*iitem) != nullptr) {
      person_with_position.inventory.add_potion(
          *dynamic_cast<Potion *>(&*iitem));
    } else {
      optional<Item> item_before = std::nullopt;
      Item item = *dynamic_cast<Item *>(&*iitem);
      switch (item.get_item_type()) {
      case ItemType::HELMET:
        item_before = person_with_position.inventory.get_helmet();
        person_with_position.inventory.set_helmet(item);
        if (item_before.has_value()) {
          auto item_before_value = item_before.value();
          items[person_with_position.pos] = std::make_shared<Item>(item_before_value.get_name(), item_before_value.get_description(), item_before_value.get_characteristics(), item_before_value.get_item_type());
        }
        break;
      case ItemType::ARMOR:
        item_before = person_with_position.inventory.get_armor();
        person_with_position.inventory.set_armor(item);
        if (item_before.has_value()) {
          auto item_before_value = item_before.value();
          items[person_with_position.pos] = std::make_shared<Item>(item_before_value.get_name(), item_before_value.get_description(), item_before_value.get_characteristics(), item_before_value.get_item_type());
        }
        break;
      case ItemType::BOOTS:
        item_before = person_with_position.inventory.get_boots();
        person_with_position.inventory.set_boots(item);
        if (item_before.has_value()) {
          auto item_before_value = item_before.value();
          items[person_with_position.pos] = std::make_shared<Item>(item_before_value.get_name(), item_before_value.get_description(), item_before_value.get_characteristics(), item_before_value.get_item_type());
        }
        break;
      case ItemType::WEAPON_MELEE:
        item_before = person_with_position.inventory.get_weapon_melee();
        person_with_position.inventory.set_weapon_melee(item);
        if (item_before.has_value()) {
          auto item_before_value = item_before.value();
          items[person_with_position.pos] = std::make_shared<Item>(item_before_value.get_name(), item_before_value.get_description(), item_before_value.get_characteristics(), item_before_value.get_item_type());
        }
        break;
      case ItemType::WEAPON_DISTANT:
        item_before = person_with_position.inventory.get_weapon_distant();
        person_with_position.inventory.set_weapon_distant(item);
        if (item_before.has_value()) {
          auto item_before_value = item_before.value();
          items[person_with_position.pos] = std::make_shared<Item>(item_before_value.get_name(), item_before_value.get_description(), item_before_value.get_characteristics(), item_before_value.get_item_type());
        }
        break;
      default:
        throw GameObjectException("wrong Item type");
      }
    }
  }
}

bool Map::action_person(CharacterAction action) {
  bool correct = false;
  int range = person_with_position.is_weapon_melee() ? 1 : DISTANT_RANGE;
  Position pos = person_with_position.pos;
  vector<Position> positions = {};
  switch (action) {
  case CharacterAction::PUNCH_RIGHT:
    for (int i = 1; i <= range; i++) {
      positions.push_back(Position(pos.x + i, pos.y));
    }
    person_with_position.punch();
    punch_cells_in_order(positions,
                         person_with_position.get_full_characteristics());
    correct = true;
    break;
  case CharacterAction::PUNCH_BACK:
    for (int i = 1; i <= range; i++) {
      positions.push_back(Position(pos.x, pos.y + i));
    }
    person_with_position.punch();
    punch_cells_in_order(positions,
                         person_with_position.get_full_characteristics());
    correct = true;
    break;
  case CharacterAction::PUNCH_LEFT:
    for (int i = 1; i <= range; i++) {
      positions.push_back(Position(pos.x - i, pos.y));
    }
    person_with_position.punch();
    punch_cells_in_order(positions,
                         person_with_position.get_full_characteristics());
    correct = true;
    break;
  case CharacterAction::PUNCH_FORWARD:
    for (int i = 1; i <= range; i++) {
      positions.push_back(Position(pos.x, pos.y - i));
    }
    person_with_position.punch();
    punch_cells_in_order(positions,
                         person_with_position.get_full_characteristics());
    correct = true;
    break;
  case CharacterAction::POTION_1:
    person_with_position.potion(0);
    correct = true;
    break;
  case CharacterAction::POTION_2:
    person_with_position.potion(1);
    correct = true;
    break;
  case CharacterAction::POTION_3:
    person_with_position.potion(2);
    correct = true;
    break;
  case CharacterAction::POTION_4:
    person_with_position.potion(3);
    correct = true;
    break;
  case CharacterAction::POTION_5:
    person_with_position.potion(4);
    correct = true;
    break;
  case CharacterAction::CHANGE_WEAPON:
    correct = person_with_position.change_weapon();
    break;
  case CharacterAction::CHANGE_ITEM:
    break;
  case CharacterAction::WAIT:
    correct = true;
    break;
  default:
    if (step_anybody(action, person_with_position)) {
      person_with_position.step();
      correct = true;
    }
    break;
  }
  return correct;
}

void Map::action_enemy(
    CharacterAction action,
    EnemyWithPosition& enemy_with_position) {
  bool correct = false;
  int range = enemy_with_position.get_attack_range();
  Position pos = enemy_with_position.pos;
  vector<Position> positions = {};
  switch (action) {
  case CharacterAction::PUNCH_RIGHT:
    for (int i = 1; i <= range; i++) {
      positions.push_back(Position(pos.x + i, pos.y));
    }
    enemy_with_position.punch();
    punch_cells_in_order(positions, enemy_with_position.get_characteristics());
    correct = true;
    break;
  case CharacterAction::PUNCH_BACK:
    for (int i = 1; i <= range; i++) {
      positions.push_back(Position(pos.x, pos.y + i));
    }
    enemy_with_position.punch();
    punch_cells_in_order(positions, enemy_with_position.get_characteristics());
    correct = true;
    break;
  case CharacterAction::PUNCH_LEFT:
    for (int i = 1; i <= range; i++) {
      positions.push_back(Position(pos.x - i, pos.y));
    }
    enemy_with_position.punch();
    punch_cells_in_order(positions, enemy_with_position.get_characteristics());
    correct = true;
    break;
  case CharacterAction::PUNCH_FORWARD:
    for (int i = 1; i <= range; i++) {
      positions.push_back(Position(pos.x, pos.y - i));
    }
    enemy_with_position.punch();
    punch_cells_in_order(positions, enemy_with_position.get_characteristics());
    correct = true;
    break;
  case CharacterAction::POTION_1:
    break;
  case CharacterAction::POTION_2:
    break;
  case CharacterAction::POTION_3:
    break;
  case CharacterAction::POTION_4:
    break;
  case CharacterAction::POTION_5:
    break;
  case CharacterAction::CHANGE_WEAPON:
    break;
  case CharacterAction::CHANGE_ITEM:
    break;
  case CharacterAction::WAIT:
    correct = true;
    break;
  default:
    if (step_anybody(action, enemy_with_position)) {
      enemy_with_position.step();
      correct = true;
    }
    break;
  }
  if (!correct) {
    throw StepException("Enemy: failed " + to_string(action));
  }
}

void Map::convertMapFromBool(const std::vector<std::vector<bool>> &genMap) {
    map.assign(genMap.size(), std::vector<MapEntity>(genMap.front().size(), MapEntity::FLOOR));
    for (size_t y = 0; y < genMap.front().size(); y++) {
        for (size_t x = 0; x < genMap.size(); x++) {
            map[x][y] = genMap[x][y] ? MapEntity::FLOOR : MapEntity::WALL;
        }
    }
}

}; // namespace GameModel::Map
