#include <cassert>
#include "WorldManipulator.h"
#include "Model/GameModel/abstract.h"
#include "Model/GameModel/GameObject/Character/IEnemy.h"
#include "Model/GameModel/GameObject/Character/Person.h"

//TODO BAGRORG get_settings() TO VIRTUAL


// TODO WHAT LOGIC BEHIND THIS?
void GameModel::Map::WorldManipulator::removeEnemy(const GameModel::CharacterWithPosition &enemyToRemove) noexcept {
  auto removedEnemy = std::dynamic_pointer_cast<IEnemy>(enemyToRemove.character);
  assert(removedEnemy != nullptr);

  if (world->enemies_with_positions.empty()) {
	return;
  }

  // If this is not enemy for remove, will return it back
  CharacterWithPosition lastEnemy = world->enemies_with_positions.back();
  world->enemies_with_positions.pop_back();
  if (removedEnemy == std::dynamic_pointer_cast<IEnemy>(lastEnemy.character)) {
	return;
  }

  for (auto &otherEnemy : world->enemies_with_positions) {
	if (removedEnemy == std::dynamic_pointer_cast<IEnemy>(otherEnemy.character)) {
	  otherEnemy = lastEnemy;
	  return;
	}
  }
}

void GameModel::Map::WorldManipulator::setWorld(std::shared_ptr<World> newWorld) {
  assert(newWorld != nullptr);
  world = newWorld;
}

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

bool GameModel::Map::WorldManipulator::moveCharacter(GameModel::CharacterWithPosition &characterWithPosition,
													 GameModel::Abstract::Position pos) noexcept {
  using Abstract::MapEntity;
  if (isDoorCell(pos.x, pos.y)) {
	if (std::dynamic_pointer_cast<Person>(characterWithPosition.character) == nullptr) {
	  // Enemy can't go in door
	  return false;
	}
  }

  world->map[characterWithPosition.pos.x][characterWithPosition.pos.y] =
	  getCellType(characterWithPosition.pos); // POGREBNOJAK FIXME(update later: mb WALL)
  world->map[pos.x][pos.y] = characterWithPosition.character->get_map_entity();
  characterWithPosition.pos = pos;
  return true;
}

bool GameModel::Map::WorldManipulator::makeAStep(GameModel::CharacterWithPosition &actingCharacter,
												 Abstract::Position newPosition) noexcept {
  if (inMap(newPosition.x, newPosition.y)) {
	if (isVacantCell(newPosition.x, newPosition.y)) {
	  return moveCharacter(actingCharacter, newPosition);
	} else if (isAnybodyAtCell(newPosition.x, newPosition.y)) {
	  CharacterWithPosition *character = getCharacterByPosition(newPosition);
	  assert(character != nullptr);

	  if (punchWhileStep(actingCharacter, *character)) {
		moveCharacter(actingCharacter, newPosition);
	  }
	  return true;
	}
  }

  return false;
}

bool GameModel::Map::WorldManipulator::act(GameModel::CharacterAction action, CharacterWithPosition &character) {
  using namespace Abstract;

  Position position = character.pos;
  bool acted = false;

  int range = character.character->getAttackRange();

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
	  character.character->step();
	  acted = true;
	}
	break;
  case CharacterAction::STEP_BACK:
	if (makeAStep(character, position + Abstract::Position{0, 1})) {
	  character.character->step();
	  acted = true;
	}
	break;
  case CharacterAction::STEP_LEFT:
	if (makeAStep(character, position + Abstract::Position{-1, 0})) {
	  character.character->step();
	  acted = true;
	}
	break;
  case CharacterAction::STEP_RIGHT:
	if (makeAStep(character, position + Abstract::Position{1, 0})) {
	  character.character->step();
	  acted = true;
	}
	break;
  default: break;
  }

  return acted;
}

// TODO METHOD?
GameModel::Characteristics getCharacteristicsForPunch(GameModel::CharacterWithPosition &characterWithPosition) {
  auto character = characterWithPosition.character;
  if (auto person = std::dynamic_pointer_cast<GameModel::Person>(character); person != nullptr) {
	return person->get_full_characteristics();
  }

  return character->get_characteristics();
}

void GameModel::Map::WorldManipulator::punch(CharacterWithPosition &puncher,
											 CharacterWithPosition &punchee,
											 bool ignoreArmor) noexcept {
  puncher.character->punch();        // TODO BAGRORG RIGHT ORDER OF EXECUTION?
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
	damage = std::max(damage - puncherChar.armor, DEFENCE_DEFAULT_DAMAGE * level);
  }

  punchee.character->takeDamage(damage);
}

bool GameModel::Map::WorldManipulator::punchWhileStep(CharacterWithPosition &walking,
													  CharacterWithPosition &standing) noexcept {
  // TODO BAGRORG OK WITH ORDER?
  punch(walking, standing, true);
  if (standing.character->isDead()) {
	handleDeath(standing);
	return true;
  }

  punch(standing, walking, true);
  if (walking.character->isDead())
	handleDeath(walking);

  return false;
}

void GameModel::Map::WorldManipulator::orientedCellsPunch(CharacterWithPosition &actingCharacter,
														  const std::vector<Abstract::Position> &positions) {
  using Abstract::Position;
  for (Position pos : positions) {
	if (!inMap(pos.x, pos.y))
	  return;

	if (isAnybodyAtCell(pos.x, pos.y)) {
	  CharacterWithPosition *character = getCharacterByPosition(pos);
	  assert(character != nullptr);

	  punch(actingCharacter, *character, false);
	  if (character->character->isDead())
		handleDeath(*character);

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

void GameModel::Map::WorldManipulator::setLevel(int newLevel) {
  level = newLevel;
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
}

GameModel::CharacterWithPosition *GameModel::Map::WorldManipulator::getCharacterByPosition(GameModel::Abstract::Position pos) {
  if (world->person_with_position.pos == pos) {
	return &world->person_with_position;
  }

  for (CharacterWithPosition &enemy : world->enemies_with_positions) {
	if (enemy.pos == pos)
	  return &enemy;
  }

  return nullptr;
}

void GameModel::Map::WorldManipulator::handleDeath(GameModel::CharacterWithPosition &deadCharacter) {
  assert(deadCharacter.character->isDead());
  assert(itemGenerator != nullptr);

  auto person = std::dynamic_pointer_cast<Person>(deadCharacter.character);
  world->map[deadCharacter.pos.x][deadCharacter.pos.y] = getCellType(deadCharacter.pos);
  if (person == nullptr) {
	std::shared_ptr<IItem> item = itemGenerator->generate();
	if (item != nullptr) {
	  world->items.insert({deadCharacter.pos, item});
	  world->map[deadCharacter.pos.x][deadCharacter.pos.y] = item->getMapEntity();
	}
	removeEnemy(deadCharacter);
  }
}

void GameModel::Map::WorldManipulator::setItemGenerator(std::shared_ptr<Generation::ItemGenerator> newGenerator) {
  assert(newGenerator != nullptr);
  itemGenerator = newGenerator;
}
GameModel::Map::WorldManipulator::WorldManipulator(std::shared_ptr<World> newWorld,
												   int level,
												   std::shared_ptr<Generation::ItemGenerator> newGenerator) {
  setWorld(newWorld);
  setLevel(level);
  setItemGenerator(newGenerator);
}

void GameModel::Map::WorldManipulator::enemiesAct() {
  for (CharacterWithPosition &enemyWithPosition : world->enemies_with_positions) {
	auto enemy = std::dynamic_pointer_cast<IEnemy>(enemyWithPosition.character);
	assert(enemy != nullptr);

	std::vector<Abstract::MapEntityWithPosition> cells = visible_cells();
	CharacterAction enemyAction = enemy->strategy(cells, enemyWithPosition.pos);
	act(enemyAction, enemyWithPosition);
  }
}
GameModel::Map::MapInfo GameModel::Map::WorldManipulator::getMapInfo() {
  std::vector<Abstract::MapEntityWithPosition> map_positions = visible_cells(/*person_with_position.pos, radius*/);
  return MapInfo(map_positions, world->person_with_position, world->map_options);
}
bool GameModel::Map::WorldManipulator::actPersonInternal(GameModel::CharacterAction action,
														 GameModel::CharacterWithPosition &character) {
  auto person = std::dynamic_pointer_cast<Person>(world->person_with_position.character);
  assert(person != nullptr);

  switch (action) {
  case CharacterAction::POTION_1: person->potion(0);
	return true;
  case CharacterAction::POTION_2: person->potion(1);
	return true;
  case CharacterAction::POTION_3: person->potion(2);
	return true;
  case CharacterAction::POTION_4: person->potion(3);
	return true;
  case CharacterAction::POTION_5: person->potion(4);
	return true;
  case CharacterAction::CHANGE_WEAPON: return person->change_weapon();
  case CharacterAction::CHANGE_ITEM: {
	assert(world->items[character.pos] != nullptr);
	auto oldItem = person->take_item(world->items[character.pos]);
	if (oldItem == nullptr) world->items.erase(character.pos);
	else world->items[character.pos] = oldItem;
  }
  default: return false;
  }
  return false;
}
