#ifndef LEVEL_6_H
#define LEVEL_6_H

/*!
    * \file Level6.h
*/

#include "Level.h"

class Level6 : public Level
{
    public:
        Level6( Player* const player ) :
            Level(player)
        {

        }

        void startLevel( const Options& options ) override;
};

#endif