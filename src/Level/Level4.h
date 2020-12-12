#ifndef LEVEL_4_H
#define LEVEL_4_H

#include "Level.h"
#include "../Plug/Plug.h"
#include "../Message/Message.h"

class Level4 : public Level
{
    public:
        explicit Level4( Player* player ) : Level(player)
        {

        }
        void startLevel() override;

        void firstQuestion( Plug* plug, const Message& message );
        void secondQuestion( Plug* plug, const Message& message );
        void thirdQuestion( Plug* plug, const Message& message );

        ~Level4() {}
};

#endif