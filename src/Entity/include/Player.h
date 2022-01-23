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
  Player(const std::string& pseudo, unsigned int id, int nbLevelSuceeded,
         weapon::WeaponInventory&& weaponInventory = weapon::WeaponInventory{
             weapon::Fist()});

  Player(const std::string& pseudo, unsigned int id, int nbLevelSuceeded,
         int nbLifePoints, int maxLifePoints, int money,
         weapon::WeaponInventory&& weapons);

  Player(const nlohmann::json& jsonInput);

  Player(const Player&) = delete;
  Player(Player&&) = default;

  Player& operator=(const Player&) = delete;
  Player& operator=(Player&&) = default;

  ~Player() = default;

  const std::string& pseudo() const { return pseudo_; }
  void changePseudo(const std::string& pseudo) { pseudo_ = pseudo; }

  unsigned int id() const { return id_; }

  int nbLevelSuceeded() const { return nbLevelSuceeded_; }
  void nextLevel() { nbLevelSuceeded_++; }

  void increaseMoney(int money) { money_ += money; }
  void decreaseMoney(int money) { money_ -= money; }

  weapon::WeaponInventory& weapons() { return weapons_; }

  nlohmann::json write() const;

  const HealthBar& healthBar() const { return healthBar_; }
  HealthBar& healthBar() { return healthBar_; }
};

template <typename Entity>
void attack(Entity& entity, const weapon::Weapon& weapon) {
  if (weapon.durability > 0) {
    entity.healthBar().decreaseLifePoints(weapon.nb_damage);
    weapon.durability -= weapon.durability_loose_per_use;
  }
}
}  // namespace entity
#endif