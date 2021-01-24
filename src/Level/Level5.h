#ifndef LEVEL_5_H
#define LEVEL_5_H

/*!
    * \file Level5.h
*/

#include "Level.h"

class Level5 : public Level
{
    public:
        explicit Level5( Player* player ) :
            Level(player)
        {

        }

        void startLevel( const Options& options ) override;

        ~Level5() override = default;
};

#endif