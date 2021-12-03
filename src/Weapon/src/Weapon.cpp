#include "Weapon.h"

namespace weapon {
Weapon NoWeapon() {
  return Weapon{data::Weapon::nameNoWeapon,         0, Type::noWeapon,
                data::Weapon::statementUseNoWeapon, 1, 0};
}
Weapon Fist() {
  return Weapon{data::Weapon::nameFist,         20, Type::fist,
                data::Weapon::statementUseFist, 1,  0};
}
Weapon DivineStrike() {
  return Weapon{data::Weapon::nameDivineStrike,      1000, Type::fist,
                data::Weapon::statementDivineStrike, 1,    0};
}
Weapon Chopper() {
  return Weapon{data::Weapon::nameChopper,         80, Type::meleeWeapon,
                data::Weapon::statementUseChopper, 1,  0};
}
Weapon Cutter() {
  return Weapon{data::Weapon::nameCutter,         15, Type::meleeWeapon,
                data::Weapon::statementUseCutter, 1,  0};
}
Weapon Hammer() {
  return Weapon{data::Weapon::nameHammer,         40, Type::meleeWeapon,
                data::Weapon::statementUseHammer, 1,  0};
}
Weapon Heroine() {
  return Weapon{data::Weapon::nameHeroine, 50, Type::meleeWeapon, "", 1, 0};
}
Weapon Katana() {
  return Weapon{data::Weapon::nameKatana,         50, Type::meleeWeapon,
                data::Weapon::statementUseKatana, 1,  0};
}
Weapon Knife() {
  return Weapon{data::Weapon::nameKnife,         30, Type::meleeWeapon,
                data::Weapon::statementUseKnife, 1,  0};
}
Weapon Ninemm(int nb_ammo) {
  return Weapon{data::Weapon::nameNinemm,         70,      Type::fireArm,
                data::Weapon::statementUseNinemm, nb_ammo, 1};
}
Weapon AK47(int nb_ammo) {
  return Weapon{data::Weapon::nameAK47,         150,     Type::fireArm,
                data::Weapon::statementUseAK47, nb_ammo, 10};
}
Weapon WeaponFistCombo(const Weapon& weapon) {
  return Weapon{weapon.name + "FistCombo",
                static_cast<int>(weapon.nb_damage / 2),
                weapon.type,
                data::Weapon::statementCombo(weapon.name),
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
  std::for_each(
      std::cbegin(inventory), std::cend(inventory),
      [&result](const auto& weapon) { result.push_back(write(weapon)); });
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
  return !present;
}

bool contains(const WeaponInventory& weaponInventory, Type&& type) {
  return std::find_if(std::cbegin(weaponInventory), std::cend(weaponInventory),
                      [&type](const auto& weapon) {
                        return type == weapon.type;
                      }) != std::cend(weaponInventory);
}

void remove(WeaponInventory& weaponInventory, const std::string& name) {
  weaponInventory.erase(std::find_if(
      std::cbegin(weaponInventory), std::cend(weaponInventory),
      [&name](const auto& weapon) { return name == weapon.name; }));
}

}  // namespace weapon