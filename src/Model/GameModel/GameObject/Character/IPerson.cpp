#include "IPerson.h"

using std::string;

namespace GameModel {
string IPerson::get_description() const noexcept {
  return person_class->get_description();
}

std::shared_ptr<IPersonClass> IPerson::get_person_class() const noexcept { return person_class; }

IPerson::IPerson(string name, Characteristics characteristics,
                 std::shared_ptr<IPersonClass> person_class)
    : ICharacter(name, person_class->get_description(), characteristics),
      person_class(person_class){};
}; // namespace GameModel
