#ifndef PLUG_H
#define PLUG_H

/*!
    * \file Plug.h
*/

#include <memory>

#include "Entity.h"

#include "NoWeapon.h"

class Plug : public Entity
{
    private:
        std::unique_ptr<const Weapon> weapon_;

    public:
        explicit Plug
        ( 
            const std::string& name, 
            const int& nbLifePoints = 100, 
            const Weapon* weapon = new NoWeapon() 
        );

        ~Plug() override = default;

        void changeWeapon( const Weapon* newWeapon );

        const Weapon* weapon() const { return weapon_.get(); }
};

#endif