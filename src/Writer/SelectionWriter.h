#ifndef SELECTION_WRITER_H
#define SELECTION_WRITER_H

/*!
    * \file SelectionWriter.h
*/

#include "Action.h"
#include <vector>

class SelectionWriter
{
    private:
        std::vector<Action*> actions_;
        std::string title_;

    public:
        SelectionWriter
        (
            const std::vector<Action*>& actions,
            const std::string& title
        );

        void writeSelection() const;
};

#endif