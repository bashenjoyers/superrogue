#pragma once

#include <cstddef>
#include "Model/GameModel/GameObject/Item/Stuff/Item.h"

namespace UIModel {

    class CursorState {
    public:
        size_t getPotionsCursor();
        void incrementPotionsCursor();
        void decrementPotionsCursor();

        GameModel::ItemType getEquipmentCursor();
        void incrementEquipmentCursor();
        void decrementEquipmentCursor();

    private:
        size_t potionsCursor = 0;
        GameModel::ItemType equipmentCursor = GameModel::ItemType::HELMET;
        size_t maxPotionsNumber = 3 + 1;
        int maxEquipmentNumber = static_cast<int>(GameModel::ItemType::WEAPON_DISTANT) + 1;
    };
}

