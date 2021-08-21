/*!
 * \file Player.cpp
 */

#include "Player.h"

#include <algorithm>
#include <cassert>
#include <iostream>

#include "WeaponFactory.h"

Player::Player(const std::string& pseudo, const int& id,
               const int& nbLevelSuceeded)
    : Entity(pseudo, MAX_LIFE_POINTS_PLAYER, MAX_LIFE_POINTS_PLAYER),
      id_(id),
      nbLevelSuceeded_(nbLevelSuceeded),
      money_(200),
      weapons_(1, new Fist()) {}

Player::Player(const std::string& pseudo, const int& id,
               const int& nbLevelSuceeded, const int& nbLifePoints,
               const int& maxLifePoints, const int& money,
               const std::list<const Weapon*>& weapons)
    : Entity(pseudo, nbLifePoints, maxLifePoints),
      id_(id),
      nbLevelSuceeded_(nbLevelSuceeded),
      money_(money),
      weapons_(weapons) {}

nlohmann::json Player::writeJson() const {
  nlohmann::json jsonWeaponArray;
  for (auto w = weapons_.cbegin(); w != weapons_.cend(); w++) {
    jsonWeaponArray.push_back((*w)->writeJson());
  }

  nlohmann::json jsonObjectOutput{{"pseudo", name_},
                                  {"id", id_},
                                  {"nbLevelSuceeded", nbLevelSuceeded_},
                                  {"nbLifePoints", nbLifePoints_},
                                  {"maxLifePoints", maxNbLifePoints_},
                                  {"money", money_},
                                  {"weapons", jsonWeaponArray}};

  return jsonObjectOutput;
}

Player* Player::readJson(const nlohmann::json& jsonInput) {
  std::list<const Weapon*> weapons;
  std::transform(jsonInput["weapons"].cbegin(), jsonInput["weapons"].cend(),
                 std::back_inserter(weapons), [](const auto& weaponJson) {
                   if (weaponJson.count("nbAmmo")) {
                     return WeaponFactory::newFireArm(weaponJson["name"],
                                                      weaponJson["nbAmmo"]);
                   } else {
                     return WeaponFactory::newWeapon(weaponJson["name"]);
                   }
                 });

  Player* player =
      new Player(jsonInput["pseudo"], jsonInput["id"],
                 jsonInput["nbLevelSuceeded"], jsonInput["nbLifePoints"],
                 jsonInput["maxLifePoints"], jsonInput["money"], weapons);

  return player;
}
