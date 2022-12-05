#pragma once
#include <string>
#include "Model/GameModel/GameObject/Character/CharacterAction.h"
#include "Model/GameModel/GameObject/Character/Class/Enemy/state/helpers.h"
#include "Model/GameModel/GameObject/Character/Class/Enemy/state/EnemyEnvironmentInfo.h"
#include "Model/GameModel/abstract.h"


namespace GameModel {
class EnemyStateHolder;

/**
 * @brief base state class for enemy
 * 
 */
class EnemyState {
public:
    // created by state name
    EnemyState(const std::string& name);
    // return name
    std::string get_name() const noexcept;
    // returns a step for the current state, or jumps to another and creates a step through it
    virtual CharacterAction step(EnemyStateHolder* state_holder, EnemyEnvironmentInfo& environment) = 0;
private:
    std::string name;
};

class EnemyStateHolder {
public:
    // the last position the character was in. Can be used to get to the desired cell or vice versa to run away from it (use depends on the settings of the enemy)
    std::optional<Abstract::Position> last_smb_pos = std::nullopt;
    // creates holder based on state, enemy class (may affect state behavior), settings and ignore flag
    EnemyStateHolder(std::shared_ptr<EnemyState> state, Abstract::EnemyClass enemy_class, EnemySettings settings, bool ignore=false);
    // updates the holder's current state, used when transitioning between states
    void update_state(std::shared_ptr<EnemyState> new_state) noexcept;
    // returns the current state
    std::shared_ptr<EnemyState> get_state() const noexcept;
    // returns settings
    EnemySettings get_settings() const noexcept;
    // returns the class of the enemy
    Abstract::EnemyClass get_entity() const noexcept;
    // returns a flag about whether to ignore the character if it is visible
    bool is_ignore() const noexcept;
    // sets the ignore flag to false - someone attacked first
    void disturb() noexcept;
    // returns the action that the character will perform. Redirects to a similar state function
    CharacterAction step(EnemyEnvironmentInfo& environment);
private:
    std::shared_ptr<EnemyState> state;
    Abstract::EnemyClass entity;
    EnemySettings settings;
    bool ignore;
};

class WaitEnemyState: public EnemyState {
public:
    WaitEnemyState();
    // just stands still, with some probability it can go into a \"walk\" state, if it sees the enemy and the flag \"ignore\" is false, then it goes into a \"fight\" state
    virtual CharacterAction step(EnemyStateHolder* state_holder, EnemyEnvironmentInfo& environment);
};

class WalkEnemyState: public EnemyState {
public:
    WalkEnemyState();
    // just walk still, with some probability it can go into a \"wait\" state, if it sees the enemy and the flag \"ignore\" is false, then it goes into a \"fight\" state
    virtual CharacterAction step(EnemyStateHolder* state_holder, EnemyEnvironmentInfo& environment);
};

class FightEnemyState: public EnemyState {
public:
    FightEnemyState();
    // tries to reach the enemy and hit him, if the enemy is not visible, he goes into a \"walk\" state or \"pursuit\" state (depending on the settings)
    virtual CharacterAction step(EnemyStateHolder* state_holder, EnemyEnvironmentInfo& environment);
};

class PursuitEnemyState: public EnemyState {
public:
    PursuitEnemyState();
    // tries to reach the place where the character was, if he sees the character, then he goes into a \"fight\" state, if he reaches that place and sees nothing, he goes into \"walk\" state
    virtual CharacterAction step(EnemyStateHolder* state_holder, EnemyEnvironmentInfo& environment);
};

class CowardEnemyState: public EnemyState {
public:
    CowardEnemyState();
    // runs in the opposite direction from the character if he sees him. Otherwise, with some probability, it goes into a \"walk\" state (if this is not a coward). If he didn’t move, he runs from the last position in which he saw the character or is standing (depending on the settings)
    virtual CharacterAction step(EnemyStateHolder* state_holder, EnemyEnvironmentInfo& environment);
};
}
