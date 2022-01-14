#include "Player.h"

#include <algorithm>
#include <cassert>
#include <iostream>

namespace entity {
Player::Player(const std::string& pseudo, const unsigned int& id,
               const int& nbLevelSuceeded,
               weapon::WeaponInventory&& weaponInventory)
    : pseudo_{pseudo},
      id_{id},
      nbLevelSuceeded_{nbLevelSuceeded},
      money_{200},
      weapons_{std::move(weaponInventory)},
      healthBar_{MAX_LIFE_POINTS_PLAYER, MAX_LIFE_POINTS_PLAYER} {}

Player::Player(const std::string& pseudo, const unsigned int& id,
               const int& nbLevelSuceeded, const int& nbLifePoints,
               const int& maxLifePoints, const int& money,
               weapon::WeaponInventory&& weapons)
    : pseudo_{pseudo},
      id_{id},
      nbLevelSuceeded_{nbLevelSuceeded},
      money_{money},
      weapons_{std::move(weapons)},
      healthBar_{nbLifePoints, maxLifePoints} {}

Player::Player(const nlohmann::json& jsonInput)
    : Player{jsonInput["pseudo"],
             jsonInput["id"],
             jsonInput["nbLevelSuceeded"],
             jsonInput["nbLifePoints"],
             jsonInput["maxLifePoints"],
             jsonInput["money"],
             weapon::make_weapon_inventory(jsonInput["weapons"])} {}

nlohmann::json Player::write() const {
  nlohmann::json jsonObjectOutput{{"pseudo", pseudo_},
                                  {"id", id_},
                                  {"nbLevelSuceeded", nbLevelSuceeded_},
                                  {"nbLifePoints", healthBar_.nbLifePoints()},
                                  {"maxLifePoints", healthBar_.maxLifePoints()},
                                  {"money", money_},
                                  {"weapons", weapon::write(weapons_)}};

  return jsonObjectOutput;
}
}  // namespace entity