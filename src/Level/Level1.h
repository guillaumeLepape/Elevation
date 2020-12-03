#ifndef LEVEL_1_H
#define LEVEL_1_H

/*!
    * \file Level1.h
*/

#include "Level.h"

class Level1 : public Level
{
    public:
        explicit Level1( Player* player ) : 
            Level(player) 
        {
            
        }
        void startLevel() override;
        ~Level1() { }
};

#endif