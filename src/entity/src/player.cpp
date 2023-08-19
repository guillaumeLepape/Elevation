#include "player.h"

#include <algorithm>
#include <iostream>

#include "results.h"

namespace entity {
Player::Player(const std::string& pseudo, int nbLevelSuceeded,
               weapon::WeaponInventory&& weaponInventory)
    : pseudo_{pseudo},
      nbLevelSuceeded_{nbLevelSuceeded},
      money_{200},
      weapons_{std::move(weaponInventory)},
      healthBar_{MAX_LIFE_POINTS_PLAYER, MAX_LIFE_POINTS_PLAYER} {}

Player::Player(const std::string& pseudo, int nbLevelSuceeded, int nbLifePoints,
               int maxLifePoints, int money, weapon::WeaponInventory&& weapons)
    : pseudo_{pseudo},
      nbLevelSuceeded_{nbLevelSuceeded},
      money_{money},
      weapons_{std::move(weapons)},
      healthBar_{nbLifePoints, maxLifePoints} {}

Player::Player(const nlohmann::json& jsonInput)
    : Player{jsonInput["pseudo"],
             jsonInput["nb_level_suceeded"],
             jsonInput["nb_life_points"],
             jsonInput["max_life_points"],
             jsonInput["money"],
             weapon::make_weapon_inventory(jsonInput["weapons"])} {}

nlohmann::json Player::write() const {
  return nlohmann::json{{"pseudo", pseudo_},
                        {"nb_level_suceeded", nbLevelSuceeded_},
                        {"nb_life_points", healthBar_.nbLifePoints()},
                        {"max_life_points", healthBar_.maxLifePoints()},
                        {"money", money_},
                        {"weapons", weapon::write(weapons_)}};
}

Player make_player_from_game_id(const std::string& id) {
  if (data::is_new_game(id)) {
    return Player{"Joueur", 0};
  } else {
    return Player{data::get_saved_data(id)["player"]};
  }
}

}  // namespace entity
