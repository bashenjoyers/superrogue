#include "exceptions/exceptions.h"

namespace superrogue::exception {
GameObjectException::GameObjectException(const std::string &message)
    : message(message){};

const char *GameObjectException::what() const noexcept {
  return message.c_str();
}

InventoryException::InventoryException(const std::string &message)
    : GameObjectException(message){};

StepException::StepException(const std::string &message)
    : GameObjectException(message){}
    
EventException::EventException(const std::string &message): GameObjectException(message) {};
}; // namespace superrogue::exception
