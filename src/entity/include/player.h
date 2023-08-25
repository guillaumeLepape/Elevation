#ifndef PLAYER_H
#define PLAYER_H

#include "health_bar.h"
#include "weapon.h"

static constexpr int MAX_LIFE_POINTS_PLAYER = 100;

namespace entity {
class Player {
 private:
  std::string pseudo_;
  int nbLevelSuceeded_;
  int money_;
  weapon::WeaponInventory weapons_;
  HealthBar healthBar_;

 public:
  Player(const std::string& pseudo, int nbLevelSuceeded,
         weapon::WeaponInventory&& weaponInventory = weapon::WeaponInventory{
             weapon::Fist()});

  Player(const std::string& pseudo, int nbLevelSuceeded, int nbLifePoints,
         int maxLifePoints, int money, weapon::WeaponInventory&& weapons);

  explicit Player(unsigned id);

  explicit Player(const nlohmann::json& jsonInput);

  Player(const Player&) = delete;
  Player(Player&&) = default;

  Player& operator=(const Player&) = delete;
  Player& operator=(Player&&) = default;

  ~Player() = default;

  [[nodiscard]] const std::string& pseudo() const { return pseudo_; }
  void changePseudo(const std::string& pseudo) { pseudo_ = pseudo; }

  [[nodiscard]] int nbLevelSuceeded() const { return nbLevelSuceeded_; }
  void nextLevel() { nbLevelSuceeded_++; }

  void increaseMoney(int money) { money_ += money; }
  void decreaseMoney(int money) { money_ -= money; }

  weapon::WeaponInventory& weapons() { return weapons_; }

  [[nodiscard]] nlohmann::json write() const;

  [[nodiscard]] const HealthBar& healthBar() const { return healthBar_; }
  HealthBar& healthBar() { return healthBar_; }
};

template <typename Entity>
void attack(Entity& entity, const weapon::Weapon& weapon) {
  if (weapon.durability > 0) {
    entity.healthBar().decreaseLifePoints(weapon.nb_damage);
    weapon.durability -= weapon.durability_loose_per_use;
  }
}

Player make_player_from_game_id(const std::string& id);

}  // namespace entity
#endif
