#include "PotionModelEvent.h"
#include "Model/Exceptions/exceptions.h"

#include <memory>

using std::make_shared;
using std::shared_ptr;

namespace GameModel::Events {
PotionModelEvent::PotionModelEvent(
    std::shared_ptr<Map::Map> map,
    std::shared_ptr<UIModel::CursorState> cursor_state)
    : IEvent(map, cursor_state) {}

void PotionModelEvent::_execute() {
  size_t cursor_res = cursorState->getPotionsCursor();
  switch (cursor_res) {
  case 0:
    map->step(CharacterAction::POTION_1);
    break;
  case 1:
    map->step(CharacterAction::POTION_2);
    break;
  case 2:
    map->step(CharacterAction::POTION_3);
    break;
  case 3:
    map->step(CharacterAction::POTION_4);
    break;
  case 4:
    map->step(CharacterAction::POTION_5);
    break;
  default:
    throw EventException("wrong potion pointer");
  }
}
}; // namespace GameModel::Events
