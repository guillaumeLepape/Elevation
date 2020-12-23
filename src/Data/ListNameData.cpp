/*!
    * \file ListNameData.cpp
*/

#include "ListNameData.h"

ListNameData::ListNameData( const nlohmann::json& jsonObject ) :
    Data( jsonObject )
{
    readData();
}

ListNameData::ListNameData( const std::string& folderFromRoot, const std::string& nameFile ) :
    Data( folderFromRoot, nameFile )
{
    readData();
}

void ListNameData::readData()
{
    for ( auto i = jsonObject_.cbegin(); i != jsonObject_.cend(); i++ )
    {
        std::string name = (std::string) *i;
        listName_.insert( name );
    }
}