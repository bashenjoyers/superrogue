#pragma once
#include "Model/GameModel/GameObject/IGameObject.h"

namespace GameModel {
class IItem : public IGameObject {
public:
  IItem(std::string name, std::string description,
        Characteristics characteristics);
  IItem() : IGameObject(){};
  virtual ~IItem() {}
};
}; // namespace superrogue::GameObject::Item
