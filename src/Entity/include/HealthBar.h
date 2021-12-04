#ifndef HEALTH_BAR_H
#define HEALTH_BAR_H

class HealthBar {
 private:
  int nbLifePoints_;
  int maxNbLifePoints_;

 public:
  constexpr HealthBar(int nbLifePoints, int maxNbLifePoints)
      : nbLifePoints_{nbLifePoints}, maxNbLifePoints_{maxNbLifePoints} {}

  const int& nbLifePoints() const { return nbLifePoints_; }

  int missingLifePoints() const { return maxNbLifePoints_ - nbLifePoints_; }

  const int& maxLifePoints() const { return maxNbLifePoints_; }

  void increaseLifePoints(const int& nbLifePoints) {
    if (nbLifePoints_ + nbLifePoints >= maxNbLifePoints_) {
      nbLifePoints_ = maxNbLifePoints_;
    } else {
      nbLifePoints_ += nbLifePoints;
    }
  }
  void decreaseLifePoints(const int& nbLifePoints) {
    nbLifePoints_ -= nbLifePoints;
  }
  void increaseMaxLifePoints(int maxNbLifePoints) {
    maxNbLifePoints_ += maxNbLifePoints;
    nbLifePoints_ += maxNbLifePoints;
  }
  bool fullLife() const { return nbLifePoints_ == maxNbLifePoints_; }
  bool dead() const { return (nbLifePoints_ <= 0); }
};

#endif