#ifndef LEVEL_2_H
#define LEVEL_2_H

/*!
    * \file Level2.h
*/


#include "Level.h"

#include "../Message/Message.h"

class Level2 : public Level
{
    private:
        int levelNumber_;
    public:
        explicit Level2( Player* player ) : 
            Level(player),
            levelNumber_(2)
        {
            
        }
        void startLevel() override;
        ~Level2() {}
};

#endif