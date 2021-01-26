#ifndef LEVEL_4_H
#define LEVEL_4_H

/*!
    * \file Level4.h
*/

#include "Level.h"

class Level4 : public Level
{   
    public:
        explicit Level4( Player* player, const Options& options ) : 
            Level(player, options)
        {

        }
        void startLevel() override;

        ~Level4() override = default;
};

#endif