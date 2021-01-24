#ifndef LEVEL_H
#define LEVEL_H

/*!
    * \file Level.h
*/

#include "Options.h"
#include "Player.h"

class Level
{
    protected:
        Player* const player_;

        void endOfLevel() const;

    public:
        explicit Level( Player* const player );
        virtual void startLevel( const Options& options ) = 0;
        virtual ~Level() = default;
};

#endif