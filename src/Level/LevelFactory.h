#ifndef LEVEL_FACTORY_H
#define LEVEL_FACTORY_H

/*!
    * \file LevelFactory.h
*/ 

#include "../Level/Introduction.h"
#include "../Level/Level1.h"
#include "../Level/Level2.h"
#include "../Level/Level3.h"
// #include "../Level/Level4.h"
// #include "../Level/Level5.h"

class LevelFactory
{
    public:
        static std::unique_ptr<Level> newLevel( Player* player, const int& levelNumber )
        {
            if ( levelNumber == 0 ) return std::make_unique<Introduction>(player);
            if ( levelNumber == 1 ) return std::make_unique<Level1>(player);
            if ( levelNumber == 2 ) return std::make_unique<Level2>(player);
            if ( levelNumber == 3 ) return std::make_unique<Level3>(player);
            // if ( levelNumber == 4 ) return std::make_unique<Level4>(player);
            // if ( levelNumber == 5 ) return std::make_unique<Level5>(player);
            assert(false); 
        }
};

#endif