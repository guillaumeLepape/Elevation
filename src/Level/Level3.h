#ifndef LEVEL_3_H
#define LEVEL_3_H

/*!
    * \file Level3.h
*/

#include "Level.h"

class Level3 : public Level
{
    private:
        int levelNumber_;

    public:
        explicit Level3( Player* player ) : 
            Level(player),
            levelNumber_(3)
        {
            
        }
        void startLevel() override;
        ~Level3() {}
};

#endif