#ifndef NINE_MM_H
#define NINE_MM_H

/*!
    * \file Ninemm.h
*/

#include "FireArm.h"

#include "Languages.h"

class Ninemm : public FireArm
{
    public:
        Ninemm( const int& nbAmmo ) :
            FireArm( data::Weapon::nameNinemm, 70, nbAmmo, 1, data::Weapon::statementUseNinemm )
        {

        }

        ~Ninemm() override = default;
};

#endif