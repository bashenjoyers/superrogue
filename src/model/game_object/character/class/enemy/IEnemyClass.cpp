#include "model/game_object/character/class/enemy/IEnemyClass.h"
#include <algorithm>

using std::find;
using std::string;
using std::vector;
using superrogue::game_object::character::CharacterAction;
using superrogue::abstract::MapEntityWithPosition;
using superrogue::abstract::Position;
using superrogue::abstract::MapEntity;


namespace superrogue::game_object::character {
IEnemyClass::IEnemyClass(string description, EnemySettings settings) noexcept : ICharacterClass(description), __settings(settings) {}

EnemySettings IEnemyClass::get_settings() const noexcept { 
    return __settings;
}

bool IEnemyClass::is_vacant(superrogue::abstract::MapEntity map_entity) {
    return map_entity == MapEntity::FLOOR || map_entity == MapEntity::ITEM || map_entity == MapEntity::POTION;
}

CharacterAction IEnemyClass::default_fight_behavior(int dx, int dy, vector<CharacterAction>& possible_actions, bool can_punch) {    // FIXME(do it adequately)
    if (dx <= dy) {
        if (dx == 0) {
            if (dy > 0) {
                if (dy <= get_settings().attack_range && can_punch) {
                    return CharacterAction::PUNCH_RIGHT;
                } else {
                    if(find(possible_actions.begin(), possible_actions.end(), CharacterAction::STEP_RIGHT) != possible_actions.end()) {
                        return CharacterAction::STEP_RIGHT;
                    } else if(find(possible_actions.begin(), possible_actions.end(), CharacterAction::STEP_FORWARD) != possible_actions.end()) {
                        return CharacterAction::STEP_FORWARD;
                    } else if(find(possible_actions.begin(), possible_actions.end(), CharacterAction::STEP_BACK) != possible_actions.end()) {
                        return CharacterAction::STEP_BACK;
                    } else {
                        return CharacterAction::WAIT;
                    }
                }
            } else {
                if (-dy <= get_settings().attack_range && can_punch) {
                    return CharacterAction::PUNCH_LEFT;
                } else {
                    if(find(possible_actions.begin(), possible_actions.end(), CharacterAction::STEP_LEFT) != possible_actions.end()) {
                        return CharacterAction::STEP_LEFT;
                    } else if(find(possible_actions.begin(), possible_actions.end(), CharacterAction::STEP_BACK) != possible_actions.end()) {
                        return CharacterAction::STEP_BACK;
                    } else if(find(possible_actions.begin(), possible_actions.end(), CharacterAction::STEP_FORWARD) != possible_actions.end()) {
                        return CharacterAction::STEP_FORWARD;
                    } else {
                        return CharacterAction::WAIT;
                    }
                }
            }
        } else {
            if (dy > 0) {
                if(find(possible_actions.begin(), possible_actions.end(), CharacterAction::STEP_RIGHT) != possible_actions.end()) {
                    return CharacterAction::STEP_RIGHT;
                } else if(dx > 0 && find(possible_actions.begin(), possible_actions.end(), CharacterAction::STEP_FORWARD) != possible_actions.end()) {
                    return CharacterAction::STEP_FORWARD;
                } else if(dx < 0 && find(possible_actions.begin(), possible_actions.end(), CharacterAction::STEP_BACK) != possible_actions.end()) {
                    return CharacterAction::STEP_BACK;
                } else {
                    return CharacterAction::WAIT;
                }
            } else {
                if(find(possible_actions.begin(), possible_actions.end(), CharacterAction::STEP_LEFT) != possible_actions.end()) {
                    return CharacterAction::STEP_LEFT;
                } else if(dx > 0 && find(possible_actions.begin(), possible_actions.end(), CharacterAction::STEP_FORWARD) != possible_actions.end()) {
                    return CharacterAction::STEP_FORWARD;
                } else if(dx < 0 && find(possible_actions.begin(), possible_actions.end(), CharacterAction::STEP_BACK) != possible_actions.end()) {
                    return CharacterAction::STEP_BACK;
                } else {
                    return CharacterAction::WAIT;
                }
            }
        }
    } else {
        if (dy == 0) {
            if (dx > 0) {
                if (dx <= get_settings().attack_range && can_punch) {
                    return CharacterAction::PUNCH_FORWARD;
                } else {
                    if(find(possible_actions.begin(), possible_actions.end(), CharacterAction::STEP_FORWARD) != possible_actions.end()) {
                        return CharacterAction::STEP_FORWARD;
                    } else if(find(possible_actions.begin(), possible_actions.end(), CharacterAction::STEP_LEFT) != possible_actions.end()) {
                        return CharacterAction::STEP_LEFT;
                    } else if(find(possible_actions.begin(), possible_actions.end(), CharacterAction::STEP_RIGHT) != possible_actions.end()) {
                        return CharacterAction::STEP_RIGHT;
                    } else {
                        return CharacterAction::WAIT;
                    }
                }
            } else {
                if (-dx <= get_settings().attack_range && can_punch) {
                    return CharacterAction::PUNCH_BACK;
                } else {
                    if(find(possible_actions.begin(), possible_actions.end(), CharacterAction::STEP_BACK) != possible_actions.end()) {
                        return CharacterAction::STEP_BACK;
                    } else if(find(possible_actions.begin(), possible_actions.end(), CharacterAction::STEP_RIGHT) != possible_actions.end()) {
                        return CharacterAction::STEP_RIGHT;
                    } else if(find(possible_actions.begin(), possible_actions.end(), CharacterAction::STEP_LEFT) != possible_actions.end()) {
                        return CharacterAction::STEP_LEFT;
                    } else {
                        return CharacterAction::WAIT;
                    }
                }
            }
        } else {
            if (dx > 0) {
                if(find(possible_actions.begin(), possible_actions.end(), CharacterAction::STEP_FORWARD) != possible_actions.end()) {
                    return CharacterAction::STEP_FORWARD;
                } else if(dy > 0 && find(possible_actions.begin(), possible_actions.end(), CharacterAction::STEP_RIGHT) != possible_actions.end()) {
                    return CharacterAction::STEP_RIGHT;
                } else if(dy < 0 && find(possible_actions.begin(), possible_actions.end(), CharacterAction::STEP_LEFT) != possible_actions.end()) {
                    return CharacterAction::STEP_LEFT;
                } else {
                    return CharacterAction::WAIT;
                }
            } else {
                if(find(possible_actions.begin(), possible_actions.end(), CharacterAction::STEP_BACK) != possible_actions.end()) {
                    return CharacterAction::STEP_BACK;
                } else if(dy > 0 && find(possible_actions.begin(), possible_actions.end(), CharacterAction::STEP_RIGHT) != possible_actions.end()) {
                    return CharacterAction::STEP_RIGHT;
                } else if(dy < 0 && find(possible_actions.begin(), possible_actions.end(), CharacterAction::STEP_LEFT) != possible_actions.end()) {
                    return CharacterAction::STEP_LEFT;
                } else {
                    return CharacterAction::WAIT;
                }
            }
        }
    }
}

CharacterAction IEnemyClass::strategy(std::vector<MapEntityWithPosition>& cells, Position& pos) noexcept { 
    return CharacterAction::WAIT;
};
};
