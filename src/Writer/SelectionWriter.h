#ifndef SELECTION_WRITER_H
#define SELECTION_WRITER_H

/*!
    * \file SelectionWriter.h
*/

#include "../Data/SelectionData.h"

class SelectionWriter
{
    private:
        const SelectionData& selectionData_;

    public:
        SelectionWriter( const SelectionData& selectionData );

        void writeSelection();
};

#endif