#ifndef USE_WEAPON_H
#define USE_WEAPON_H

/*!
 * \brief UseWeapon.h
 */

#include "ActionWriter.h"
#include "Dead.h"
#include "FireArm.h"
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
    auto weapon = player_.weapons().find(nameWeapon_);

    weapon->attack(&plug_);

    auto result = Result(
        data::Weapon::resultUseWeapon(plug_.name(), weapon->damageWeapon()));
    Action::writeResult(result);

    Dead dead(plug_, data::Action::resultDead(plug_.name()));
    dead.triggerAction();

    // if weapon is fireArm and has no ammo, delete it
    if (player_.weapons().find(nameWeapon_)->weaponType() ==
        WeaponType::fireArm) {
      if (((const FireArm* const)player_.weapons().find(nameWeapon_))
              ->nbAmmo() <= 0) {
        player_.weapons().deleteWeapon(nameWeapon_);
      }
    }
  }

  const std::string& statement() const {
    return player_.weapons().find(nameWeapon_)->statement();
  }
  const std::string& name() const { return nameWeapon_; }

  WeaponType weaponType() const {
    return player_.weapons().find(nameWeapon_)->weaponType();
  }
};

#endif