#ifndef PLAYER_H
#define PLAYER_H

/*!
 * \file Player.h
 * \brief Player file containing player class
 * \author jessH
 */

#include "Entity.h"

static constexpr int MAX_LIFE_POINTS_PLAYER = 100;

/*!
 * \class Player class
 * \brief
 */

class Player : public Entity {
 private:
  /*< Unique id */
  int id_;

  /*< Number of level suceeded by the player */
  int nbLevelSuceeded_;

  /*< Amount of money own by player */
  int money_;

  /*< List of weapons own by player */
  weapon::WeaponInventory weapons_;

 public:
  /*!
   * \brief Private Constructor
   *
   * Private Constructor of Player class
   * Used in readJson method to generate Player class
   * from saved game
   */
  Player(const std::string& pseudo, const int& id, const int& nbLevelSuceeded,
         const int& nbLifePoints, const int& maxLifePoints, const int& money,
         weapon::WeaponInventory&& weapons);

  Player(const nlohmann::json& jsonInput);

  /*!
   * \brief Constructor
   *
   * Constructor of Player class
   *
   * \param pseudo : pseudo for the player
   * \param id : unique id, used to save game
   * \param nbLevelSuceeded : number of level suceeded by player
   */
  Player(const std::string& pseudo, const int& id, const int& nbLevelSuceeded,
         weapon::WeaponInventory&& weaponInventory = []() {
           weapon::WeaponInventory result;
           result.insert(weapon::Fist());
           return result;
         }());

  Player(const Player&) = delete;
  Player(Player&&) = default;

  Player& operator=(const Player&) = delete;
  Player& operator=(Player&&) = default;

  virtual ~Player() = default;

  /*!
   * \brief id accesor, initialized at the creation of Player, unmodifiable
   * argument \return unique id
   */
  const int& id() const { return id_; }

  /*!
   * \brief nbLevelSuceeded accesor
   */
  const int& nbLevelSuceeded() const { return nbLevelSuceeded_; }
  /*!
   * \brief when pass to next level, increment nbLevelSuceeded. Only way to
   * modify nbLevelSuceeded argument
   */
  void nextLevel() { nbLevelSuceeded_++; }

  void increaseMoney(const int& money) { money_ += money; }
  void decreaseMoney(const int& money) { money_ -= money; }

  /*!
   * \brief Accesor to weapon inventory
   * \return Reference to weapon inventory
   */
  weapon::WeaponInventory& weapons() { return weapons_; }

  nlohmann::json writeJson() const;
};

#endif