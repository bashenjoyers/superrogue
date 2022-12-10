#include <cassert>
#include "WorldManipulator.h"
#include "Model/GameModel/abstract.h"
#include "Model/GameModel/GameObject/Character/Enemy.h"
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
	  map_entity == MapEntity::ENEMY_TRAVELER ||
      map_entity == MapEntity::ENEMY_REPLICATOR;
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

  int range = character->get_attack_range();

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

  if (damage != 0)
  	punchee->take_damage(damage);
}

bool GameModel::Map::WorldManipulator::punchWhileStep(std::shared_ptr<ICharacter> walking,
													  std::shared_ptr<ICharacter> standing) noexcept {
  // TODO BAGRORG OK WITH ORDER?
  assert((std::abs(walking->get_position().x - standing->get_position().x) <= 1
	  && walking->get_position().y == standing->get_position().y) ||
	  (std::abs(walking->get_position().y - standing->get_position().y) <= 1
		  && walking->get_position().x == standing->get_position().x));

  punch(walking, standing, true);
  if (standing->is_dead()) {
	handleDeath(standing);
	return true;
  }

  punch(standing, walking, true);

  if (walking->is_dead()) {
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
	  if (character->is_dead())
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

std::vector<GameModel::Abstract::MapEntityWithPosition> GameModel::Map::WorldManipulator::visible_cells(const Abstract::Position& pos, int radius, bool ignore_walls, const Area& area) {
	visibility_builder.set_pos(pos);
	visibility_builder.set_radius(radius);
	visibility_builder.set_ignore_walls(ignore_walls);
	visibility_builder.set_area(area);
	visibility_builder.set_world(world);
	auto res = visibility_builder.build();
	visibility_builder.reset();
	return res;
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
  assert(deadCharacter->is_dead());
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
	clearDeadEnemies();
  } else {
	world->map[pos.x][pos.y] = Abstract::MapEntity::FLOOR;
  }
}

GameModel::Map::WorldManipulator::WorldManipulator(std::shared_ptr<World> newWorld,
												   int level,
												   std::shared_ptr<Generation::ItemGenerator> newGenerator) : world(
	newWorld), level(level), itemGenerator(newGenerator), visibility_builder(VisibilityBuilder()) {}

void GameModel::Map::WorldManipulator::enemiesAct() {
  auto enemies(world->enemies);
  std::vector<std::shared_ptr<Enemy>> replicatedEnemies;
  for (const auto& enemy : enemies) {
	Abstract::Position startPosition = enemy->get_position();
	if (enemy->is_dead())
		continue;

	auto enemy_settings = enemy->get_settings();
	std::vector<Abstract::MapEntityWithPosition> cells = visible_cells(startPosition, enemy_settings.visible_radius, enemy_settings.ignore_walls, enemy_settings.area);
	CharacterAction enemyAction = enemy->strategy(cells, startPosition);
	act(enemyAction, enemy);

	if (is_step(enemyAction)) { 
		if (auto r = enemy->replicate(); r != nullptr) {
		r->set_position(startPosition);
		world->map[startPosition.x][startPosition.y] = r->get_map_entity();
		replicatedEnemies.push_back(r);
		}
	}
  }

  for (const auto& r: replicatedEnemies) world->enemies.push_back(r);
}

GameModel::Map::MapInfo GameModel::Map::WorldManipulator::getMapInfo() {
  std::vector<Abstract::MapEntityWithPosition> map_positions = visible_cells(world->person->get_position(), world->person->get_settings().visible_radius);
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
  std::vector<std::shared_ptr<Enemy>> oldEnemies = std::move(world->enemies);
  world->enemies = std::vector<std::shared_ptr<Enemy>>();

  std::copy_if(oldEnemies.begin(),
			   oldEnemies.end(),
			   std::back_inserter(world->enemies),
			   [](auto enemy) { return !enemy->is_dead(); });

  assert(std::all_of(world->enemies.begin(), world->enemies.end(), [](auto e) { return !e->is_dead(); }));
}
