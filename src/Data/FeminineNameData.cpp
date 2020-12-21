/*!
    * \file FeminineNameData.cpp
*/

#include "FeminineNameData.h"

FeminineNameData::FeminineNameData( const nlohmann::json& jsonObject ) :
    Data( jsonObject )
{
    readData();
}

FeminineNameData::FeminineNameData( const std::string& folderFromRoot, const std::string& nameFile ) :
    Data( folderFromRoot, nameFile )
{
    readData();
}

void FeminineNameData::readData()
{
    for ( auto i = jsonObject_.cbegin(); i != jsonObject_.cend(); i++ )
    {
        std::string name = (std::string) *i;
        feminineName_.insert( name );
    }
}