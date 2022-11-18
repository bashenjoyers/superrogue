#pragma once

#include "Model/GameModel/Map/Map.h"
#include "Model/GameModel/Events/ModelEvent.h"


namespace GameModel::Events {
class StepBackModelEvent : public ModelEvent {
public:
    StepBackModelEvent(std::shared_ptr<Map::Map> map);
private:
    void _execute() override;
};
}
