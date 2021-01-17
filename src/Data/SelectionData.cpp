/*!
    * \file SelectionData.cpp
*/

#include "SelectionData.h"

SelectionData::SelectionData( const nlohmann::json& jsonObject ) :
    Data( jsonObject )
{
    readData();
}

SelectionData::SelectionData( const std::string& folderFromRoot, const std::string& fileName ) :
    Data( folderFromRoot, fileName )
{
    readData();
}

SelectionData::SelectionData( const std::string& title ) :
    Data(),
    title_( title )
{

}


void SelectionData::readData() 
{
    title_ = jsonObject_["title"];
}