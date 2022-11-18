#pragma once

#include "Model/GameModel/Map/Map.h"
#include "Model/GameModel/Events/ModelEvent.h"


namespace GameModel::Events {
class StepLeftModelEvent : public ModelEvent {
public:
    StepLeftModelEvent(std::shared_ptr<Map::Map> map);
private:
    void _execute() override;
};
}
