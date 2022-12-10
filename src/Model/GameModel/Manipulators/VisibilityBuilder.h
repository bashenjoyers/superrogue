#pragma once
#include <vector>
#include "Model/GameModel/abstract.h"
#include "Model/GameModel/GameObject/Character/Class/Enemy/state/helpers.h"
#include "Model/GameModel/Map/World.h"


namespace GameModel::Map {
class VisibilityBuilder {
public:
  /**
   * @brief Map builder constructor
   */
  VisibilityBuilder();

  /**
   * @brief reset all settings
   */
  void reset() noexcept;

  /**
   * @brief set persion position
   * @param pos
   */
  void set_pos(const Abstract::Position& pos) noexcept;

  /**
   * @brief set persion visible radius
   * @param radius
   */
  void set_radius(int radius) noexcept;

  /**
   * @brief set if persion can ignore walls
   * @param ignore_walls  //false
   */
  void set_ignore_walls(bool ignore_walls) noexcept;

  /**
   * @brief set area in which person could be
   * @param ignore_walls  //false
   */
  void set_area(const Area& area) noexcept;

   /**
   * @brief set area in which person could be
   * @param ignore_walls  //false
   */
  void set_world(std::shared_ptr<World> world) noexcept;
  
  /**
   * @brief hard visibility algorithm
   * @return std::vector<GameModel::Abstract::MapEntityWithPosition> of visible cells
   */
  std::vector<GameModel::Abstract::MapEntityWithPosition> build() const;
private:
  std::optional<Abstract::Position> pos = std::nullopt;
  int radius = DEFAULT_VISIBLE_RADIUS;
  bool ignore_walls = false;
  Area area = Area();
  std::shared_ptr<World> world = nullptr;
};
}
