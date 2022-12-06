#include "EventProvider.h"
#include "Model/GameModel/Events/ModelEvents.h"
#include "Model/UIModel/Events/UIEvents.h"

#include "Common/Ncurses/CursesAPI.h"

namespace Controller {
using namespace GameModel::Events;
using namespace UIModel;

EventProvider::EventProvider(std::shared_ptr<CursorState> cursorState,
                             std::shared_ptr<GameModel::GameManager> map) {
  keyMapping = {
      {'[', std::make_shared<MovePotionDownEvent>(map, cursorState)},
      {']', std::make_shared<MovePotionUpEvent>(map, cursorState)},
      {'-', std::make_shared<MoveEquipmentDownEvent>(map, cursorState)},
      {'=', std::make_shared<MoveEquipmentUpEvent>(map, cursorState)},

      {'e', std::make_shared<ChangeItemModelEvent>(map, cursorState)},
      {'q', std::make_shared<ChangeWeaponModelEvent>(map, cursorState)},
      {'p', std::make_shared<PotionModelEvent>(map, cursorState)},
      {'s', std::make_shared<PunchBackModelEvent>(map, cursorState)},
      {'w', std::make_shared<PunchForwardModelEvent>(map, cursorState)},
      {'a', std::make_shared<PunchLeftModelEvent>(map, cursorState)},
      {'d', std::make_shared<PunchRightModelEvent>(map, cursorState)},
      {'l', std::make_shared<StepBackModelEvent>(map, cursorState)},
      {'o', std::make_shared<StepForwardModelEvent>(map, cursorState)},
      {'k', std::make_shared<StepLeftModelEvent>(map, cursorState)},
      {';', std::make_shared<StepRightModelEvent>(map, cursorState)},
      {'.', std::make_shared<WaitModelEvent>(map, cursorState)},
  };

  emptyEvent = std::make_shared<GameModel::Events::EmptyEvent>(map, cursorState);
}

std::shared_ptr<IEvent> EventProvider::getEventByKey(int key) {
  if (keyMapping.find(key) == keyMapping.end())
    return emptyEvent;
  return keyMapping[key];
}

void EventProvider::addObserver(std::shared_ptr<ModelObserver> obs) {
    for (auto &[key, event]: keyMapping) {
        event->addObserver(obs);
    }
    emptyEvent->addObserver(obs);

    emptyEvent->execute();    // to connect
}

} // namespace Controller
