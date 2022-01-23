#ifndef USE_WEAPON_H
#define USE_WEAPON_H

#include "ActionWriter.h"
#include "Dead.h"
#include "Languages.h"
#include "NameType.h"
#include "Player.h"
#include "Plug.h"

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
    auto weapon =
        std::find_if(std::cbegin(player_.weapons()),
                     std::cend(player_.weapons()), [this](const auto& weapon) {
                       return weapon.name == this->nameWeapon_;
                     });

    if (weapon != std::cend(player_.weapons())) {
      entity::attack(plug_, *weapon);

      auto result = Result{
          data::Weapon::resultUseWeapon(plug_.name(), weapon->nb_damage)};
      action::writeResult(result);

      action::Dead dead{plug_, data::Action::resultDead(plug_.name())};
      dead.trigger();

      // if weapon is fireArm and has no ammo, delete it
      if (weapon->type == weapon::Type::fireArm and weapon->durability <= 0) {
        weapon::remove(player_.weapons(), nameWeapon_);
      }
    }
  }

  const std::string& statement() const {
    auto weapon =
        std::find_if(std::cbegin(player_.weapons()),
                     std::cend(player_.weapons()), [this](const auto& weapon) {
                       return weapon.name == this->nameWeapon_;
                     });

    if (weapon != std::cend(player_.weapons())) {
      return weapon->statement;
    } else {
      return data::Weapon::statementEmpty;
    }
  }

  const std::string& name() const { return nameWeapon_; }

  weapon::Type type() const {
    auto weapon =
        std::find_if(std::cbegin(player_.weapons()),
                     std::cend(player_.weapons()), [this](const auto& weapon) {
                       return weapon.name == this->nameWeapon_;
                     });

    if (weapon != std::cend(player_.weapons())) {
      return weapon->type;
    } else {
      return weapon::Type::noWeapon;
    }
  }
};
}  // namespace action

#endif