#pragma once
#include <vector>
#include <optional>
#include "Model/GameModel/GameObject/Character/CharacterAction.h"
#include "Model/GameModel/abstract.h"


namespace GameModel {
/**
 * @brief The environment of the character based on which he performs actions
 * possible_actions - actions, that he can in current moment (does not include punches, they are calculated according to the respective directions)
 * smb_pos - the position of the one you want to attack / run from (usually the position of the character)
 * own_pos - current position
 */
struct EnemyEnvironmentInfo {
  std::vector<CharacterAction> possible_actions = {CharacterAction::WAIT};
  std::optional<Abstract::Position> smb_pos = std::nullopt;
  Abstract::Position own_pos;
};
}
