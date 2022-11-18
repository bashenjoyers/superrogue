#pragma once
#include "Model/Exceptions/exceptions.h"

namespace GameModel {
enum class CharacterAction {
  STEP_FORWARD,
  STEP_RIGHT,
  STEP_BACK,
  STEP_LEFT,
  PUNCH_FORWARD,
  PUNCH_RIGHT,
  PUNCH_BACK,
  PUNCH_LEFT,
  POTION_1,
  POTION_2,
  POTION_3,
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
  case CharacterAction::POTION_1:
    return "potion1";
  case CharacterAction::POTION_2:
    return "potion2";
  case CharacterAction::POTION_3:
    return "potion3";
  case CharacterAction::CHANGE_ITEM:
    return "change Item";
  case CharacterAction::WAIT:
    return "wait";
  default:
    throw GameObjectException("wrong CharacterAction");
  }
}
}; // namespace GameModel
