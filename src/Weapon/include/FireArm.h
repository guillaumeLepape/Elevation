#ifndef FIRE_ARM_H
#define FIRE_ARM_H

/*!
 * \file FireArm.h
 */

#include "Languages.h"
#include "Weapon.h"

static auto writeJsonFireArm = [](const std::string& name,
                                  int nbAmmo) -> nlohmann::json {
  return {{"name", name}, {"nbAmmo", nbAmmo}};
};

struct FireArm : Weapon {
  virtual int nbAmmo() const = 0;
  virtual int nbAmmoForOneShot() const = 0;
  virtual ~FireArm() = default;
};

#endif