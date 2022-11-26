#include "IPerson.h"

using std::string;

namespace GameModel {
string IPerson::get_description() const noexcept {
  return person_class->get_description();
}

PersonSettings IPerson::get_settings() const noexcept { return person_class->get_settings(); }
IPerson::IPerson(string name, Characteristics characteristics,
                 std::shared_ptr<IPersonClass> person_class)
    : ICharacter(name, person_class->get_description(), characteristics),
      person_class(person_class){};
}; // namespace GameModel
