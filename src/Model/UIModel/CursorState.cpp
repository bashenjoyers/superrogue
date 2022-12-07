#include "CursorState.h"

namespace UIModel {
    size_t CursorState::getPotionsCursor() {
        return potionsCursor;
    }

    GameModel::ItemType CursorState::getEquipmentCursor() {
        return equipmentCursor;
    }

    void CursorState::incrementPotionsCursor() {
        potionsCursor = (potionsCursor + 1) % maxPotionsNumber;
    }

    void CursorState::decrementPotionsCursor() {
        if (potionsCursor == 0) potionsCursor = maxPotionsNumber;
        potionsCursor = (potionsCursor - 1) % maxPotionsNumber;
    }

    void CursorState::incrementEquipmentCursor() {
        equipmentCursor = static_cast<GameModel::ItemType>(
                ((int) equipmentCursor + 1) % maxEquipmentNumber
        );
    }

    void CursorState::decrementEquipmentCursor() {
        equipmentCursor = static_cast<GameModel::ItemType>(
                (maxEquipmentNumber + (((int) equipmentCursor - 1) % maxEquipmentNumber)) % maxEquipmentNumber
        );
    }
}

