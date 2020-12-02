#ifndef INTRODUCTION_H
#define INTRODUCTION_H

#include "Level.h"

class Introduction : public Level
{
    public:
        explicit Introduction( Player* player ) : Level(player) {}
        void startLevel() override;
};

#endif