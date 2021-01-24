#ifndef INTRODUCTION_H
#define INTRODUCTION_H

/*!
    * \file Introduction.h
*/

#include "Level.h"

class Introduction : public Level
{
    public:
        explicit Introduction( Player* player ) : 
            Level(player)
        {

        }

        void startLevel( const Options& options ) override;
};

#endif