#include "AddWeaponAction.h"

#include "ActionWriter.h"
#include "Player.h"

namespace action {
AddWeaponAction::AddWeaponAction(entity::Player& player,
                                 weapon::Weapon&& weapon)
    : result_{data::Action::resultAddWeapon(weapon.name)},
      player_{player},
      weapon_{std::move(weapon)} {}

void AddWeaponAction::trigger() {
  if (weapon_.type != weapon::Type::noWeapon) {
    bool present;
    std::tie(std::ignore, present) =
        player_.weapons().insert(std::move(weapon_));

    if (not present) {
      action::writeResult(result_);
    }
  }
}
}  // namespace action