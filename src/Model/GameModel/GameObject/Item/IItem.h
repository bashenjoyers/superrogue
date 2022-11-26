#pragma once
#include "Model/GameModel/GameObject/IGameObject.h"

namespace GameModel {
/**
 * @brief the base class for the item
 * 
 */
class IItem : public IGameObject {
public:
  /**
   * @brief creates an item by standard fields IGameObject
   * 
   */
  IItem(std::string name, std::string description,
        Characteristics characteristics);
  IItem() : IGameObject(){};
  virtual ~IItem() {}
};
}; // namespace GameModel
