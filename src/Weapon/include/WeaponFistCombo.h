#ifndef WEAPON_FIST_COMBO_H
#define WEAPON_FIST_COMBO_H

/*!
 * \file WeaponFistCombo.h
 */

#include "Languages.h"
#include "Weapon.h"

// class WeaponFistCombo : public Weapon {
//  public:
//   WeaponFistCombo(const Weapon* weapon)
//       : Weapon(weapon->name() + "FistCombo", weapon->damageWeapon() / 2,
//                weapon->weaponType(),
//                data::Weapon::statementCombo(weapon->name())) {}

//   ~WeaponFistCombo() override = default;
// };

struct WeaponFistCombo : Weapon {
  WeaponFistCombo(const Weapon* const weapon)
      : weapon_{weapon},
        name_{weapon_->name() + "FistCombo"},
        statement_{data::Weapon::statementCombo(weapon_->name())} {}

  const std::string& name() const override { return name_; }
  int damageWeapon() const override { return weapon_->damageWeapon() / 2; }
  WeaponType weaponType() const override { return weapon_->weaponType(); }
  const std::string& statement() const override { return statement_; }
  nlohmann::json writeJson() const override {
    return writeJsonNonFireArm(name());
  }
  void attack(Entity* const entity) const override {
    entity->decreaseLifePoints(damageWeapon());
  }
  ~WeaponFistCombo() = default;

 private:
  const Weapon* const weapon_;
  std::string name_;
  std::string statement_;
};

#endif