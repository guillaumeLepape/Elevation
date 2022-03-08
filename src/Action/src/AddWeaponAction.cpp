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
    bool not_in_player_weapons;
    std::tie(std::ignore, not_in_player_weapons) =
        player_.weapons().insert(std::move(weapon_));

    if (not_in_player_weapons) {
      action::writeResult(result_);
    }
  }
}
}  // namespace action