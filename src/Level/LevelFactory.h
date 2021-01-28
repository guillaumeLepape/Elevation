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
#include "Level8.h"

static constexpr int NB_LEVEL = 9;

class LevelFactory
{
    public:
        static std::unique_ptr<Level> newLevel
        ( 
            Player* player, 
            const Options& options, 
            const int& levelNumber 
        )
        {
            if ( levelNumber == 0 ) return std::make_unique<Introduction>(player, options);
            if ( levelNumber == 1 ) return std::make_unique<Level1>(player, options);
            if ( levelNumber == 2 ) return std::make_unique<Level2>(player, options);
            if ( levelNumber == 3 ) return std::make_unique<Level3>(player, options);
            if ( levelNumber == 4 ) return std::make_unique<Level4>(player, options);
            if ( levelNumber == 5 ) return std::make_unique<Level5>(player, options);
            if ( levelNumber == 6 ) return std::make_unique<Level6>(player, options);
            if ( levelNumber == 7 ) return std::make_unique<Level7>(player, options);
            if ( levelNumber == 8 ) return std::make_unique<Level8>(player, options);
            assert(false); 
        }
};

#endif