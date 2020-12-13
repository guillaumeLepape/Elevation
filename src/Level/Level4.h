#ifndef LEVEL_4_H
#define LEVEL_4_H

#include "Level.h"
#include "../Plug/Plug.h"
#include "../Message/Message.h"

class Level4 : public Level
{   
    private:
        void firstQuestion( Plug* plug, const Message& message );
        void secondQuestion( Plug* plug, const Message& message );
        void thirdQuestion( Plug* plug, const Message& message );

    public:
        explicit Level4( Player* player ) : Level(player)
        {

        }
        void startLevel() override;

        ~Level4() {}
};

#endif