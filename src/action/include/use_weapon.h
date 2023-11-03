#pragma once

#include <range/v3/algorithm/find_if.hpp>
#include <range/v3/range/concepts.hpp>

#include "action_writer.h"
#include "dead.h"
#include "languages.h"
#include "player.h"
#include "plug.h"

namespace action {
class UseWeapon {
  entity::Player& player_;
  entity::Plug& plug_;
  const std::string& nameWeapon_;

 public:
  UseWeapon(entity::Player& player, entity::Plug& plug,
            const std::string& nameWeapon)
      : player_{player}, plug_{plug}, nameWeapon_{nameWeapon} {}

  void trigger() {
    auto weapon = ranges::find_if(player_.weapons(), [&](const auto& weapon) {
      return weapon.name == nameWeapon_;
    });

    if (weapon != std::cend(player_.weapons())) {
      entity::attack(plug_, *weapon);

      auto result =
          data::weapon::resultUseWeapon(plug_.name(), weapon->nb_damage);
      result::write(result);

      action::dead::trigger(plug_, data::action::resultDead(plug_.name()));

      // if weapon is fireArm and has no ammo, delete it
      if (weapon->type == weapon::Type::fireArm and weapon->durability <= 0) {
        weapon::remove(player_.weapons(), nameWeapon_);
      }
    }
  }

  const std::string& statement() const {
    auto weapon = ranges::find_if(player_.weapons(), [&](const auto& weapon) {
      return weapon.name == nameWeapon_;
    });

    if (weapon != std::cend(player_.weapons())) {
      return weapon->statement;
    } else {
      return data::weapon::statementEmpty;
    }
  }

  const std::string& name() const { return nameWeapon_; }

  weapon::Type type() const {
    auto weapon = ranges::find_if(player_.weapons(), [&](const auto& weapon) {
      return weapon.name == nameWeapon_;
    });

    return weapon != std::cend(player_.weapons()) ? weapon->type
                                                  : weapon::Type::noWeapon;
  }
};

namespace use_weapon {
void trigger(entity::Player& player, entity::Plug& plug,
             const std::string& nameWeapon) {
  UseWeapon use_weapon{player, plug, nameWeapon};
  use_weapon.trigger();
}
}  // namespace use_weapon
}  // namespace action
