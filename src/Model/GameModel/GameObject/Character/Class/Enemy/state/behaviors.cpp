#include "Model/GameModel/GameObject/Character/Class/Enemy/state/behaviors.h"
#include "Model/GameModel/const.h"
#include "Model/GameModel/values.h"

using std::vector;


namespace GameModel {
CharacterAction default_fight_behavior(
    int dx, int dy, vector<CharacterAction> &possible_actions,
    EnemySettings settings,
    bool can_punch) {
  if (abs(dx) <= abs(dy)) {
    if (dx == 0) {
      if (dy > 0) {
        if (dy <= settings.attack_range && can_punch) {
          if (settings.intellect > INTELLECT_STEP_PUNCH_K && dy == 1)
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
        if (-dy <= settings.attack_range && can_punch) {
          if (settings.intellect > INTELLECT_STEP_PUNCH_K && -dy == 1)
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
        if (dx <= settings.attack_range && can_punch) {
          if (settings.intellect > INTELLECT_STEP_PUNCH_K && dx == 1)
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
        if (-dx <= settings.attack_range && can_punch) {
          if (settings.intellect > INTELLECT_STEP_PUNCH_K && -dx == 1)
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

CharacterAction walk_behavior(vector<CharacterAction> &possible_actions) {
    std::uniform_int_distribution<int> position_gen(0, possible_actions.size() - 1);
    return possible_actions[position_gen(Values::generator)];
}

CharacterAction wait_behavior() {
    return CharacterAction::WAIT;
}

CharacterAction coward_behavior(int dx, int dy, vector<CharacterAction> &possible_actions, EnemySettings settings) {
    return default_fight_behavior(-dx, -dy, possible_actions, settings, false);
}
}
