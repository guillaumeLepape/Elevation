#ifndef LEVEL_7_H
#define LEVEL_7_H

/*!
    * \file "Level7.h"
*/

#include "Level.h"

class Level7 : public Level
{
    public:
        Level7( Player* const player ) :    
            Level(player)
        {

        }

        void startLevel( const Options& options ) override;
};

#endif