#pragma once

#include "Model/GameModel/Map/Map.h"
#include "Model/GameModel/Events/ModelEvent.h"


namespace GameModel::Events {
class PunchBackModelEvent : public ModelEvent {
public:
    PunchBackModelEvent(std::shared_ptr<Map::Map> map);
private:
    void _execute() override;
};
}
