#ifndef SELECTION_WRITER_H
#define SELECTION_WRITER_H

/*!
    * \file SelectionWriter.h
*/

#include "ActionWriter.h"

class SelectionWriter
{
    private:
        std::vector<const ActionWriter*> actionWriter_;
        SelectionData selectionData_;

    public:
        SelectionWriter
        ( 
            const std::vector<const ActionWriter*>& actionWriter,
            const nlohmann::json& jsonObject
        );

        SelectionWriter
        (
            const std::vector<const ActionWriter*>& actionWriter,
            const std::string& title
        );

        SelectionWriter 
        (
            const std::vector<const ActionWriter*>& actionWriter,
            const SelectionData& selectionData
        );

        SelectionWriter
        (
            const std::vector<const ActionWriter*>& actionWriter,
            const std::string& folderFromRoot,
            const std::string& fileName
        );

        void writeSelection() const;
};

#endif