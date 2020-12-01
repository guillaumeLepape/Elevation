#ifndef LEVEL_2_H
#define LEVEL_2_H

#include "Level.h"

class Level2 : public Level
{
    public:
        explicit Level2( Player* player ) : Level(player)
        {
            
        }
        void startLevel() override;
        ~Level2() {}
};

#endif