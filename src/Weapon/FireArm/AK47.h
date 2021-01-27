#ifndef AK_47_H
#define AK_47_H

/*!
    * \file AK47.h
*/

#include "FireArm.h"

#include "Languages.h"

class AK47 : public FireArm
{
    public:
        AK47( const int& nbAmmo ) :
            FireArm( data::Weapon::nameAK47, 90, nbAmmo, data::Weapon::statementUseAK47 )
        {

        }

        ~AK47() override = default;
};

#endif