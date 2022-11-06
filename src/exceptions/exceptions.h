#pragma once
#include <iostream>


namespace superrogue::exception {
class GameObjectException : public std::exception {
    std::string __message;
public:
    explicit GameObjectException(const std::string& message);

    const char* what() const noexcept override;
};

class InventoryException : public GameObjectException {
public:
    explicit InventoryException(const std::string& message);
};
};
