#include "controller/events/modelEvent/StepBackModelEvent.h"

using superrogue::map::Map;
using superrogue::map::MapInfo;
using std::shared_ptr;
using std::make_shared;
using superrogue::game_object::character::CharacterAction;;


namespace superrogue::controller::event {
StepBackModelEvent::StepBackModelEvent(std::shared_ptr<superrogue::map::Map*> map) : ModelEvent(map) {};

void StepBackModelEvent::_execute() {
    (*map)->step(CharacterAction::STEP_BACK);
}
};
