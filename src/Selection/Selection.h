#ifndef SELECTION_H
#define SELECTION_H

/*!
    * \file Selection.h
*/

#include "Actions.h"

class Selection
{
    private:
        static int select
        (
            const std::vector<Action*>& actions,
            const SelectionWriter& selectionWriter
        );

        static std::vector<const ActionWriter*> 
            vectorOfActionsToVectorOfActionWriter( const std::vector<Action*>& actions );

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