#pragma once
#include "exceptions/exceptions.h"

namespace superrogue::game_object::character {
enum class CharacterAction {
  STEP_FORWARD,
  STEP_RIGHT,
  STEP_BACK,
  STEP_LEFT,
  PUNCH_FORWARD,
  PUNCH_RIGHT,
  PUNCH_BACK,
  PUNCH_LEFT,
  POTION,
  CHANGE_ITEM,
  WAIT,
};

inline const std::string to_string(CharacterAction action) {
  switch (action) {
  case CharacterAction::STEP_FORWARD:
    return "step forward";
  case CharacterAction::STEP_RIGHT:
    return "step right";
  case CharacterAction::STEP_BACK:
    return "step back";
  case CharacterAction::STEP_LEFT:
    return "step left";
  case CharacterAction::PUNCH_FORWARD:
    return "punch forward";
  case CharacterAction::PUNCH_RIGHT:
    return "punch right";
  case CharacterAction::PUNCH_BACK:
    return "punch back";
  case CharacterAction::PUNCH_LEFT:
    return "punch left";
  case CharacterAction::POTION:
    return "potion";
  case CharacterAction::CHANGE_ITEM:
    return "change item";
  case CharacterAction::WAIT:
    return "wait";
  default:
    throw superrogue::exception::GameObjectException("wrong CharacterAction");
  }
}
}; // namespace superrogue::game_object::character
