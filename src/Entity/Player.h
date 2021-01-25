#ifndef PLAYER_H
#define PLAYER_H

/*!
    * \file Player.h
    * \brief Player file containing player class
    * \author jessH
*/

#include <vector>
#include "Weapon.h"
#include "Entity.h"

/*!
    * \class Player class
    * \brief 
*/

class Player : public Entity
{
    private:
        /*< Unique id */
        std::string id_;

        /*< Number of level suceeded by the player */
        int nbLevelSuceeded_;    

        /*< Amount of money own by player */
        int money_;

        /*< List of weapons own by player */
        std::vector<const Weapon*> weapons_;
        
        /*< Price of the drug choosen */
        int price_;

        /*!
            * \brief Private Constructor 
            * 
            * Private Constructor of Player class
            * Used in readJson method to generate Player class 
            * from saved game
        */
        Player
        ( 
            const std::string& pseudo, 
            const std::string& id,
            const int& nbLevelSuceeded,
            const int& nbLifePoints,
            const int& money,
            const std::vector<const Weapon*>& weapons,
            const int& price
        );

    public:
        /*!
            * \brief Constructor 
            * 
            * Constructor of Player class
            * 
            * \param pseudo : pseudo for the player
            * \param id : unique id, used to save game
            * \param nbLevelSuceeded : number of level suceeded by player
        */
        Player( const std::string& pseudo, const std::string& id, const int& nbLevelSuceeded );

        void attack( Entity* entity ) override {}

        /*!
            * \brief id accesor, initialized at the creation of Player, unmodifiable argument
            * \return unique id 
        */
        const std::string& id() const { return id_; }

        /*!
            * \brief nbLevelSuceeded accesor
        */
        const int& nbLevelSuceeded() const { return nbLevelSuceeded_; }
        /*!
            * \brief when pass to next level, increment nbLevelSuceeded. Only way to modify nbLevelSuceeded argument 
        */
        void nextLevel() { nbLevelSuceeded_++; }

        void increaseMoney( const int& money ) { money_ += money; }

        void addWeapon( const Weapon* const weapon );
        void deleteWeapon( const std::string& nameWeapon );
        void deleteWeapon( const Weapon& weapon );
        const Weapon* weaponFromName( const std::string& nameWeapon ) const;
        
        bool containWeaponType( WeaponType weaponType );

        const std::vector<const Weapon*>& weapons() const { return weapons_; }

        const int& price() const { return price_; }
        void setPrice( const int& price ) { price_ = price; } 

        nlohmann::json writeJson() const;

        /*!
            * \brief 
            * 
            * Create Player instance from json file results
            * This result file contains all the previously saved game 
            * 
            * \param jsonInput : json object containing result from previous game
        */
        static Player* readJson( const nlohmann::json& jsonInput ); 

};  

#endif