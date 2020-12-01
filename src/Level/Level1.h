#ifndef LEVEL_1_H
#define LEVEL_1_H

#include "Level.h"

class Level1 : public Level
{
    public:
        Level1( Player* player ) : 
            Level(player) 
        {
            
        }
        void startLevel() override;
        ~Level1() { }
};

#endif