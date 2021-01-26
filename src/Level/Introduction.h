#ifndef INTRODUCTION_H
#define INTRODUCTION_H

/*!
    * \file Introduction.h
*/

#include "Level.h"

class Introduction : public Level
{
    public:
        explicit Introduction( Player* player, const Options& options ) : 
            Level(player, options)
        {

        }

        void startLevel() override;
        ~Introduction() override = default;
};

#endif