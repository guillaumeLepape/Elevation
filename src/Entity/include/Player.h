#ifndef PLAYER_H
#define PLAYER_H

#include "HealthBar.h"
#include "Weapon.h"

static constexpr int MAX_LIFE_POINTS_PLAYER = 100;

namespace entity {
class Player {
 private:
  std::string pseudo_;
  unsigned int id_;
  int nbLevelSuceeded_;
  int money_;
  weapon::WeaponInventory weapons_;
  HealthBar healthBar_;

 public:
  Player(
      const std::string& pseudo, const unsigned int& id,
      const int& nbLevelSuceeded,
      weapon::WeaponInventory&& weaponInventory = []() {
        weapon::WeaponInventory result;
        result.insert(weapon::Fist());
        return result;
      }());

  Player(const std::string& pseudo, const unsigned int& id,
         const int& nbLevelSuceeded, const int& nbLifePoints,
         const int& maxLifePoints, const int& money,
         weapon::WeaponInventory&& weapons);

  Player(const nlohmann::json& jsonInput);

  Player(const Player&) = delete;
  Player(Player&&) = default;

  Player& operator=(const Player&) = delete;
  Player& operator=(Player&&) = default;

  virtual ~Player() = default;

  const std::string& pseudo() const { return pseudo_; }
  void changePseudo(const std::string& pseudo) { pseudo_ = pseudo; }

  const unsigned int& id() const { return id_; }

  const int& nbLevelSuceeded() const { return nbLevelSuceeded_; }
  void nextLevel() { nbLevelSuceeded_++; }

  void increaseMoney(const int& money) { money_ += money; }
  void decreaseMoney(const int& money) { money_ -= money; }

  weapon::WeaponInventory& weapons() { return weapons_; }

  nlohmann::json write() const;

  const HealthBar& healthBar() const { return healthBar_; }
  HealthBar& healthBar() { return healthBar_; }
};

template <typename Entity>
void attack(Entity* const entity, const weapon::Weapon& weapon) {
  if (weapon.durability > 0) {
    entity->healthBar().decreaseLifePoints(weapon.nb_damage);
    weapon.durability -= weapon.durability_loose_per_use;
  }
}
}  // namespace entity
#endif