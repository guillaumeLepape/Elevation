#ifndef LEVEL_6_H
#define LEVEL_6_H

/*!
    * \file Level6.h
*/

#include "Level.h"

class Level6 : public Level
{
    public:
        Level6( Player* const player, const Options& options ) :
            Level(player, options)
        {

        }

        void startLevel() override;

        ~Level6() override = default;
};

#endif