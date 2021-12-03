#ifndef USE_WEAPON_H
#define USE_WEAPON_H

/*!
 * \brief UseWeapon.h
 */

#include "ActionWriter.h"
#include "Dead.h"
#include "Languages.h"
#include "NameType.h"
#include "Player.h"
#include "Plug.h"

class UseWeapon {
  Player& player_;
  Plug& plug_;
  const std::string& nameWeapon_;

 public:
  UseWeapon(Player& player, Plug& plug, const std::string& nameWeapon)
      : player_(player), plug_(plug), nameWeapon_(nameWeapon) {}

  void triggerAction() {
    auto weapon =
        std::find_if(std::cbegin(player_.weapons()),
                     std::cend(player_.weapons()), [this](const auto& weapon) {
                       return weapon.name == this->nameWeapon_;
                     });

    if (weapon != std::cend(player_.weapons())) {
      attack(&plug_, *weapon);

      auto result = Result(
          data::Weapon::resultUseWeapon(plug_.name(), weapon->nb_damage));
      Action::writeResult(result);

      Dead dead(plug_, data::Action::resultDead(plug_.name()));
      dead.triggerAction();

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

#endif