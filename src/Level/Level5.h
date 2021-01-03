#ifndef LEVEL_5_H
#define LEVEL_5_H

/*!
    * \file Level5.h
*/

#include "Level.h"

class Level5 : public Level
{
    private:
        int levelNumber_;

    public:
        explicit Level5( Player* player ) :
            Level(player),
            levelNumber_(5)
        {

        }

        void startLevel( const Options& options ) override;

        ~Level5() {}
};

#endif