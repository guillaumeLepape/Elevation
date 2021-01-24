#ifndef LEVEL_FACTORY_H
#define LEVEL_FACTORY_H

/*!
    * \file LevelFactory.h
*/ 

#include "Introduction.h"
#include "Level1.h"
#include "Level2.h"
#include "Level3.h"
#include "Level4.h"
#include "Level5.h"
#include "Level6.h"
#include "Level7.h"

static constexpr int NB_LEVEL = 8;

class LevelFactory
{
    public:
        static std::unique_ptr<Level> newLevel( Player* player, const int& levelNumber )
        {
            if ( levelNumber == 0 ) return std::make_unique<Introduction>(player);
            if ( levelNumber == 1 ) return std::make_unique<Level1>(player);
            if ( levelNumber == 2 ) return std::make_unique<Level2>(player);
            if ( levelNumber == 3 ) return std::make_unique<Level3>(player);
            if ( levelNumber == 4 ) return std::make_unique<Level4>(player);
            if ( levelNumber == 5 ) return std::make_unique<Level5>(player);
            if ( levelNumber == 6 ) return std::make_unique<Level6>(player);
            if ( levelNumber == 7 ) return std::make_unique<Level7>(player);
            assert(false); 
        }
};

#endif