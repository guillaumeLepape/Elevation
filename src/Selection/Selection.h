#ifndef SELECTION_H
#define SELECTION_H

/*!
    * \file Selection.h
*/

#include "Action.h"
#include "SelectionWriter.h"

class Selection
{
    private:
        static int select
        (
            const std::vector<Action*>& actions,
            const SelectionWriter& selectionWriter
        );

    public:
        static int select
        ( 
            const std::vector<Action*>& actions,
            const std::string& folderFromRoot,
            const std::string& nameFile
        );

        static int select
        (
            const std::vector<Action*>& actions,
            const std::string& title
        );
};

#endif