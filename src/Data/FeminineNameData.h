#ifndef NAME_DATA_H
#define NAME_DATA_H

/*!
    * \file FeminineNameData.h
*/

#include "Data.h"

#include <set>

class FeminineNameData : public Data
{
    private:
        std::set<std::string> feminineName_;

    public:
        FeminineNameData( const nlohmann::json& jsonObject );
        FeminineNameData( const std::string& folderFromRoot, const std::string& nameFile );

        void readData() override;

        const std::set<std::string>& feminineName() const { return feminineName_; }
};

#endif