#ifndef NINE_MM_H
#define NINE_MM_H

/*!
    * \file Ninemm.h
*/

#include "FireArm.h"

class Ninemm : public FireArm
{
    public:
        Ninemm( const int& nbAmmo ) :
            FireArm( "9mm", 70, nbAmmo )
        {

        }

        ~Ninemm() override = default;
};

#endif