#pragma once

#include "Model/GameModel/Map/World.h"
#include "Model/GameModel/GameObject/Item/Generation/ItemGenerator.h"

namespace GameModel::Map {

class WorldManipulator {
public:
  WorldManipulator(std::shared_ptr<World> newWorld, int level, std::shared_ptr<Generation::ItemGenerator> newGenerator);

  void setWorld(std::shared_ptr<World> newWorld);
  void setLevel(int newLevel);	// TODO LEVEL IN WORLD?
  void setItemGenerator(std::shared_ptr<Generation::ItemGenerator> newGenerator);		// TODO TO CONSTRUCTOR?

  bool inMap(int x, int y) const noexcept;
  bool isVacantCell(int x, int y) const noexcept;
  bool isDoorCell(int x, int y) const noexcept;
  bool isAnybodyAtCell(int x, int y) const noexcept;
  Abstract::MapEntity getCellType(const Abstract::Position &pos) const noexcept;
  std::vector<Abstract::MapEntityWithPosition>
  visible_cells(/*const Abstract::Position &pos, int radius, bool ignore_walls,
				const std::vector<Abstract::Position> &area*/) const noexcept;

  bool moveCharacter(CharacterWithPosition &anybody, Abstract::Position pos) noexcept;
  bool makeAStep(GameModel::CharacterWithPosition &actingCharacter,
				 Abstract::Position newPosition) noexcept;
  bool act(GameModel::CharacterAction action, CharacterWithPosition &character);
  bool actPersonInternal(GameModel::CharacterAction action, CharacterWithPosition &character);
  void enemiesAct();
  void punch(CharacterWithPosition &puncher, CharacterWithPosition &punchee, bool ignoreArmor) noexcept;
  bool punchWhileStep(CharacterWithPosition &walking, CharacterWithPosition &standing) noexcept;
  void removeEnemy(const CharacterWithPosition &enemyToRemove) noexcept;

  MapInfo getMapInfo();
private:
  void orientedCellsPunch(CharacterWithPosition &actingCharacter, const std::vector<Abstract::Position> &positions);
  std::vector<GameModel::Abstract::Position> generateCellsRayByMask(Abstract::Position startPos,
																	int range,
																	int xMask,
																	int yMask);
  CharacterWithPosition *getCharacterByPosition(Abstract::Position pos);
  void handleDeath(CharacterWithPosition &deadCharacter);

  std::shared_ptr<World> world;
  std::shared_ptr<Generation::ItemGenerator> itemGenerator;
  int level;
};

}
