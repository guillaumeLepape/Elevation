#ifndef LEVEL_H
#define LEVEL_H

#include "../Player/Player.h"

class Level
{
    protected:
        Player* player_;

    public:
        Level( Player* player ) : 
            player_(player)
        {  
            
        }
        virtual void startLevel() = 0;
        virtual ~Level() {}
};

#endif