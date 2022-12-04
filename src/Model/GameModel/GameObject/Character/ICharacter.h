#pragma once
#include "Model/GameModel/GameObject/IGameObject.h"
#include "Model/GameModel/abstract.h"
#include <iostream>
#include <string>
#include <memory>
#include <vector>

namespace GameModel {
/**
 * @brief interface for any character
 * 
 */
class ICharacter : public IGameObject {
public:
  // returns an overridden empty description (nothing is known about the abstract character)
  virtual std::string get_description() const noexcept override { return ""; };
  // determines the action on step
  virtual void step(){};
  // determines the action on punch
  virtual void punch(){};
  virtual Abstract::MapEntity get_map_entity() const noexcept = 0;
  // creates an instance according to the standard properties of the object
  ICharacter(std::string name, std::string description,
             Characteristics characteristics);
  ICharacter(){};
  virtual ~ICharacter() {}
};

/**
 * @brief interface for anything that has a position
 *
 */
struct WithPosition {
    Abstract::Position pos;
    virtual ~WithPosition(){};
};

/**
* @brief Class containing character and position
*
*/
struct CharacterWithPosition: WithPosition {
    std::shared_ptr<ICharacter> character;
    std::vector<Abstract::Position> area; // where Enemy can be
    CharacterWithPosition(std::shared_ptr<ICharacter> character) : character(character) {};
    CharacterWithPosition() = default;
    virtual ~CharacterWithPosition(){};
};

}; // namespace GameModel

