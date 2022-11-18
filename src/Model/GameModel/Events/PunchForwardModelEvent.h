#pragma once

#include "Model/GameModel/Map/Map.h"
#include "Model/GameModel/Events/ModelEvent.h"


namespace GameModel::Events {
class PunchForwardModelEvent : public ModelEvent {
public:
    PunchForwardModelEvent(std::shared_ptr<Map::Map> map);
private:
    void _execute() override;
};
}
