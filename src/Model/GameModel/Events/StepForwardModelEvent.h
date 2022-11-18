#pragma once

#include "Model/GameModel/Map/Map.h"
#include "Model/GameModel/Events/ModelEvent.h"


namespace GameModel::Events {
class StepForwardModelEvent : public ModelEvent {
public:
    StepForwardModelEvent(std::shared_ptr<Map::Map> map);
private:
    void _execute() override;
};
}
