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
        const Options& options_;

        void endOfLevel() const;

    public:
        explicit Level( Player* const player, const Options& options );
        virtual void startLevel() = 0;
        virtual ~Level() = default;
};

#endif