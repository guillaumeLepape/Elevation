#ifndef LEVEL_3_H
#define LEVEL_3_H

#include "Level.h"

#include "../Message/Message.h"

class Level3 : public Level
{
    public:
        explicit Level3( Player* player ) : Level(player)
        {
            
        }
        void startLevel() override;
        ~Level3() {}
};

#endif