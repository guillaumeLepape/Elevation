#ifndef LEVEL_2_H
#define LEVEL_2_H

#include "Level.h"

#include "../Message/Message.h"

class Level2 : public Level
{
    public:
        explicit Level2( Player* player ) : Level(player)
        {
            
        }
        void startLevel() override;
        void negociate( const Message& message, Player* player, Plug* plug );
        ~Level2() {}
};

#endif