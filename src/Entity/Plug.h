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
        Weapon* const weapon_;

    public:
        explicit Plug
        ( 
            const std::string& name, 
            const int& price, 
            const int& nbLifePoints = 100, 
            Weapon* const weapon = new NoWeapon() 
        );

        // const std::string& name() const { return name_; }
        const int& price() const { return price_; }

        Weapon* weapon() const { return weapon_; }
};

#endif