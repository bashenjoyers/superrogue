#pragma once
#include "ICharacter.h"
#include "Model/GameModel/GameObject/Character/Class/Person/IPersonClass.h"
#include "Model/GameModel/GameObject/Characteristics.h"
#include <iostream>
#include <string>

#include <memory>

namespace GameModel {
class IPerson : public ICharacter {
  std::shared_ptr<IPersonClass> person_class;

public:
  std::string get_description() const noexcept override;
  virtual void potion(int potion_i) = 0;
  std::shared_ptr<IPersonClass> get_person_class() const noexcept;
  IPerson(std::string name, Characteristics characteristics,
          std::shared_ptr<IPersonClass> person_class);
  IPerson(){};
  virtual ~IPerson() {}
};
}; // namespace GameModel
