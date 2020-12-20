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
        std::vector<Action*> actions_;
        SelectionData selectionData_;

    public:
        SelectionWriter
        ( 
            const std::vector<Action*>& actions,
            const nlohmann::json& jsonObject
        );

        SelectionWriter 
        (
            const std::vector<Action*>& actions,
            const SelectionData& selectionData
        );

        SelectionWriter
        (
            const std::vector<Action*>& actions,
            const std::string& folderFromRoot,
            const std::string& fileName
        );

        void writeSelection();
};

#endif