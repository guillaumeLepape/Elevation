#ifndef LEVEL_10_H
#define LEVEL_10_H

/*!
    * \file Level10.h
*/

#include "Level.h"

class Level10 : public Level
{
    public:
        Level10( Player* const player, ResultsData* const resultsData, const Options& options ) :
            Level(player, resultsData, options)
        {

        }

        void startLevel() override;

        ~Level10() override = default;
};

#endif