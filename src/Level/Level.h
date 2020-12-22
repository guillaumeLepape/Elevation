#ifndef LEVEL_H
#define LEVEL_H

/*!
    * \file Level.h
*/

#include "Player.h"

class Level
{
    protected:
        Player* player_;

    public:
        explicit Level( Player* player ) : 
            player_(player)
        {  
            
        }
        virtual void startLevel() = 0;
        virtual ~Level() {}
};

#endif