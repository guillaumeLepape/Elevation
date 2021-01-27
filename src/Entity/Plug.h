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
        Weapon* const weapon_;

    public:
        explicit Plug
        ( 
            const std::string& name, 
            const int& nbLifePoints = 100, 
            Weapon* const weapon = new Fist() 
        );

        Weapon* weapon() const { return weapon_; }
};

#endif