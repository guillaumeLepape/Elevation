#ifndef SELECTION_H
#define SELECTION_H

/*!
    * \file Selection.h
*/

#include <vector>

#include "../Action/Action.h"

class Selection
{
    private:
        void printMenu
        (
            const std::string& selectionTitle,
            const std::vector<Action*>& actions
        ) const;

    public:
        Selection();

        void select
        ( 
            const std::string& selectionTitle,
            const std::vector<Action*>& actions
        ) const;
};

#endif