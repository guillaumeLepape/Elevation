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
 private:
  Result result_;

  const Weapon* weapon_;
  Player* const player_;
  Plug* const plug_;

 public:
  UseWeapon(Player* const player, Plug* const plug, const Weapon* weapon)
      : result_(data::Weapon::resultUseWeapon(plug->name(),
                                              weapon->damageWeapon())),
        weapon_(weapon),
        player_(player),
        plug_(plug) {}

  void triggerAction() {
    plug_->decreaseLifePoints(weapon_->damageWeapon());

    Action::writeResult(result_);

    Dead dead(plug_, data::Action::resultDead(plug_->name()));
    dead.triggerAction();

    // if weapon is fireArm and has no ammo, delete it
    if (weapon_->weaponType() == WeaponType::fireArm) {
      if (((FireArm*)weapon_)->nbAmmo() <= 0) {
        std::string nameWeapon = weapon_->name();
        player_->weapons().deleteWeapon(nameWeapon);
      }
    }
  }

  const std::string& statement() const { return weapon_->statement(); }

  const std::string& nameWeapon() const { return weapon_->name(); }
  const Weapon* weapon() const { return weapon_; }
};

struct UseWeapon1 {
  Player& player_;
  Plug& plug_;
  std::unique_ptr<const Weapon> weapon_;
  Result result_;
  UseWeapon1(Player& player, Plug& plug, std::unique_ptr<const Weapon>&& weapon)
      : player_(player),
        plug_(plug),
        weapon_(std::move(weapon)),
        result_(data::Weapon::resultUseWeapon(plug_.name(),
                                              weapon_->damageWeapon())) {}

  const std::string& statement() const { return weapon_->statement(); }
};

namespace t {
void trigger(const UseWeapon1& useWeapon);
}

#endif