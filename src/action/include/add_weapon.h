#ifndef ADD_WEAPON_ACTION_H
#define ADD_WEAPON_ACTION_H

#include "action_writer.h"
#include "concept.h"
#include "player.h"
#include "plug.h"
#include "weapon.h"

namespace action {
class AddWeapon {
 private:
  std::string result_;
  entity::Player& player_;
  weapon::Weapon weapon_;

 public:
  AddWeapon(entity::Player& player, weapon::Weapon&& weapon)
      : result_{data::action::resultAddWeapon(weapon.name)},
        player_{player},
        weapon_{std::move(weapon)} {}

  void trigger() {
    if (weapon_.type != weapon::Type::noWeapon) {
      bool not_in_player_weapons;
      std::tie(std::ignore, not_in_player_weapons) =
          player_.weapons().insert(std::move(weapon_));

      if (not_in_player_weapons) {
        result::write(result_);
      }
    }
  }
};

namespace add_weapon {
void trigger(entity::Player& player, weapon::Weapon&& weapon) {
  AddWeapon add_weapon{player, std::forward<weapon::Weapon>(weapon)};
  add_weapon.trigger();
}
}  // namespace add_weapon
}  // namespace action

#endif