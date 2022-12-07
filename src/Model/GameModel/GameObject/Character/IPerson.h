#pragma once
#include "ICharacter.h"
#include "Model/GameModel/GameObject/Character/Class/Person/IPersonClass.h"
#include "Model/GameModel/GameObject/Characteristics.h"
#include <iostream>
#include <string>

#include <memory>

namespace GameModel {
/**
 * @brief Person interface
 * 
 */
class IPerson : public ICharacter {
  // Person class. Gives certain features when playin
  std::shared_ptr<IPersonClass> person_class;

public:
  // redefines description to class description
  std::string get_description() const noexcept override;
  // use potion
  virtual void potion(int potion_i) = 0;
  // returns the person settings
  virtual PersonSettings get_settings() const noexcept;
  /**
   * @brief Construct a new IPerson by standard properties (without a description, it is taken separately) and by person class
   * 
   */
  IPerson(std::string name, Characteristics characteristics,
          std::shared_ptr<IPersonClass> person_class);
  IPerson(){};
  virtual ~IPerson() {}

    Abstract::MapEntity get_map_entity() const noexcept override;
};
}; // namespace GameModel
