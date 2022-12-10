#pragma once
#include "Model/GameModel/GameObject/Character/CharacterAction.h"
#include "Model/GameModel/GameObject/Character/Class/Enemy/state/helpers.h"

namespace GameModel {
/**
 * @brief seeks to approach the position and hit the one who is there
 * 
 * @param dx - distance to character (x)
 * @param dy - distance to character (y)
 * @param possible_actions - posible step directions and wait
 * @param settings - just enemy settings
 * @param can_punch - if this character can punch smb
 * @return CharacterAction - result action
 */
CharacterAction default_fight_behavior(int dx, int dy, std::vector<CharacterAction> &possible_actions, EnemySettings settings, bool can_punch = true);

/**
 * @brief just takes a step in an accessible direction or stands
 * 
 * @param possible_actions - posible step directions and wait
 * @return CharacterAction - result action
 */
CharacterAction walk_behavior(std::vector<CharacterAction> &possible_actions);

/**
 * @brief just stands
 * 
 * @param possible_actions - posible step directions and wait
 * @return CharacterAction - result action
 */
CharacterAction wait_behavior();

/**
 * @brief seeks to get away from the position and the one who is there
 * 
 * @param dx - distance to character (x)
 * @param dy - distance to character (y)
 * @param possible_actions - posible step directions and wait
 * @param settings - just enemy settings
 * @return CharacterAction - result action
 */
CharacterAction coward_behavior(int dx, int dy, std::vector<CharacterAction> &possible_actions, EnemySettings settings);
}
