#ifndef LEVEL_H
#define LEVEL_H

/*!
    * \file Level.h
*/

#include "Player.h"
#include "Options.h"

class Level
{
    protected:
        Player* player_;

    public:
        explicit Level( Player* player ) : 
            player_(player)
        {  
            
        }
        virtual void startLevel( const Options& options ) = 0;
        virtual ~Level() {}
};

#endif