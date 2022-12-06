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
                 CharacterWithPosition person_with_position, MapOptions mapOptions)
    : map_positions(map_positions), mapOptions(mapOptions) {
  auto person = dynamic_cast<Person*>(&*person_with_position.character);
  name = person->get_name();
  characteristics = person->get_full_characteristics();
  description = person->get_description();
  inventory = person->inventory;
  weapon_melee = person->is_weapon_melee();
}

void Map::remove_enemy(const CharacterWithPosition& character_with_position) noexcept {
  auto removed_enemy = std::dynamic_pointer_cast<IEnemy>(character_with_position.character);
  if (enemies_with_positions.size() == 0) {
    return;
  }
  CharacterWithPosition enemy = enemies_with_positions.back();
  enemies_with_positions.pop_back();
  if (removed_enemy == std::dynamic_pointer_cast<IEnemy>(enemy.character)) {
    return;
  }
  for (int i = 0; i < enemies_with_positions.size(); i++) {
    if (removed_enemy == std::dynamic_pointer_cast<IEnemy>(enemies_with_positions[i].character)) {
      enemies_with_positions[i] = enemy;
      return;
    }
  }
}

Map::Map(std::shared_ptr<Generation::ItemGenerator> itemGenerator,
         std::shared_ptr<Generation::Map::MapGenerator> mapGenerator,
         std::shared_ptr<Generation::AbstractEnemyFactory> enemyFactory,
         std::shared_ptr<Person> person,
         MapOptions map_options,
         int level) :
      map_options(map_options), level(level), itemGenerator(itemGenerator) {
    Generation::Map::MapBuilder mb;
    mb.setEnemiesCount(enemyCount);
    mb.setItemsCount(itemsCount);
    mb.setEnemiesFactory(enemyFactory);
    mb.setItemsGenerator(itemGenerator);
    mb.setMapGenerator(mapGenerator);
    mb.setMapOptions(map_options);
    mb.setPerson(person);
    mb.build();

    map = mb.getMap();
    enemies_with_positions = mb.getEnemies();
    items = mb.getItems();
    person_with_position = *mb.getPerson();
}

GameStatus Map::get_game_status() const noexcept { return game_status; }

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
         map_entity == MapEntity::ENEMY_TRAVELER ||
         map_entity == MapEntity::ENEMY_REPLICATOR;
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
    auto enemy = std::dynamic_pointer_cast<IEnemy>(enemies_with_positions[i].character);
    int radius = enemy->get_settings().visible_radius;
    bool ignore_walls = enemy->get_settings().ignore_walls;
    vector<MapEntityWithPosition> cells =
        visible_cells(enemies_with_positions[i].pos, radius, ignore_walls,
                      enemies_with_positions[i].area);
    CharacterAction enemy_action =
        enemy->strategy(cells, enemies_with_positions[i].pos);
    action_enemy(enemy_action, enemies_with_positions[i]);

    auto replicator = dynamic_cast<Replicator*>(&*enemy);
    if (replicator != nullptr) {
        bool is_vacant = is_vacant_cell(enemies_with_positions[i].pos.x, enemies_with_positions[i].pos.y);
        if (replicator->get_replication_probability() > 0.5 && is_vacant) {
            CharacterWithPosition character = CharacterWithPosition(replicator);
            this->enemies_with_positions.push_back(replicator);
        }
    }
  }
  return true;
}

MapInfo Map::get_map_info() const noexcept {
  auto person = std::dynamic_pointer_cast<Person>(person_with_position.character);
  int radius =
      person->get_settings().visible_radius;
  vector<MapEntityWithPosition> map_positions =
      visible_cells(person_with_position.pos, radius);
  return MapInfo(map_positions, person_with_position, map_options);
}

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
          return;
        }
      } else {
        CharacterWithPosition *erased_enemy = nullptr;
        for (int i = 0; i < enemies_with_positions.size(); i++) {
          if (enemies_with_positions[i].pos == pos) {
            if (punch(enemies_with_positions[i], characteristics)) {
              erased_enemy = &enemies_with_positions[i];
              break;
            }
          }
        }
        if (erased_enemy != nullptr) {
          shared_ptr<IItem> item = itemGenerator->generate();
          if (item == nullptr) {
            map[erased_enemy->pos.x][erased_enemy->pos.y] =
                get_cell_type(erased_enemy->pos);
          } else {
            items.insert({erased_enemy->pos, item});
            map[erased_enemy->pos.x][erased_enemy->pos.y] = item->getMapEntity();
          }
          remove_enemy(*erased_enemy);
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

bool Map::punch(CharacterWithPosition& character_with_position,
                 const Characteristics& characteristics) noexcept {
  Characteristics character_characteristics;
  if ((dynamic_cast<Person*>(&*character_with_position.character) != nullptr)) {
    character_characteristics = dynamic_cast<Person *>(&*character_with_position.character)
                                    ->get_full_characteristics();
  } else {
    character_characteristics = character_with_position.character->get_characteristics();
  }
  float dodge_chance = DEFAULT_DODGE_CHANCE;
  if (character_characteristics.dexterity > characteristics.dexterity) {
    dodge_chance = max(1 - (float)characteristics.dexterity / character_characteristics.dexterity, dodge_chance);
  }
  if (dodge_gen(Values::generator) <= dodge_chance) {
    return false;
  }
  int damage = std::max(characteristics.damage - character_characteristics.armor, DEFENCE_DEFAULT_DAMAGE * level);
  return character_with_position.character->damaged(damage);
}

bool Map::punch_step(const CharacterWithPosition& character1_with_position, const CharacterWithPosition& character2_with_position) noexcept {
  auto person1 = std::dynamic_pointer_cast<Person>(character1_with_position.character);  //
  auto person2 = std::dynamic_pointer_cast<Person>(character2_with_position.character);  // only for get characteristics and check is it person
  Characteristics character1_characteristics, character2_characteristics;
  if (person1 != nullptr) {
    character1_characteristics = person1->get_full_characteristics();
  } else {
    character1_characteristics = character1_with_position.character->get_characteristics();
  }
  if (person2 != nullptr) {
    character2_characteristics = person2->get_full_characteristics();
  } else {
    character2_characteristics = character2_with_position.character->get_characteristics();
  }
  character1_with_position.character->punch();
  float dodge_chance = 0;
  if (character2_characteristics.dexterity > character1_characteristics.dexterity) {
    dodge_chance = max(1 - (float)character1_characteristics.dexterity / character2_characteristics.dexterity, dodge_chance);
  }
  if (dodge_gen(Values::generator) > dodge_chance) {
    if (character2_with_position.character->damaged(character1_characteristics.damage)) { // smb died
      if (person2 != nullptr) { // Person died
        map[character2_with_position.pos.x][character2_with_position.pos.y] = get_cell_type(character2_with_position.pos);
        game_status = GameStatus::END;
      } else {  // not drop anything
        map[character2_with_position.pos.x][character2_with_position.pos.y] = get_cell_type(character2_with_position.pos);
        remove_enemy(character2_with_position);
      }
      return true;
    }
  }
  character2_with_position.character->punch();
  dodge_chance = 0;
  if (character1_characteristics.dexterity > character2_characteristics.dexterity) {
    dodge_chance = max(1 - (float)character2_characteristics.dexterity / character1_characteristics.dexterity, dodge_chance);
  }
  if (dodge_gen(Values::generator) > dodge_chance) {
    if (character1_with_position.character->damaged(character2_characteristics.damage)) { // smb died
      if (person1 != nullptr) { // Person died
        map[character1_with_position.pos.x][character1_with_position.pos.y] = get_cell_type(character1_with_position.pos);
        game_status = GameStatus::END;
      } else {  // not drop anything
        map[character1_with_position.pos.x][character1_with_position.pos.y] = get_cell_type(character1_with_position.pos);
        remove_enemy(character1_with_position);
      }
    }
  }
  return false;
}

bool Map::any_step_anybody(CharacterWithPosition &anybody, Position pos) noexcept {
  if (is_door_cell(pos.x, pos.y)) {
    if ((dynamic_cast<Person*>(&*anybody.character) != nullptr)) {
      map[anybody.pos.x][anybody.pos.y] = get_cell_type(anybody.pos);
      map[pos.x][pos.y] = MapEntity::PERSON;
      anybody.pos = pos;
      game_status = GameStatus::NEXT_LVL;
      return true;
    }
  } else {
    map[anybody.pos.x][anybody.pos.y] = get_cell_type(anybody.pos); // FIXME(update later: mb WALL)
    if (dynamic_cast<Person*>(&*anybody.character) != nullptr) {
      map[pos.x][pos.y] = MapEntity::PERSON;
    } else {
      map[pos.x][pos.y] = dynamic_cast<IEnemy*>(&*anybody.character)
                              ->get_map_entity();
    }
    anybody.pos = pos;
    return true;
  }
  return false;
}

bool Map::any_punch_step_anybody(CharacterWithPosition &anybody, Position pos) noexcept {
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

bool Map::step_anybody(CharacterAction action, CharacterWithPosition &anybody) noexcept {
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
  auto person = std::dynamic_pointer_cast<Person>(person_with_position.character);
  person->take_item();
  auto it_item = items.find(person_with_position.pos);
  if (it_item != items.end()) {
    auto iitem = it_item->second;
    items.erase(it_item);
    if (dynamic_cast<Potion*>(&*iitem) != nullptr) {
      person->inventory.add_potion(
          *dynamic_cast<Potion *>(&*iitem));
    } else {
      optional<Item> item_before = std::nullopt;
      Item item = *dynamic_cast<Item *>(&*iitem);
      switch (item.get_item_type()) {
      case ItemType::HELMET:
        item_before = person->inventory.get_helmet();
        person->inventory.set_helmet(item);
        if (item_before.has_value()) {
          auto item_before_value = item_before.value();
          items[person_with_position.pos] = std::make_shared<Item>(item_before_value.get_name(), item_before_value.get_description(), item_before_value.get_characteristics(), item_before_value.get_item_type());
        }
        break;
      case ItemType::ARMOR:
        item_before = person->inventory.get_armor();
        person->inventory.set_armor(item);
        if (item_before.has_value()) {
          auto item_before_value = item_before.value();
          items[person_with_position.pos] = std::make_shared<Item>(item_before_value.get_name(), item_before_value.get_description(), item_before_value.get_characteristics(), item_before_value.get_item_type());
        }
        break;
      case ItemType::BOOTS:
        item_before = person->inventory.get_boots();
        person->inventory.set_boots(item);
        if (item_before.has_value()) {
          auto item_before_value = item_before.value();
          items[person_with_position.pos] = std::make_shared<Item>(item_before_value.get_name(), item_before_value.get_description(), item_before_value.get_characteristics(), item_before_value.get_item_type());
        }
        break;
      case ItemType::WEAPON_MELEE:
        item_before = person->inventory.get_weapon_melee();
        person->inventory.set_weapon_melee(item);
        if (item_before.has_value()) {
          auto item_before_value = item_before.value();
          items[person_with_position.pos] = std::make_shared<Item>(item_before_value.get_name(), item_before_value.get_description(), item_before_value.get_characteristics(), item_before_value.get_item_type());
        }
        break;
      case ItemType::WEAPON_DISTANT:
        item_before = person->inventory.get_weapon_distant();
        person->inventory.set_weapon_distant(item);
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
  auto person = std::dynamic_pointer_cast<Person>(person_with_position.character);
  bool correct = false;
  int range = person->is_weapon_melee() ? 1 : DISTANT_RANGE;
  Position pos = person_with_position.pos;
  vector<Position> positions = {};
  switch (action) {
  case CharacterAction::PUNCH_RIGHT:
    for (int i = 1; i <= range; i++) {
      positions.push_back(Position(pos.x + i, pos.y));
    }
    person_with_position.character->punch();
    punch_cells_in_order(positions,
                         person->get_full_characteristics());
    correct = true;
    break;
  case CharacterAction::PUNCH_BACK:
    for (int i = 1; i <= range; i++) {
      positions.push_back(Position(pos.x, pos.y + i));
    }
    person_with_position.character->punch();
    punch_cells_in_order(positions,
                         person->get_full_characteristics());
    correct = true;
    break;
  case CharacterAction::PUNCH_LEFT:
    for (int i = 1; i <= range; i++) {
      positions.push_back(Position(pos.x - i, pos.y));
    }
    person_with_position.character->punch();
    punch_cells_in_order(positions,
                         person->get_full_characteristics());
    correct = true;
    break;
  case CharacterAction::PUNCH_FORWARD:
    for (int i = 1; i <= range; i++) {
      positions.push_back(Position(pos.x, pos.y - i));
    }
    person_with_position.character->punch();
    punch_cells_in_order(positions,
                         person->get_full_characteristics());
    correct = true;
    break;
  case CharacterAction::POTION_1:
    person->potion(0);
    correct = true;
    break;
  case CharacterAction::POTION_2:
    person->potion(1);
    correct = true;
    break;
  case CharacterAction::POTION_3:
    person->potion(2);
    correct = true;
    break;
  case CharacterAction::POTION_4:
    person->potion(3);
    correct = true;
    break;
  case CharacterAction::POTION_5:
    person->potion(4);
    correct = true;
    break;
  case CharacterAction::CHANGE_WEAPON:
    correct = person->change_weapon();
    break;
  case CharacterAction::CHANGE_ITEM:
    break;
  case CharacterAction::WAIT:
    correct = true;
    break;
  default:
    if (step_anybody(action, person_with_position)) {
      person_with_position.character->step();
      correct = true;
    }
    break;
  }
  return correct;
}

void Map::action_enemy(
    CharacterAction action,
    CharacterWithPosition& enemy_with_position) {
  bool correct = false;
  auto enemy = std::dynamic_pointer_cast<IEnemy>(enemy_with_position.character);
  int range = enemy->get_attack_range();
  Position pos = enemy_with_position.pos;
  vector<Position> positions = {};
  switch (action) {
  case CharacterAction::PUNCH_RIGHT:
    for (int i = 1; i <= range; i++) {
      positions.push_back(Position(pos.x + i, pos.y));
    }
    enemy_with_position.character->punch();
    punch_cells_in_order(positions, enemy->get_characteristics());
    correct = true;
    break;
  case CharacterAction::PUNCH_BACK:
    for (int i = 1; i <= range; i++) {
      positions.push_back(Position(pos.x, pos.y + i));
    }
    enemy_with_position.character->punch();
    punch_cells_in_order(positions, enemy->get_characteristics());
    correct = true;
    break;
  case CharacterAction::PUNCH_LEFT:
    for (int i = 1; i <= range; i++) {
      positions.push_back(Position(pos.x - i, pos.y));
    }
    enemy_with_position.character->punch();
    punch_cells_in_order(positions, enemy->get_characteristics());
    correct = true;
    break;
  case CharacterAction::PUNCH_FORWARD:
    for (int i = 1; i <= range; i++) {
      positions.push_back(Position(pos.x, pos.y - i));
    }
    enemy_with_position.character->punch();
    punch_cells_in_order(positions, enemy->get_characteristics());
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
      enemy_with_position.character->step();
      correct = true;
    }
    break;
  }
  if (!correct) {
    throw StepException("Enemy: failed " + to_string(action));
  }
}

}; // namespace GameModel::Map
