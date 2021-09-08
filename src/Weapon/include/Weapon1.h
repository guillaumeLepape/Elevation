#include <nlohmann/json.hpp>
#include <string_view>

#include "Entity.h"

struct Weapon1 {
  std::string_view name;
  int nb_damage;
};

struct FireArm1 : Weapon1 {
  mutable int nb_ammo;
};

template <typename T>
void attack(Entity& entity, const T& weapon) {
  entity.decreaseLifePoints(weapon.nb_damage);
}

template <>
void attack(Entity& entity, const FireArm1& weapon) {
  weapon.nb_ammo--;
  entity.decreaseLifePoints(weapon.nb_damage);
}

template <typename T>
nlohmann::json writeJson(const T& weapon) {
  return {{"name", weapon.name}};
}

template <>
nlohmann::json writeJson(const FireArm1& weapon) {
  return {{"name", weapon.name}, {"nbAmmo", weapon.nb_ammo}};
}
