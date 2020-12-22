#ifndef LEVEL_4_H
#define LEVEL_4_H

/*!
    * \file Level4.h
*/

#include "Level.h"

#include "MessageHandler.h"

class Level4 : public Level
{   
    private:
        int levelNumber_;

        void firstQuestion( const MessageHandler& messageHandler );
        void secondQuestion( const MessageHandler& messageHandler );
        void thirdQuestion( const MessageHandler& messageHandler );

    public:
        explicit Level4( Player* player ) : 
            Level(player),
            levelNumber_(4)
        {

        }
        void startLevel() override;

        ~Level4() {}
};

#endif