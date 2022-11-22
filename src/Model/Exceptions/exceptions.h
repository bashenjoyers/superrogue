#pragma once
#include <iostream>

/**
 * @brief a class that represents exception for game objects
 */
class GameObjectException : public std::exception {
  std::string message;

public:
   /**
   * @brief returns an object of GameObjectException
   *
   * @param message - info about exception
   */
  explicit GameObjectException(const std::string &message);

  /**
  * @brief returns info about exception
  *
  * @return const char* - info about exception
  */
  const char *what() const noexcept override;
};

/**
 * @brief a class that represents exception for config reading
 */
class ConfigReadException : public std::exception {
    std::string message;

public:
    /**
    * @brief creates an object of ConfigReadException
    *
    * @param message - info about exception
    */
    explicit ConfigReadException(const std::string &message);

    /**
    * @brief returns info about exception
    *
    * @return const char* - info about exception
    */
    const char *what() const noexcept override;
};

/**
 * @brief a class that represents exception for inventory
 */
class InventoryException : public GameObjectException {
public:
    /**
    * @brief creates an object of InventoryException
    *
    * @param message - info about exception
    */
    explicit InventoryException(const std::string &message);
};

/**
 * @brief a class that represents exception for step
 */
class StepException : public GameObjectException {
public:
    /**
    * @brief creates an object of StepException
    *
    * @param message - info about exception
    */
    explicit StepException(const std::string &message);
};

/**
 * @brief a class that represents exception for event
 */
class EventException : public GameObjectException {
public:
    /**
    * @brief creates an object of EventException
    *
    * @param message - info about exception
    */
    explicit EventException(const std::string &message);
};
