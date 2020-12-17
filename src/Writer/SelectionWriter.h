#ifndef SELECTION_WRITER_H
#define SELECTION_WRITER_H

/*!
    * \file SelectionWriter.h
*/

#include "../Data/SelectionData.h"

#include "../Action/Action.h"

class SelectionWriter
{
    private:
        SelectionData selectionData_;
        std::vector<Action*> actions_;

    public:
        SelectionWriter
        ( 
            const int& levelNumber,
            const int& selectionIndex, 
            const std::vector<Action*>& nameAction 
        );

        void writeSelection();
};

#endif