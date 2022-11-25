#include "IEnemyClass.h"
#include <algorithm>

using std::find;
using std::string;
using std::vector;

namespace GameModel {
using namespace Abstract;

IEnemyClass::IEnemyClass(string description, EnemySettings settings)
    : ICharacterClass(description), settings(settings) {}

EnemySettings IEnemyClass::get_settings() const noexcept { return settings; }

bool IEnemyClass::is_vacant(Abstract::MapEntity map_entity) const noexcept {
  return map_entity == MapEntity::FLOOR || map_entity == MapEntity::ITEM ||
         map_entity == MapEntity::POTION;
}

CharacterAction IEnemyClass::default_fight_behavior(
    int dx, int dy, vector<CharacterAction> &possible_actions,
    bool can_punch) const noexcept {
  if (abs(dx) <= abs(dy)) {
    if (dx == 0) {
      if (dy > 0) {
        if (dy <= get_settings().attack_range && can_punch) {
          if (settings.intellect > INTELLECT_STEP_PUNCH_K && find(possible_actions.begin(), possible_actions.end(), CharacterAction::STEP_BACK) != possible_actions.end())
            return CharacterAction::STEP_BACK;
          return CharacterAction::PUNCH_BACK;
        } else {
          if (find(possible_actions.begin(), possible_actions.end(),
                   CharacterAction::STEP_BACK) != possible_actions.end()) {
            return CharacterAction::STEP_BACK;
          } else if (find(possible_actions.begin(), possible_actions.end(),
                          CharacterAction::STEP_RIGHT) !=
                     possible_actions.end()) {
            return CharacterAction::STEP_RIGHT;
          } else if (find(possible_actions.begin(), possible_actions.end(),
                          CharacterAction::STEP_LEFT) !=
                     possible_actions.end()) {
            return CharacterAction::STEP_LEFT;
          } else {
            return CharacterAction::WAIT;
          }
        }
      } else {
        if (-dy <= get_settings().attack_range && can_punch) {
          if (settings.intellect > INTELLECT_STEP_PUNCH_K && find(possible_actions.begin(), possible_actions.end(), CharacterAction::STEP_FORWARD) != possible_actions.end())
            return CharacterAction::STEP_FORWARD;
          return CharacterAction::PUNCH_FORWARD;
        } else {
          if (find(possible_actions.begin(), possible_actions.end(),
                   CharacterAction::STEP_FORWARD) != possible_actions.end()) {
            return CharacterAction::STEP_FORWARD;
          } else if (find(possible_actions.begin(), possible_actions.end(),
                          CharacterAction::STEP_LEFT) !=
                     possible_actions.end()) {
            return CharacterAction::STEP_LEFT;
          } else if (find(possible_actions.begin(), possible_actions.end(),
                          CharacterAction::STEP_RIGHT) !=
                     possible_actions.end()) {
            return CharacterAction::STEP_RIGHT;
          } else {
            return CharacterAction::WAIT;
          }
        }
      }
    } else {
      if (dy > 0) {
        if (find(possible_actions.begin(), possible_actions.end(),
                 CharacterAction::STEP_BACK) != possible_actions.end()) {
          return CharacterAction::STEP_BACK;
        } else if (dx > 0 &&
                   find(possible_actions.begin(), possible_actions.end(),
                        CharacterAction::STEP_RIGHT) !=
                       possible_actions.end()) {
          return CharacterAction::STEP_RIGHT;
        } else if (dx < 0 &&
                   find(possible_actions.begin(), possible_actions.end(),
                        CharacterAction::STEP_LEFT) != possible_actions.end()) {
          return CharacterAction::STEP_LEFT;
        } else {
          return CharacterAction::WAIT;
        }
      } else {
        if (find(possible_actions.begin(), possible_actions.end(),
                 CharacterAction::STEP_FORWARD) != possible_actions.end()) {
          return CharacterAction::STEP_FORWARD;
        } else if (dx > 0 &&
                   find(possible_actions.begin(), possible_actions.end(),
                        CharacterAction::STEP_RIGHT) !=
                       possible_actions.end()) {
          return CharacterAction::STEP_RIGHT;
        } else if (dx < 0 &&
                   find(possible_actions.begin(), possible_actions.end(),
                        CharacterAction::STEP_LEFT) != possible_actions.end()) {
          return CharacterAction::STEP_LEFT;
        } else {
          return CharacterAction::WAIT;
        }
      }
    }
  } else {
    if (dy == 0) {
      if (dx > 0) {
        if (dx <= get_settings().attack_range && can_punch) {
          if (settings.intellect > INTELLECT_STEP_PUNCH_K && find(possible_actions.begin(), possible_actions.end(), CharacterAction::STEP_RIGHT) != possible_actions.end())
            return CharacterAction::STEP_RIGHT;
          return CharacterAction::PUNCH_RIGHT;
        } else {
          if (find(possible_actions.begin(), possible_actions.end(),
                   CharacterAction::STEP_RIGHT) != possible_actions.end()) {
            return CharacterAction::STEP_RIGHT;
          } else if (find(possible_actions.begin(), possible_actions.end(),
                          CharacterAction::STEP_FORWARD) !=
                     possible_actions.end()) {
            return CharacterAction::STEP_FORWARD;
          } else if (find(possible_actions.begin(), possible_actions.end(),
                          CharacterAction::STEP_BACK) !=
                     possible_actions.end()) {
            return CharacterAction::STEP_BACK;
          } else {
            return CharacterAction::WAIT;
          }
        }
      } else {
        if (-dx <= get_settings().attack_range && can_punch) {
          if (settings.intellect > INTELLECT_STEP_PUNCH_K && find(possible_actions.begin(), possible_actions.end(), CharacterAction::STEP_LEFT) != possible_actions.end())
            return CharacterAction::STEP_LEFT;
          return CharacterAction::PUNCH_LEFT;
        } else {
          if (find(possible_actions.begin(), possible_actions.end(),
                   CharacterAction::STEP_LEFT) != possible_actions.end()) {
            return CharacterAction::STEP_LEFT;
          } else if (find(possible_actions.begin(), possible_actions.end(),
                          CharacterAction::STEP_BACK) !=
                     possible_actions.end()) {
            return CharacterAction::STEP_BACK;
          } else if (find(possible_actions.begin(), possible_actions.end(),
                          CharacterAction::STEP_FORWARD) !=
                     possible_actions.end()) {
            return CharacterAction::STEP_FORWARD;
          } else {
            return CharacterAction::WAIT;
          }
        }
      }
    } else {
      if (dx > 0) {
        if (find(possible_actions.begin(), possible_actions.end(),
                 CharacterAction::STEP_RIGHT) != possible_actions.end()) {
          return CharacterAction::STEP_RIGHT;
        } else if (dy > 0 &&
                   find(possible_actions.begin(), possible_actions.end(),
                        CharacterAction::STEP_BACK) !=
                       possible_actions.end()) {
          return CharacterAction::STEP_BACK;
        } else if (dy < 0 &&
                   find(possible_actions.begin(), possible_actions.end(),
                        CharacterAction::STEP_FORWARD) != possible_actions.end()) {
          return CharacterAction::STEP_FORWARD;
        } else {
          return CharacterAction::WAIT;
        }
      } else {
        if (find(possible_actions.begin(), possible_actions.end(),
                 CharacterAction::STEP_LEFT) != possible_actions.end()) {
          return CharacterAction::STEP_LEFT;
        } else if (dy > 0 &&
                   find(possible_actions.begin(), possible_actions.end(),
                        CharacterAction::STEP_BACK) !=
                       possible_actions.end()) {
          return CharacterAction::STEP_BACK;
        } else if (dy < 0 &&
                   find(possible_actions.begin(), possible_actions.end(),
                        CharacterAction::STEP_FORWARD) != possible_actions.end()) {
          return CharacterAction::STEP_FORWARD;
        } else {
          return CharacterAction::WAIT;
        }
      }
    }
  }
}

CharacterAction IEnemyClass::strategy(std::vector<MapEntityWithPosition> &cells,
                                      const Position &pos) noexcept {
  return CharacterAction::WAIT;
};
}; // namespace GameModel
