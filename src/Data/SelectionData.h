#ifndef SELECTION_DATA_H
#define SELECTION_DATA_H

/*!
    * \file SelectionData.h
*/

#include "Data.h"

class SelectionData : public Data
{
    private:
        std::string title_;

    public:
        SelectionData( const nlohmann::json& jsonObject );
        SelectionData( const std::string& folderFromRoot, const std::string& fileName );   
        SelectionData( const std::string& title );

        void readData() override;

        const std::string& title() const { return title_; }
};

#endif