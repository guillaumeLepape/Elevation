#ifndef PLUG_H
#define PLUG_H

/*!
    * \file Plug.h
*/

#include "Entity.h"
#include "NoWeapon.h"

class Plug : public Entity
{
    private:
        // const std::string name_;
        const int price_;
        // int lifePoints_;
        Weapon weapon_;

    public:
        explicit Plug
        ( 
            const std::string& name, 
            const int& price, 
            const int& nbLifePoints = 100, 
            const Weapon& weapon = NoWeapon() 
        );
        
        void attack( Entity* entity ) override {  }

        // const std::string& name() const { return name_; }
        const int& price() const { return price_; }

        // const int& lifePoints() const { return lifePoints_; }
        // void decreaseLifePoints( const int& lifePoints) { lifePoints_ -= lifePoints; } 

        // bool deadOrNot() const { return (lifePoints_ <= 0); }

        const Weapon& weapon() const { return weapon_; }
};

#endif