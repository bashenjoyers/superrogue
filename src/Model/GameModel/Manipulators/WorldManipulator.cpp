#include <cassert>
#include "WorldManipulator.h"
#include "Model/GameModel/abstract.h"
#include "Model/GameModel/GameObject/Character/IEnemy.h"
#include "Model/GameModel/GameObject/Character/Person.h"

//TODO BAGRORG get_settings() TO VIRTUA

bool GameModel::Map::WorldManipulator::inMap(int x, int y) const noexcept {
  return x >= 0 && y >= 0 && x < world->map_options.width && y < world->map_options.height;
}

bool GameModel::Map::WorldManipulator::isVacantCell(int x, int y) const noexcept {
  using Abstract::MapEntity;
  MapEntity map_entity = world->map[x][y];
  return map_entity == MapEntity::FLOOR || map_entity == MapEntity::ITEM ||
	  map_entity == MapEntity::POTION || map_entity == MapEntity::DOOR;
}

bool GameModel::Map::WorldManipulator::isDoorCell(int x, int y) const noexcept {
  using Abstract::MapEntity;
  MapEntity map_entity = world->map[x][y];
  return map_entity == MapEntity::DOOR;
}

bool GameModel::Map::WorldManipulator::isAnybodyAtCell(int x, int y) const noexcept {
  using Abstract::MapEntity;
  MapEntity map_entity = world->map[x][y];
  return map_entity == MapEntity::PERSON || map_entity == MapEntity::ENEMY ||
	  map_entity == MapEntity::ENEMY_AGRESSIVE ||
	  map_entity == MapEntity::ENEMY_COWARD ||
	  map_entity == MapEntity::ENEMY_FLYING ||
	  map_entity == MapEntity::ENEMY_INDIFFERENT ||
	  map_entity == MapEntity::ENEMY_ORDINARY ||
	  map_entity == MapEntity::ENEMY_TRAVELER;
}

GameModel::Abstract::MapEntity GameModel::Map::WorldManipulator::getCellType(const GameModel::Abstract::Position &pos) const noexcept {
  using Abstract::MapEntity;
  auto item = world->items.find(pos);
  if (item == world->items.end()) {
	return MapEntity::FLOOR;
  }

  return item->second->getMapEntity();
}

bool GameModel::Map::WorldManipulator::moveCharacter(std::shared_ptr<ICharacter> characterWithPosition,
													 GameModel::Abstract::Position pos) noexcept {
  using Abstract::MapEntity;
  if (isDoorCell(pos.x, pos.y)) {
	if (std::dynamic_pointer_cast<Person>(characterWithPosition) == nullptr) {
	  // Enemy can't go in door
	  return false;
	}
  }

  Abstract::Position characterPosition = characterWithPosition->get_position();
  world->map[characterPosition.x][characterPosition.y] =
	  getCellType(characterPosition);
  world->map[pos.x][pos.y] = characterWithPosition->get_map_entity();
  characterWithPosition->set_position(pos);
  return true;
}

bool GameModel::Map::WorldManipulator::makeAStep(std::shared_ptr<ICharacter> actingCharacter,
												 Abstract::Position newPosition) noexcept {
  if (inMap(newPosition.x, newPosition.y)) {
	if (isVacantCell(newPosition.x, newPosition.y)) {
	  return moveCharacter(actingCharacter, newPosition);
	} else if (isAnybodyAtCell(newPosition.x, newPosition.y)) {
	  std::shared_ptr<ICharacter> character = getCharacterByPosition(newPosition);
	  assert(character != nullptr);

	  if (punchWhileStep(actingCharacter, character)) {
		assert(isVacantCell(newPosition.x, newPosition.y));
		return moveCharacter(actingCharacter, newPosition);
	  }
	  assert(isAnybodyAtCell(newPosition.x, newPosition.y));
	  return true;
	}
  }

  return false;
}

bool GameModel::Map::WorldManipulator::act(GameModel::CharacterAction action, std::shared_ptr<ICharacter> character) {
  using namespace Abstract;

  Position position = character->get_position();
  bool acted = false;

  int range = character->getAttackRange();

  switch (action) {
  case CharacterAction::PUNCH_RIGHT:
	orientedCellsPunch(character,
					   generateCellsRayByMask(position,
											  range, /*xMask=*/
											  1, /*yMask=*/
											  0));
	acted = true;
	break;
  case CharacterAction::PUNCH_BACK:
	orientedCellsPunch(character,
					   generateCellsRayByMask(position,
											  range, /*xMask=*/
											  0, /*yMask=*/
											  1));
	acted = true;
	break;
  case CharacterAction::PUNCH_LEFT:
	orientedCellsPunch(character,
					   generateCellsRayByMask(position,
											  range, /*xMask=*/
											  -1, /*yMask=*/
											  0));
	acted = true;
	break;
  case CharacterAction::PUNCH_FORWARD:
	orientedCellsPunch(character,
					   generateCellsRayByMask(position,
											  range, /*xMask=*/
											  0, /*yMask=*/
											  -1));
	acted = true;
	break;
  case CharacterAction::WAIT: acted = true;
	break;
  case CharacterAction::STEP_FORWARD:
	if (makeAStep(character, position + Abstract::Position{0, -1})) {
	  character->step();
	  acted = true;
	}
	break;
  case CharacterAction::STEP_BACK:
	if (makeAStep(character, position + Abstract::Position{0, 1})) {
	  character->step();
	  acted = true;
	}
	break;
  case CharacterAction::STEP_LEFT:
	if (makeAStep(character, position + Abstract::Position{-1, 0})) {
	  character->step();
	  acted = true;
	}
	break;
  case CharacterAction::STEP_RIGHT:
	if (makeAStep(character, position + Abstract::Position{1, 0})) {
	  character->step();
	  acted = true;
	}
	break;
  default: break;
  }

  return acted;
}

// TODO METHOD?
GameModel::Characteristics getCharacteristicsForPunch(std::shared_ptr<GameModel::ICharacter> characterWithPosition) {
  if (auto person = std::dynamic_pointer_cast<GameModel::Person>(characterWithPosition); person != nullptr) {
	return person->get_full_characteristics();
  }

  return characterWithPosition->get_characteristics();
}

void GameModel::Map::WorldManipulator::punch(std::shared_ptr<ICharacter> puncher,
											 std::shared_ptr<ICharacter> punchee,
											 bool ignoreArmor) noexcept {
  puncher->punch();        // TODO BAGRORG RIGHT ORDER OF EXECUTION?
  Characteristics puncherChar = getCharacteristicsForPunch(puncher);
  Characteristics puncheeChar = getCharacteristicsForPunch(punchee);

  float dodge_chance = DEFAULT_DODGE_CHANCE;
  if (puncheeChar.dexterity > puncherChar.dexterity) {
	dodge_chance = std::max(1 - (float)puncherChar.dexterity / puncheeChar.dexterity, dodge_chance);
  }

  if (dodge_gen(Values::generator) <= dodge_chance) {
	return;
  }

  int damage = puncherChar.damage;
  if (!ignoreArmor) {
	damage = std::max(damage - puncheeChar.armor, DEFENCE_DEFAULT_DAMAGE * level);
  }

  punchee->takeDamage(damage);
}

bool GameModel::Map::WorldManipulator::punchWhileStep(std::shared_ptr<ICharacter> walking,
													  std::shared_ptr<ICharacter> standing) noexcept {
  // TODO BAGRORG OK WITH ORDER?
  assert((std::abs(walking->get_position().x - standing->get_position().x) <= 1
	  && walking->get_position().y == standing->get_position().y) ||
	  (std::abs(walking->get_position().y - standing->get_position().y) <= 1
		  && walking->get_position().x == standing->get_position().x));

  punch(walking, standing, true);
  if (standing->isDead()) {
	handleDeath(standing);
	return true;
  }

  punch(standing, walking, true);

  if (walking->isDead()) {
	handleDeath(walking);
  }

  return false;
}

void GameModel::Map::WorldManipulator::orientedCellsPunch(std::shared_ptr<ICharacter> actingCharacter,
														  const std::vector<Abstract::Position> &positions) {
  using Abstract::Position;
  for (Position pos : positions) {
	if (!inMap(pos.x, pos.y))
	  return;

	if (isAnybodyAtCell(pos.x, pos.y)) {
	  std::shared_ptr<ICharacter> character = getCharacterByPosition(pos);
	  assert(character != nullptr);

	  punch(actingCharacter, character, false);
	  if (character->isDead())
		handleDeath(character);

	} else if (!isVacantCell(pos.x, pos.y)) {
	  return;
	}
  }
}

std::vector<GameModel::Abstract::Position> GameModel::Map::WorldManipulator::generateCellsRayByMask(Abstract::Position startPos,
																									int range,
																									int xMask,
																									int yMask) {
  using Abstract::Position;

  std::vector<Position> positions;
  for (int i = 1; i <= range; i++) {
	positions.emplace_back(startPos.x + xMask * i, startPos.y + yMask * i);
  }

  return positions;
}

std::vector<GameModel::Abstract::MapEntityWithPosition> GameModel::Map::WorldManipulator::visible_cells() const noexcept {
  using Abstract::MapEntityWithPosition;
  using Abstract::Position;

  std::vector<Abstract::MapEntityWithPosition> ans;
  for (size_t y = 0; y < world->map.front().size(); y++) {
	for (size_t x = 0; x < world->map.size(); x++) {
	  ans.push_back(MapEntityWithPosition{.pos = Position(x, y), .map_entity = world->map[x][y]});
	}
  }

  return ans;


//    auto visible = vector<vector<bool>>(radius * 2 + 1, vector<bool>(radius * 2 + 1, false));
//    int x = pos.x;
//    int y = pos.y;
//
//    int radius_x_pos = min(radius, (int)map.size() - 1 - x);
//    int radius_x_neg = min(radius, x);
//    int radius_y_pos = min(radius, (int)map.front().size() - 1 - y);
//    int radius_y_neg = min(radius, y);
//
//    vector<pair<int, int>> directions = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
//    for (auto direction : directions) {
//        int radius_x = (direction.first > 0)? radius_x_pos : radius_x_neg;
//        int radius_y = (direction.second > 0)? radius_y_pos : radius_y_neg;
//
//        if (radius_x > 0) {
//            int i = radius_x * direction.first;
//            for (int j = 0; abs(j) <= radius_y; j += direction.second) {
//                float del = abs((float)j/i);
//                int dx = direction.first;
//                int dy = 0;
//                while (abs(dx) <= radius_x && abs(dy) <= radius_y) {
//                    if (view_blockers.find(map[x + dx][y + dy]) == view_blockers.end()) {
//                        visible[radius + dx][radius + dy] = true;
//                        if (abs((float)dy/dx) >= del) {
//                            dx += direction.first;
//                        } else {
//                            dy += direction.second;
//                        }
//                    } else {
//                        visible[radius + dx][radius + dy] = true;
//                        break;
//                    }
//                }
//            }
//        }
//
//        if (radius_y > 0) {
//            int i = radius_y * direction.second;
//            for (int j = 0; abs(j) <= radius_x; j += direction.first) {
//                float del = abs((float)j/i);
//                int dx = 0;
//                int dy = direction.second;
//                while (abs(dx) <= radius_x && abs(dy) <= radius_y) {
//                    if (view_blockers.find(map[x + dx][y + dy]) == view_blockers.end()) {
//                        visible[radius + dx][radius + dy] = true;
//                        if (abs((float)dx/dy) >= del) {
//                            dy += direction.second;
//                        } else {
//                            dx += direction.first;
//                        }
//                    } else {
//                        visible[radius + dx][radius + dy] = true;
//                        break;
//                    }
//                }
//            }
//        }
//    }
//
//    auto door_pos = MapEntityWithPosition{
//            .pos = Position(map.size()-1, map.front().size()-1),
//            .map_entity = MapEntity::DOOR,
//    };
//
//    auto own_pos = MapEntityWithPosition{
//            .pos = pos,
//            .map_entity = map[pos.x][pos.y],
//    };
//
//    vector<MapEntityWithPosition> ans;
//    ans.push_back(own_pos);
//    ans.push_back(door_pos);
//
//    for (int i = radius - radius_x_neg; i <= radius + radius_x_pos; i++) {
//        for (int j = radius - radius_y_neg; j <= radius + radius_y_pos; j++) {
//            if (visible[i][j]) {
//                Position pos = Position(i - radius + x, j - radius + y);
//                if (pos == door_pos.pos) continue;
//                ans.push_back(MapEntityWithPosition {
//                        .pos = pos,
//                        .map_entity = map[i - radius + x][j - radius + y]
//                });
//            }
//        }
//    }
//
//    // old simple version
//    // vector<MapEntityWithPosition> ans;
//    // for (size_t y = 0; y < map.front().size(); y++) {
//    //     for (size_t x = 0; x < map.size(); x++) {
//    //         ans.push_back(MapEntityWithPosition{ .pos = Position(x, y), .map_entity = map[x][y] });
//    //     }
//    // }
//
//    // if area is empty - no limits for it
//    if (area.size() == 0) {
//        return ans;
//    }
//    // TODO update with area
//
//    // TODO update with characters visibility radius
//
//    return ans;




}

std::shared_ptr<GameModel::ICharacter> GameModel::Map::WorldManipulator::getCharacterByPosition(GameModel::Abstract::Position pos) const {
  if (world->person->get_position() == pos) {
	return world->person;
  }

  auto e = std::find_if(world->enemies.begin(), world->enemies.end(), [pos](auto e) {
	return e->get_position() == pos;
  });

  if (e != world->enemies.end())
	return *e;

  return nullptr;
}

void GameModel::Map::WorldManipulator::handleDeath(std::shared_ptr<ICharacter> deadCharacter) {
  assert(deadCharacter->isDead());
  assert(itemGenerator != nullptr);

  auto person = std::dynamic_pointer_cast<Person>(deadCharacter);
  auto pos = deadCharacter->get_position();
  world->map[pos.x][pos.y] = getCellType(pos);
  if (person == nullptr) {
	std::shared_ptr<IItem> item = itemGenerator->generate();
	if (item != nullptr) {
	  world->items.insert({pos, item});
	  world->map[pos.x][pos.y] = item->getMapEntity();
	}
  }
}

GameModel::Map::WorldManipulator::WorldManipulator(std::shared_ptr<World> newWorld,
												   int level,
												   std::shared_ptr<Generation::ItemGenerator> newGenerator) : world(
	newWorld), level(level), itemGenerator(newGenerator) {}

void GameModel::Map::WorldManipulator::enemiesAct() {
  for (auto enemy : world->enemies) {
	auto enemyPtr = std::dynamic_pointer_cast<IEnemy>(enemy);
	assert(enemy != nullptr);

	std::vector<Abstract::MapEntityWithPosition> cells = visible_cells();
	CharacterAction enemyAction = enemyPtr->strategy(cells, enemyPtr->get_position());
	act(enemyAction, enemy);
  }
}

GameModel::Map::MapInfo GameModel::Map::WorldManipulator::getMapInfo() {
  std::vector<Abstract::MapEntityWithPosition> map_positions = visible_cells(/*person_with_position.pos, radius*/);
  return MapInfo(map_positions, world->person, world->map_options);
}

bool GameModel::Map::WorldManipulator::actPersonInternal(GameModel::CharacterAction action,
														 std::shared_ptr<ICharacter> character) {
  auto person = std::dynamic_pointer_cast<Person>(world->person);
  assert(person != nullptr);
  bool acted = false;

  switch (action) {
  case CharacterAction::POTION_1: person->potion(0);
	acted = true;
	break;
  case CharacterAction::POTION_2: person->potion(1);
	acted = true;
	break;
  case CharacterAction::POTION_3: person->potion(2);
	acted = true;
	break;
  case CharacterAction::POTION_4: person->potion(3);
	acted = true;
	break;
  case CharacterAction::POTION_5: person->potion(4);
	acted = true;
	break;
  case CharacterAction::CHANGE_WEAPON: acted = person->change_weapon();
	break;
  case CharacterAction::CHANGE_ITEM: {
	if (world->items.find(character->get_position()) == world->items.end()) {
	  break;
	}

	assert(world->items[character->get_position()] != nullptr);
	auto oldItem = person->take_item(world->items[character->get_position()]);
	if (oldItem == nullptr)
	  world->items.erase(character->get_position());
	else
	  world->items[character->get_position()] = oldItem;
  }
	break;
  default: acted = false;
	break;
  }
  return acted;
}

void GameModel::Map::WorldManipulator::clearDeadEnemies() {
  std::vector<std::shared_ptr<IEnemy>> oldEnemies = std::move(world->enemies);
  world->enemies = std::vector<std::shared_ptr<IEnemy>>();

  std::copy_if(oldEnemies.begin(),
			   oldEnemies.end(),
			   std::back_inserter(world->enemies),
			   [](auto enemy) { return !enemy->isDead(); });

  assert(std::all_of(world->enemies.begin(), world->enemies.end(), [](auto e) { return !e->isDead(); }));
}
