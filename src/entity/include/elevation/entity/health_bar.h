#pragma once

namespace elevation::entity {
class HealthBar {
 private:
  int nbLifePoints_;
  int maxNbLifePoints_;

 public:
  constexpr HealthBar(int nbLifePoints, int maxNbLifePoints)
      : nbLifePoints_{nbLifePoints}, maxNbLifePoints_{maxNbLifePoints} {}

  [[nodiscard]] int nbLifePoints() const { return nbLifePoints_; }

  [[nodiscard]] int missingLifePoints() const {
    return maxNbLifePoints_ - nbLifePoints_;
  }

  [[nodiscard]] int maxLifePoints() const { return maxNbLifePoints_; }

  void increaseLifePoints(int nbLifePoints) {
    if (nbLifePoints_ + nbLifePoints >= maxNbLifePoints_) {
      nbLifePoints_ = maxNbLifePoints_;
    } else {
      nbLifePoints_ += nbLifePoints;
    }
  }
  void decreaseLifePoints(int nbLifePoints) { nbLifePoints_ -= nbLifePoints; }
  void increaseMaxLifePoints(int maxNbLifePoints) {
    maxNbLifePoints_ += maxNbLifePoints;
    nbLifePoints_ += maxNbLifePoints;
  }
  [[nodiscard]] bool fullLife() const {
    return nbLifePoints_ == maxNbLifePoints_;
  }
  [[nodiscard]] bool dead() const { return (nbLifePoints_ <= 0); }
  [[nodiscard]] bool alive() const { return not dead(); }
};
}  // namespace elevation::entity
