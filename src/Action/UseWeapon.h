#ifndef USE_WEAPON_H
#define USE_WEAPON_H

/*!
 * \brief UseWeapon.h
 */

#include "Dead.h"
#include "FireArm.h"
#include "Languages.h"
#include "Player.h"
#include "Plug.h"

class UseWeapon : public Action {
 private:
  const Weapon* weapon_;
  Player* const player_;
  Plug* const plug_;

 public:
  UseWeapon(Player* const player, Plug* const plug, const Weapon* weapon,
            const std::string& result)
      : Action(weapon->statement(), result),
        weapon_(weapon),
        player_(player),
        plug_(plug) {}

  void triggerAction() override {
    weapon_->attack(plug_);

    actionWriter_.writeResult();

    Dead dead(plug_, "", data::Action::resultDead(plug_->name()));
    dead.triggerAction();

    // if weapon is fireArm and has no ammo, delete it
    if (weapon_->weaponType() == WeaponType::fireArm) {
      if (((FireArm*)weapon_)->nbAmmo() <= 0) {
        std::string nameWeapon = weapon_->name();
        player_->weapons()->deleteWeapon(nameWeapon);
      }
    }
  }

  const std::string& nameWeapon() const { return weapon_->name(); }
  const Weapon* weapon() const { return weapon_; }
};

#endif