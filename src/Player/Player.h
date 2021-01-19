#ifndef PLAYER_H
#define PLAYER_H

/*!
    * \file Player.h
*/

#include <vector>
#include "Weapon.h"

class Player
{
    private:
        std::string pseudo_;    
        std::string id_;
        int nbLevelSuceeded_;    
        int nbLifePoints_;
        int money_;
        std::vector<Weapon> weapons_;
        int selectedWeapon_;
        int price_;

        Player
        ( 
            const std::string& pseudo, 
            const std::string& id,
            const int& nbLevelSuceeded,
            const int& nbLifePoints,
            const int& money,
            const std::vector<Weapon>& weapons,
            const int& price
        );

    public:
        Player( const std::string& pseudo, const std::string& id, const int& nbLevelSuceeded );
        void printState();

        const std::string& id() const { return id_; }

        const std::string& pseudo() const { return pseudo_; }
        void setPseudo( const std::string& pseudo ) { pseudo_ = pseudo; } 

        const int& nbLevelSuceeded() const { return nbLevelSuceeded_; }
        void nextLevel() { nbLevelSuceeded_++; }

        const int& nbLifePoints() const { return nbLifePoints_; }

        void decreaseLifePoints( const int& nbLifePoints ) { nbLifePoints_ -= nbLifePoints; }

        void increaseMoney( const int& money ) { money_ += money; }

        bool dead() const { return nbLifePoints_ <= 0; }

        void changeWeapon( const std::string& nameWeapon ); 
        void addWeapon( const Weapon& weapon );
        void deleteWeapon( const std::string& nameWeapon );
        const Weapon& weaponFromName( const std::string& nameWeapon ) const;
        const Weapon& selectedWeapon() const { return weapons_[selectedWeapon_]; }
        
        bool containWeaponType( WeaponType weaponType );

        const std::vector<Weapon>& weapons() const { return weapons_; }

        const int& price() const { return price_; }
        void setPrice( const int& price ) { price_ = price; } 

        nlohmann::json writeJson() const;
        static Player* readJson( const nlohmann::json& jsonInput ); 

};  

#endif