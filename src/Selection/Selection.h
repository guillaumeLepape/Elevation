#ifndef SELECTION_H
#define SELECTION_H

#include <vector>
#include <string>

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