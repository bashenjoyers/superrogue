#include "exceptions/exceptions.h"


namespace superrogue::exception {
GameObjectException::GameObjectException(const std::string& message) : __message(message) {};

const char* GameObjectException::what() const noexcept {
    return __message.c_str();
}

InventoryException::InventoryException(const std::string& message) : GameObjectException(message) {};

StepException::StepException(const std::string& message) : GameObjectException(message) {};
};
