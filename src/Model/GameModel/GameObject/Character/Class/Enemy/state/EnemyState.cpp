#include "Model/GameModel/GameObject/Character/Class/Enemy/state/EnemyState.h"
#include "Model/GameModel/values.h"
#include "Model/GameModel/GameObject/Character/Class/Enemy/state/behaviors.h"
#include "Model/GameModel/generator.h"

using std::string;
using std::shared_ptr;


namespace GameModel {
// EnemyState
using Abstract::EnemyClass;
using Abstract::Position;
using Generation::change_state_gen;

EnemyState::EnemyState(const string& name): name(name) {}

string EnemyState::get_name() const noexcept {
    return name;
}

// EnemyStateHolder
EnemyStateHolder::EnemyStateHolder(shared_ptr<EnemyState> state, EnemyClass enemy_class, EnemySettings settings, bool ignore): state(state), entity(enemy_class), settings(settings), ignore(ignore) {}
    
void EnemyStateHolder::update_state(shared_ptr<EnemyState> new_state) noexcept {
    state.swap(new_state);
}

std::shared_ptr<EnemyState> EnemyStateHolder::get_state() const noexcept {
    return state;
}

Abstract::EnemyClass EnemyStateHolder::get_entity() const noexcept {
    return entity;
}

EnemySettings EnemyStateHolder::get_settings() const noexcept {
    return settings;
}

bool EnemyStateHolder::is_ignore() const noexcept {
    return ignore;
}

void EnemyStateHolder::disturb() noexcept {
    ignore = false;
}

CharacterAction EnemyStateHolder::step(EnemyEnvironmentInfo& environment) {
    auto step = state->step(this, environment);
    return step;
}

// WaitEnemyState
WaitEnemyState::WaitEnemyState() : EnemyState("Wait") {}

CharacterAction WaitEnemyState::step(EnemyStateHolder* state_holder, EnemyEnvironmentInfo& environment) {
    if (!state_holder->is_ignore() && environment.smb_pos.has_value()) {
        state_holder->update_state(std::make_shared<FightEnemyState>());
        return state_holder->step(environment);
    }
    float change = change_state_gen(Values::generator);
    if (change < CHANGE_WALK_K) {
        state_holder->update_state(std::make_shared<WalkEnemyState>());
        return state_holder->step(environment);
    }
    return wait_behavior();
}

// WalkEnemyState
WalkEnemyState::WalkEnemyState() : EnemyState("Walk") {}

CharacterAction WalkEnemyState::step(EnemyStateHolder* state_holder, EnemyEnvironmentInfo& environment) {
    if (!state_holder->is_ignore() && environment.smb_pos.has_value()) {
        state_holder->update_state(std::make_shared<FightEnemyState>());
        return state_holder->step(environment);
    }
    float change = change_state_gen(Values::generator);
    if (change < CHANGE_WALK_K) {
        state_holder->update_state(std::make_shared<WaitEnemyState>());
        return state_holder->step(environment);
    }
    return walk_behavior(environment.possible_actions);
}

// FightEnemyState
FightEnemyState::FightEnemyState() : EnemyState("Fight") {}

CharacterAction FightEnemyState::step(EnemyStateHolder* state_holder, EnemyEnvironmentInfo& environment) {
    if (!environment.smb_pos.has_value()) {
        if (state_holder->last_smb_pos.has_value()) {
            state_holder->update_state(std::make_shared<PursuitEnemyState>());
        } else {
            state_holder->update_state(std::make_shared<WalkEnemyState>());
        }
        return state_holder->step(environment);
    }
    EnemySettings settings = state_holder->get_settings();
    Position smb_pos = environment.smb_pos.value();
    if (settings.intellect > SAVE_LAST_POS_INTELLECT_K) {
        state_holder->last_smb_pos = smb_pos;
    }
    int dx = (int)smb_pos.x - environment.own_pos.x;
    int dy = (int)smb_pos.y - environment.own_pos.y;
    return default_fight_behavior(dx, dy, environment.possible_actions, settings, true);   // TODO true
}

// PursuitEnemyState
PursuitEnemyState::PursuitEnemyState() : EnemyState("Pursuit") {}

CharacterAction PursuitEnemyState::step(EnemyStateHolder* state_holder, EnemyEnvironmentInfo& environment) {
    if (environment.smb_pos.has_value()) {
        state_holder->update_state(std::make_shared<FightEnemyState>());
        return state_holder->step(environment);
    }
    Position last_smb_pos = state_holder->last_smb_pos.value();     // the value is definitely there, otherwise you cannot get into this state
    if (environment.own_pos == last_smb_pos) {
        state_holder->update_state(std::make_shared<WalkEnemyState>());
        return state_holder->step(environment);
    }
    int dx = (int)last_smb_pos.x - environment.own_pos.x;
    int dy = (int)last_smb_pos.y - environment.own_pos.y;
    return default_fight_behavior(dx, dy, environment.possible_actions, state_holder->get_settings(), false);
}

// CowardEnemyState
CowardEnemyState::CowardEnemyState() : EnemyState("Coward") {}

CharacterAction CowardEnemyState::step(EnemyStateHolder* state_holder, EnemyEnvironmentInfo& environment) {
    EnemySettings settings = state_holder->get_settings();
    if (environment.smb_pos.has_value()) {
        Position smb_pos = environment.smb_pos.value();
        if (settings.intellect > SAVE_LAST_POS_INTELLECT_K) {
            state_holder->last_smb_pos = smb_pos;
        }
        int dx = (int)smb_pos.x - environment.own_pos.x;
        int dy = (int)smb_pos.y - environment.own_pos.y;
        return coward_behavior(dx, dy, environment.possible_actions, settings);
    }
    float change = change_state_gen(Values::generator);
    if (change < NOT_COWARD_K && state_holder->get_entity() != EnemyClass::COWARD) {
        state_holder->update_state(std::make_shared<WalkEnemyState>());
        return state_holder->step(environment);
    }
    if (state_holder->last_smb_pos.has_value()) {
        Position last_smb_pos = state_holder->last_smb_pos.value();
        int dx = (int)last_smb_pos.x - environment.own_pos.x;
        int dy = (int)last_smb_pos.y - environment.own_pos.y;
        return coward_behavior(dx, dy, environment.possible_actions, settings);
    }
    return wait_behavior();
}
}
