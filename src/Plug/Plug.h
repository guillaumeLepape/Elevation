#ifndef PLUG_H
#define PLUG_H

/*!
    * \file Plug.h
*/

#include "Weapon.h"

class Plug 
{
    private:
        const std::string name_;
        const int price_;
        int lifePoints_;
        Weapon weapon_;

    public:
        explicit Plug
        ( 
            const std::string& name, 
            const int& price, 
            const int& lifePoints = 100, 
            const Weapon& weapon = Weapon() 
        );
        
        const std::string& name() const { return name_; }
        const int& price() const { return price_; }

        const int& lifePoints() const { return lifePoints_; }
        void decreaseLifePoints( const int& lifePoints) { lifePoints_ -= lifePoints; } 

        const bool deadOrNot() const { return (lifePoints_ <= 0); }

        const Weapon& weapon() const { return weapon_; }
};

#endif