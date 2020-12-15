#ifndef INTRODUCTION_H
#define INTRODUCTION_H

/*!
    * \file Introduction.h
*/

#include "Level.h"

class Introduction : public Level
{
    private:
        const int levelNumber_;

    public:
        explicit Introduction( Player* player ) : 
            Level(player),
            levelNumber_(0) 
        {

        }

        void startLevel() override;
};

#endif