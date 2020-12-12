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
        static void printMenu
        (
            const std::string& selectionTitle,
            const std::vector<Action*>& actions
        );


    public:
        static int select
        ( 
            const std::string& selectionTitle,
            const std::vector<Action*>& actions
        );
};

#endif