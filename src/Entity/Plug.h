#ifndef PLUG_H
#define PLUG_H

/*!
    * \file Plug.h
*/

#include "Entity.h"

#include "Fist.h"

class Plug : public Entity
{
    private:
        const Weapon* weapon_;

    public:
        explicit Plug
        ( 
            const std::string& name, 
            const int& nbLifePoints = 100, 
            const Weapon* weapon = new Fist() 
        );

        void changeWeapon( const Weapon* newWeapon );

        const Weapon* weapon() const { return weapon_; }
};

#endif