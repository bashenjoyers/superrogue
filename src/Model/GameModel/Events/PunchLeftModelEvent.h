#pragma once

#include "Model/GameModel/Map/Map.h"
#include "Model/GameModel/Events/ModelEvent.h"


namespace GameModel::Events {
class PunchLeftModelEvent : public ModelEvent {
public:
    PunchLeftModelEvent(std::shared_ptr<Map::Map> map);
private:
    void _execute() override;
};
}
