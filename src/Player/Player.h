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
        int nbLifePoints_;
        int money_;
        bool dead_;
        std::vector<Weapon> weapons_;
        int selectedWeapon_;
        int price_;

    public:
        Player();
        void printState();

        const std::string& pseudo() const { return pseudo_; }
        void setPseudo( const std::string& pseudo ) { pseudo_ = pseudo; } 

        void increaseMoney( const int& money ) { money_ += money; }

        const bool& dead() const { return dead_; }
        void setDead( const bool& dead ) { dead_ = dead; }

        void changeWeapon( const std::string& nameWeapon ); 
        void addWeapon( const Weapon& weapon ) { weapons_.push_back( weapon ); }
        const Weapon& weaponFromName( const std::string& nameWeapon ) const;
        const Weapon& selectedWeapon() const { return weapons_[selectedWeapon_]; }

        const int& price() const { return price_; }
        void setPrice( const int& price ) { price_ = price; } 
};  

#endif