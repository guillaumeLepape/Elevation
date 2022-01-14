#ifndef ADD_WEAPON_ACTION_H
#define ADD_WEAPON_ACTION_H

#include <memory>

#include "NameType.h"
#include "Player.h"
#include "Plug.h"
#include "Weapon.h"

namespace action {
class AddWeaponAction {
 private:
  Result result_;
  entity::Player& player_;
  weapon::Weapon weapon_;

 public:
  AddWeaponAction(entity::Player& player, weapon::Weapon&& weapon);

  void trigger();
};
}  // namespace action

#endif