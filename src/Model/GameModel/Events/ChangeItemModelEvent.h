#pragma once

#include "Model/GameModel/Map/Map.h"
#include "Model/GameModel/Events/ModelEvent.h"


namespace GameModel::Events {
class ChangeItemModelEvent : public ModelEvent {
public:
    ChangeItemModelEvent(std::shared_ptr<Map::Map> map);
private:
    void _execute() override;
};
}
