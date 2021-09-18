#ifndef PLUG_H
#define PLUG_H

/*!
 * \file Plug.h
 */

#include <memory>

#include "Entity.h"
#include "NoWeapon.h"

class Plug : public Entity {
 private:
  std::unique_ptr<const Weapon> weapon_;

 public:
  Plug(const std::string& name, const int& nbLifePoints = 100,
       std::unique_ptr<const Weapon>&& weapon =
           std::unique_ptr<const Weapon>(new NoWeapon()));

  Plug(const Plug&) = delete;
  Plug(Plug&&) = default;

  Plug& operator=(const Plug&) = delete;
  Plug& operator=(Plug&&) = default;

  virtual ~Plug() = default;

  void changeWeapon(const Weapon* newWeapon);

  const Weapon* weapon() const { return weapon_.get(); }
  std::unique_ptr<const Weapon> realeaseWeapon() { return std::move(weapon_); }
};

#endif