#include "elevation/weapon/weapon.h"

#include <fmt/color.h>

#include <range/v3/algorithm/contains.hpp>
#include <range/v3/algorithm/generate.hpp>
#include <range/v3/algorithm/remove.hpp>
#include <range/v3/algorithm/transform.hpp>
#include <range/v3/iterator/insert_iterators.hpp>

namespace elevation::weapon {
Weapon NoWeapon() {
  return Weapon{data::weapon::nameNoWeapon,         0, Type::noWeapon,
                data::weapon::statementUseNoWeapon, 1, 0};
}
Weapon Fist() {
  return Weapon{data::weapon::nameFist,         20, Type::fist,
                data::weapon::statementUseFist, 1,  0};
}
Weapon DivineStrike() {
  return Weapon{data::weapon::nameDivineStrike,      1000, Type::fist,
                data::weapon::statementDivineStrike, 1,    0};
}
Weapon Chopper() {
  return Weapon{data::weapon::nameChopper,         80, Type::meleeWeapon,
                data::weapon::statementUseChopper, 1,  0};
}
Weapon Cutter() {
  return Weapon{data::weapon::nameCutter,         15, Type::meleeWeapon,
                data::weapon::statementUseCutter, 1,  0};
}
Weapon Hammer() {
  return Weapon{data::weapon::nameHammer,         40, Type::meleeWeapon,
                data::weapon::statementUseHammer, 1,  0};
}
Weapon Heroine() {
  return Weapon{data::weapon::nameHeroine, 50, Type::meleeWeapon, "", 1, 0};
}
Weapon Katana() {
  return Weapon{data::weapon::nameKatana,         50, Type::meleeWeapon,
                data::weapon::statementUseKatana, 1,  0};
}
Weapon Knife() {
  return Weapon{data::weapon::nameKnife,         30, Type::meleeWeapon,
                data::weapon::statementUseKnife, 1,  0};
}
Weapon Ninemm(int nb_ammo) {
  return Weapon{data::weapon::nameNinemm,         70,      Type::fireArm,
                data::weapon::statementUseNinemm, nb_ammo, 1};
}
Weapon AK47(int nb_ammo) {
  return Weapon{data::weapon::nameAK47,         150,     Type::fireArm,
                data::weapon::statementUseAK47, nb_ammo, 10};
}
Weapon WeaponFistCombo(const Weapon& weapon) {
  return Weapon{fmt::format("{}FistCombo", weapon.name),
                static_cast<int>(weapon.nb_damage / 2),
                weapon.type,
                data::weapon::statementCombo(weapon.name),
                1,
                0};
}

nlohmann::json write(const Weapon& weapon) {
  return {{"name", weapon.name},
          {"nb_damage", weapon.nb_damage},
          {"type", weapon.type},
          {"statement", weapon.statement},
          {"durability", weapon.durability},
          {"durability_loose_per_use", weapon.durability_loose_per_use}};
}

Weapon make_weapon(const nlohmann::json& json) {
  return Weapon{json["name"],       json["nb_damage"],
                json["type"],       json["statement"],
                json["durability"], json["durability_loose_per_use"]};
}

nlohmann::json write(const WeaponInventory& inventory) {
  nlohmann::json result;

  ranges::transform(inventory, ranges::back_inserter(result),
                    [](const auto& weapon) { return write(weapon); });

  return result;
}

WeaponInventory make_weapon_inventory(const nlohmann::json& json) {
  WeaponInventory weaponInventory;
  for (const nlohmann::json& json_weapon : json) {
    weaponInventory.insert(make_weapon(json_weapon));
  }
  return weaponInventory;
}

bool add(WeaponInventory& weaponInventory, Weapon&& weapon) {
  bool present = true;
  std::tie(std::ignore, present) = weaponInventory.insert(std::move(weapon));
  return not present;
}

bool contains(const WeaponInventory& weaponInventory, Type&& type) {
  return ranges::contains(weaponInventory, type,
                          [](const auto& weapon) { return weapon.type; });
}

void remove(WeaponInventory& weaponInventory, const std::string& name) {
  std::erase_if(weaponInventory,
                [&name](const auto& weapon) { return name == weapon.name; });
}

}  // namespace elevation::weapon
