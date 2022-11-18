#pragma once
#include <iostream>

class GameObjectException : public std::exception {
  std::string message;

public:
  explicit GameObjectException(const std::string &message);

  const char *what() const noexcept override;
};

class InventoryException : public GameObjectException {
public:
  explicit InventoryException(const std::string &message);
};

class StepException : public GameObjectException {
public:
  explicit StepException(const std::string &message);
};

class EventException : public GameObjectException {
public:
  explicit EventException(const std::string &message);
};
