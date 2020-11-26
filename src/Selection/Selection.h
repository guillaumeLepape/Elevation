#ifndef SELECTION_H
#define SELECTION_H

#include <vector>
#include <string>

#include "../Action/Action.h"

class Selection
{
    private:
        Selection();
    public:
        static void newSelection
        ( 
            const std::string& selectionTitle,
            const std::vector<std::string>& selections, 
            const std::vector<Action*>& actions
        );
};

#endif