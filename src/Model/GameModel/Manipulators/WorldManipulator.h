#pragma once

#include "Model/GameModel/Map/World.h"
#include "Model/GameModel/GameObject/Item/Generation/ItemGenerator.h"

namespace GameModel::Map {

class WorldManipulator {
public:
  WorldManipulator(std::shared_ptr<World> newWorld, int level, std::shared_ptr<Generation::ItemGenerator> newGenerator);

  void setWorld(std::shared_ptr<World> newWorld);
  void setLevel(int newLevel);    // TODO LEVEL IN WORLD?
  void setItemGenerator(std::shared_ptr<Generation::ItemGenerator> newGenerator);        // TODO TO CONSTRUCTOR?

  bool inMap(int x, int y) const noexcept;
  bool isVacantCell(int x, int y) const noexcept;
  bool isDoorCell(int x, int y) const noexcept;
  bool isAnybodyAtCell(int x, int y) const noexcept;
  Abstract::MapEntity getCellType(const Abstract::Position &pos) const noexcept;
  std::vector<Abstract::MapEntityWithPosition> visible_cells(/*const Abstract::Position &pos, int radius, bool ignore_walls,
				const std::vector<Abstract::Position> &area*/) const noexcept;

  bool moveCharacter(std::shared_ptr<ICharacter> anybody, Abstract::Position pos) noexcept;
  bool makeAStep(std::shared_ptr<ICharacter> actingCharacter,
				 Abstract::Position newPosition) noexcept;
  bool act(GameModel::CharacterAction action, std::shared_ptr<ICharacter> character);
  bool actPersonInternal(GameModel::CharacterAction action, std::shared_ptr<ICharacter> character);
  void enemiesAct();
  void punch(std::shared_ptr<ICharacter> puncher, std::shared_ptr<ICharacter> punchee, bool ignoreArmor) noexcept;
  bool punchWhileStep(std::shared_ptr<ICharacter> walking, std::shared_ptr<ICharacter> standing) noexcept;

  MapInfo getMapInfo();
  void clearDeadEnemies();
private:
  void orientedCellsPunch(std::shared_ptr<ICharacter> actingCharacter,
						  const std::vector<Abstract::Position> &positions);
  std::vector<GameModel::Abstract::Position> generateCellsRayByMask(Abstract::Position startPos,
																	int range,
																	int xMask,
																	int yMask);
  std::shared_ptr<ICharacter> getCharacterByPosition(Abstract::Position pos) const;
  void handleDeath(std::shared_ptr<ICharacter> deadCharacter);

  std::shared_ptr<World> world;
  std::shared_ptr<Generation::ItemGenerator> itemGenerator;
  int level;
};

}
