#include "EventProvider.h"
#include "Model/GameModel/Events/ModelEvents.h"
#include "Model/UIModel/Events/UIEvents.h"

#include "Common/Ncurses/CursesAPI.h"

namespace Controller {
    using namespace GameModel::Events;
    using namespace UIModel;

    EventProvider::EventProvider(std::shared_ptr<CursorState> cursorState, std::shared_ptr<GameModel::Map::Map> map) {
        keyMapping = {
                {'[', std::make_shared<MovePotionDownEvent>(cursorState)},
                {']', std::make_shared<MovePotionUpEvent>(cursorState)},
                {'-', std::make_shared<MoveEquipmentDownEvent>(cursorState)},
                {'=', std::make_shared<MoveEquipmentUpEvent>(cursorState)},

                {'e', std::make_shared<ChangeItemModelEvent>(map)},
                {'p', std::make_shared<PotionModelEvent>(map, cursorState)},
                {'s', std::make_shared<PunchBackModelEvent>(map)},
                {'w', std::make_shared<PunchForwardModelEvent>(map)},
                {'a', std::make_shared<PunchLeftModelEvent>(map)},
                {'d', std::make_shared<PunchRightModelEvent>(map)},
                {KEY_DOWN, std::make_shared<StepBackModelEvent>(map)},
                {KEY_UP, std::make_shared<StepForwardModelEvent>(map)},
                {KEY_LEFT, std::make_shared<StepLeftModelEvent>(map)},
                {KEY_RIGHT, std::make_shared<StepRightModelEvent>(map)},
                {'.', std::make_shared<WaitModelEvent>(map)},
        };
    }

    std::shared_ptr<IEvent> EventProvider::getEventByKey(int key) {
        if (keyMapping.find(key) == keyMapping.end()) return emptyEvent;
        return keyMapping[key];
    }
    
    void EventProvider::addUIObserver(std::shared_ptr<UIModelObserver> obs) {
        for (auto [key, event]: keyMapping) {
            auto e = std::dynamic_pointer_cast<UIEvent>(event);
            if (e) {
                e->addObserver(obs);
            }
        }
    }
    
    void EventProvider::addModelObserver(std::shared_ptr<GameModelObserver> obs) {
        for (auto [key, event]: keyMapping) {
            auto e = std::dynamic_pointer_cast<ModelEvent>(event);
            if (e) {
                e->addObserver(obs);
            }
        }
    }
}
