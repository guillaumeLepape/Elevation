#ifndef SELECTION_H
#define SELECTION_H

/*!
    * \file Selection.h
*/

#include "../Action/Action.h"

class Selection
{
    public:
        static int select
        ( 
            const int& levelNumber_, 
            const int& indexSelection, 
            const std::vector<Action*>& actions 
        );
};

#endif