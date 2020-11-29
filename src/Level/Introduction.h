#ifndef INTRODUCTION_H
#define INTRODUCTION_H

#include "Level.h"

class Introduction : public Level
{
    private: 
        void getPseudo() const;

    public:
        Introduction( Player* player ) : Level(player) {}
        void startLevel();
};

#endif