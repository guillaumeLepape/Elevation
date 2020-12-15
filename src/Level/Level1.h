#ifndef LEVEL_1_H
#define LEVEL_1_H

/*!
    * \file Level1.h
*/

#include "Level.h"

class Level1 : public Level
{
    private:
        int levelNumber_;

    public:
        explicit Level1( Player* player ) : 
            Level(player),
            levelNumber_(1)
        {
            
        }
        void startLevel() override;
        ~Level1() { }
};

#endif