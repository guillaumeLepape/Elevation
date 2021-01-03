#ifndef LEVEL_4_H
#define LEVEL_4_H

/*!
    * \file Level4.h
*/

#include "Level.h"

class Level4 : public Level
{   
    private:
        int levelNumber_;

    public:
        explicit Level4( Player* player ) : 
            Level(player),
            levelNumber_(4)
        {

        }
        void startLevel( const Options& options ) override;

        ~Level4() {}
};

#endif