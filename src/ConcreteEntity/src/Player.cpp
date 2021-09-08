/*!
 * \file Player.cpp
 */

#include "Player.h"

#include <algorithm>
#include <cassert>
#include <iostream>

#include "WeaponFactory.h"

Player::Player(const std::string& pseudo, const int& id,
               const int& nbLevelSuceeded, WeaponInventory&& weaponInventory)
    : Entity(pseudo, MAX_LIFE_POINTS_PLAYER, MAX_LIFE_POINTS_PLAYER),
      id_(id),
      nbLevelSuceeded_(nbLevelSuceeded),
      money_(200),
      weapons_(std::move(weaponInventory)) {}

Player::Player(const std::string& pseudo, const int& id,
               const int& nbLevelSuceeded, const int& nbLifePoints,
               const int& maxLifePoints, const int& money,
               WeaponInventory&& weapons)
    : Entity(pseudo, nbLifePoints, maxLifePoints),
      id_(id),
      nbLevelSuceeded_(nbLevelSuceeded),
      money_(money),
      weapons_(std::move(weapons)) {}

nlohmann::json Player::writeJson() const {
  nlohmann::json jsonObjectOutput{{"pseudo", name_},
                                  {"id", id_},
                                  {"nbLevelSuceeded", nbLevelSuceeded_},
                                  {"nbLifePoints", nbLifePoints_},
                                  {"maxLifePoints", maxNbLifePoints_},
                                  {"money", money_},
                                  {"weapons", weapons_.writeJson()}};

  return jsonObjectOutput;
}

Player* Player::readJson(const nlohmann::json& jsonInput) {
  return new Player(jsonInput["pseudo"], jsonInput["id"],
                    jsonInput["nbLevelSuceeded"], jsonInput["nbLifePoints"],
                    jsonInput["maxLifePoints"], jsonInput["money"],
                    WeaponInventory::readJson(jsonInput["weapons"]));
}
