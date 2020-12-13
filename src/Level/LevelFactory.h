#ifndef LEVEL_FACTORY_H
#define LEVEL_FACTORY_H

/*!
    * \file LevelFactory.h
*/ 

#include "../Level/Introduction.h"
#include "../Level/Level1.h"
#include "../Level/Level2.h"
#include "../Level/Level3.h"
#include "../Level/Level4.h"

class LevelFactory
{
    public:
        static Level* newLevel( Player* player, const int& levelNumber )
        {
            if ( levelNumber == 0 ) return new Introduction(player);
            if ( levelNumber == 1 ) return new Level1(player);
            if ( levelNumber == 2 ) return new Level2(player);
            if ( levelNumber == 3 ) return new Level3(player);
            if ( levelNumber == 4 ) return new Level4(player);
            assert(false); 
        }
};

#endif